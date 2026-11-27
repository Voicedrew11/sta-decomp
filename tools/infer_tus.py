#!/usr/bin/env python3
"""Infer the game's translation units from the order of their data.

    tools/infer_tus.py [--limit 0x4000] [--all]

mwldps2 laid out each section unit by unit in link order, so every unit's
data is one stretch, and the stretches come in .text order. Today's game
sources are one function per file. When an object used only by function A
sits before an object used only by an earlier function B (a backward step),
A and B cannot be separate units: they are one translation unit, which then
holds every function between them in .text. Overlapping ranges join.

Only objects with one user count (a shared global ties nothing), only
.data, .bss and small data (.rodata follows the .text order), and only steps
within --limit bytes of code (a longer one is link noise: commons, a
library's data; taking them all chains the game into one unit).

Each candidate is printed with its function files, the steps that tie it,
and whether it can be merged now: every file CodeWarrior C or an asm chunk
(merged as INCLUDE_ASM, include/include_asm.h), none ee-gcc (src/game/ee/).
A blocked candidate is split at its ee-gcc functions into runs, each listed
as a candidate of its own. An INCLUDE_ASM'd chunk counts as its unit's.
--all prints the blocked ones too.
"""
import bisect
import collections
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import move_data as M     # noqa: E402

ROOT = M.ROOT
SECTIONS = {".data": (0x001EDE80, 0x001F8880), ".sdata": (0x00201B80, 0x00201E80),
            ".sbss": (0x00201E80, 0x00202480), ".bss": (0x00202480, 0x004BE180)}
GAME_TEXT = 0x00128210


def taddr(path):
    m = re.search(r"(?:func|text)_([0-9A-F]{8})", path)
    return int(m.group(1), 16) if m else None


def included():
    """asm chunk -> the C unit that INCLUDE_ASMs it (include/include_asm.h):
    the chunk is part of that unit."""
    import gen_ninja
    order = [l.strip() for l in (ROOT / "config/link_order.jp.txt").read_text().splitlines() if l.strip()]
    return {c: u for u, cs in gen_ninja.include_asm_units(order).items() for c in cs}


INCLUDED = None


def unit_of(path):
    global INCLUDED
    if INCLUDED is None:
        INCLUDED = included()
    return INCLUDED.get(path, path)


def text_units():
    """[(address, unit path)] of the game's .text units in link order (an
    INCLUDE_ASM'd chunk is its unit's)."""
    out = []
    for line in (ROOT / "config/link_order.jp.txt").read_text().splitlines():
        line = line.strip()
        if line.startswith(("src/game/", "asm/text")) and not line.startswith("src/game/data/") \
                and unit_of(line) == line:
            a = taddr(line)
            if a is None and line.startswith("asm/") and out:
                a = out[-1][0] + 1      # an asm chunk named by no address: right after
            if a is not None and a >= GAME_TEXT:
                out.append((a, line))
    return sorted(out)


def candidates(limit):
    sz = M.sizes()
    alias = M.aliases()
    names = [n for n, (a, s) in sz.items() if n.startswith(("D_", "jtbl_"))
             and any(lo <= a < hi for lo, hi in SECTIONS.values())]
    us = M.users(set(names), alias)
    units = text_units()
    starts = [a for a, _ in units]
    steps = []      # (lo, hi, section, object before, object after)
    for sec, (lo, hi) in SECTIONS.items():
        seq = []
        for a, n in sorted((sz[n][0], n) for n in names if lo <= sz[n][0] < hi):
            if len(us[n]) == 1:
                t = taddr(unit_of(next(iter(us[n]))))
                if t is not None and t >= GAME_TEXT:
                    seq.append((t, n))
        for (x, nx), (y, ny) in zip(seq, seq[1:]):
            if y < x and x - y <= limit:
                steps.append((y, x, sec, nx, ny))
    steps.sort()
    merged = []
    for lo, hi, *ev in steps:
        if merged and lo <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], hi)
            merged[-1][2].append(ev)
        else:
            merged.append([lo, hi, [ev]])
    out = []
    for lo, hi, ev in merged:
        i, j = bisect.bisect_left(starts, lo), bisect.bisect_right(starts, hi)
        files = [u for _, u in units[i:j]]
        out.append((files, ev))
    return out


def blocked(f):
    """An ee-gcc function cannot share a CodeWarrior unit; an asm chunk can
    (INCLUDE_ASM, include/include_asm.h)."""
    return f.startswith("src/game/ee/") or not f.endswith((".c", ".s"))


def main():
    limit = int(sys.argv[sys.argv.index("--limit") + 1], 0) if "--limit" in sys.argv else 0x4000
    show_all = "--all" in sys.argv
    ready, waiting = [], []
    for files, ev in candidates(limit):
        if not any(blocked(f) for f in files):
            ready.append((files, ev, None))
            continue
        waiting.append((files, ev))
        run = []
        for f in files + [None]:
            if f is None or blocked(f):
                if len(run) > 1:
                    ready.append((run, ev, files))
                run = []
            else:
                run.append(f)
    ready.sort(key=lambda r: len(r[0]))
    if "--files" in sys.argv:
        for files, ev, parent in ready:
            print(" ".join(files))
        return
    for files, ev, parent in ready:
        tag = f"  (C run of a unit with {sum(blocked(f) for f in parent)} asm/ee function(s))" if parent else ""
        print(f"{Path(files[0]).stem}..{Path(files[-1]).stem}: {len(files)} files{tag}")
        for sec, a, b in ev[:4]:
            print(f"    {sec}: {a} before {b}")
    print(f"{len(ready)} mergeable candidates, {sum(len(r[0]) for r in ready)} files;"
          f" {len(waiting)} units wait on asm/ee functions", file=sys.stderr)
    if show_all:
        for files, ev in waiting:
            bl = [Path(f).name for f in files if blocked(f)]
            print(f"WAIT {Path(files[0]).stem}..{Path(files[-1]).stem}: {len(files)} files, on {', '.join(bl)}")


if __name__ == "__main__":
    main()
