#!/usr/bin/env python3
"""Define a merged unit's .bss in the unit, a data-only unit inside it included.

    tools/absorb_bss.py UNIT.c DATA.c ...      (tools/merge_tu.py calls absorb())

A translation unit's .bss is one stretch; a data-only unit
(src/game/data/bss_*.c) that lies inside that stretch is the unit's own. Its
objects, and the ones the parts define, become one block at the top of the
unit, from the highest address down (CodeWarrior writes uninitialised
objects in reverse order, so the original source defined them at the top).

An object of 8 bytes or less would go to .sbss in a game unit; in retail it
is in .bss, so it was part of a larger object. Each run of such objects is
defined as one, named by its first object, in the type the code declares
that name with (an array of it), and the names inside it become fields for
ld (config/data_aliases.txt); a run of 8 bytes or less is refused. Other
objects take the type the unit declares them with, else the data unit's.
config/symbol_addrs.carve.txt gets the grouped sizes, so splat's target
object has the same objects.

absorb() takes the merged text (for the declared types) and returns the
block, the parts' definition lines it replaces and the groups, or raises
SystemExit with the reason. tools/merge_tu.py merge() puts the block first
(each name's first declaration: a part that declares one otherwise keeps
its view through an alias), checks the match and updates the link order and
sta.jp.yaml (the data unit's .bss subsegment takes the unit's name).
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import move_data as M     # noqa: E402

ROOT = M.ROOT
BSS = (0x00202480, 0x004BE180)
CARVE = ROOT / "config/symbol_addrs.carve.txt"


def bss_defs(text):
    """name -> definition line of the uninitialised D_ objects a text defines
    at its top level."""
    out = {}
    for m in M.DEF.finditer(text):
        line = m.group(0)
        decl = re.sub(r"__attribute__\(\((?:[^()]|\([^()]*\))*\)\)", "", m.group("decl"))
        if re.match(r"\s|extern\b|typedef\b|#", line) or "=" in decl or "(" in decl:
            continue
        out[m.group("name")] = line
    return out


def declared(text, name):
    """(type, ptr, has_dim) of the extern the text declares `name` with."""
    for m in M.EXTERN.finditer(text):
        if m.group("name") == name:
            return m.group("type"), m.group("ptr"), m.group("dim") is not None
    return None


def definition(text, name, size, fallback):
    """A definition of `name` (`size` bytes) in its declared type."""
    d = declared(text, name)
    if d is None:
        if fallback is None:
            raise SystemExit(f"{name}: no declaration to take a type from")
        line = re.sub(r"\s*__attribute__\(\(aligned\(\d+\)\)\)", "", fallback.split(";")[0])
        m = re.fullmatch(r"\s*((?:\w+\s+)*?\w+)\s*(\**)\s*" + name + r"\s*(\[[^\]]*\])?\s*", line)
        if not m:
            raise SystemExit(f"{name}: cannot read {line!r}")
        d = (m.group(1), m.group(2), m.group(3) is not None)
    t, ptr, dim = d
    es = M.type_size(t.split()[-1], ptr, text)
    if dim or es is not None:
        if es is None or size % es:
            raise SystemExit(f"{name}: {size:#x} bytes are no whole number of {t}{ptr}")
        return f"{t} {ptr}{name}[{size // es:#x}];"
    return f"{t} {ptr}{name};"      # a struct the size says nothing against: the ROM check does


def absorb(text, data_units):
    sz = M.sizes()
    own = bss_defs(text)
    objs = {}       # name -> (addr, size, fallback line or None, from a part)
    for n, line in own.items():
        if n in sz and BSS[0] <= sz[n][0] < BSS[1]:
            objs[n] = (*sz[n], line, True)
    for du in data_units:
        for n, line in bss_defs((ROOT / du).read_text()).items():
            objs[n] = (*sz[n], line, False)
    order = sorted(objs, key=lambda n: objs[n][0])
    # runs of small objects -> one object each
    groups, i = [], 0       # (base name, addr, size, inner names)
    while i < len(order):
        n = order[i]
        a, s = objs[n][:2]
        if s > 8:
            groups.append((n, a, s, []))
            i += 1
            continue
        j = i
        while j + 1 < len(order) and objs[order[j + 1]][1] <= 8:
            j += 1
        end = objs[order[j]][0] + objs[order[j]][1]
        run = order[i:j + 1]
        if end - a > 8:
            groups.append((n, a, end - a, run[1:]))
        elif groups and groups[-1][1] + groups[-1][2] == a:
            # too small for an object of its own: the trailing fields of the
            # object before it (a struct's), as the repeated records show
            b, ba, bs, binner = groups[-1]
            groups[-1] = (b, ba, end - ba, binner + run)
        elif j + 1 < len(order) and objs[order[j + 1]][0] == end:
            nx = order[j + 1]
            groups.append((n, a, objs[nx][0] + objs[nx][1] - a, run[1:] + [nx]))
            j += 1
        else:
            raise SystemExit(f"{n}: a run of {end - a:#x} bytes of small objects, no neighbour to join")
        i = j + 1
    # check: one stretch, nothing foreign in it
    for (n1, a1, s1, _), (n2, a2, _, _) in zip(groups, groups[1:]):
        if a2 - (a1 + s1) >= 16:
            raise SystemExit(f"a gap of {a2 - a1 - s1:#x} bytes after {n1}: not one stretch")
    start = groups[0][1]
    defs = []
    wants = [min(M.natural(s), a & -a, start & -start) for _, a, s, _ in groups]
    wants[0] = max(wants)
    for (n, a, s, inner), want in zip(groups, wants):
        if objs[n][3] and s == objs[n][1]:
            line = objs[n][2]
        else:
            try:
                line = definition(text, n, s, objs[n][2])
            except SystemExit:
                line = f"u8 {n}[{s:#x}];"      # no type fits: bytes (a part's other view is aliased)
        line = re.sub(r"\s*__attribute__\(\(aligned\(\d+\)\)\)", "", line)
        if want != M.natural(s):
            line = line.replace(";", f" __attribute__((aligned({want})));", 1)
        if inner:
            line += f"      /* also {', '.join(inner)} */"
        defs.append(line)
    block = (f"/* .bss from 0x{start:08X}, defined from the top down (CodeWarrior writes\n"
             "   uninitialised objects in reverse order) */\n" + "\n".join(reversed(defs)) + "\n\n")
    # the parts' own definitions leave their bodies (tools/merge_tu.py merge())
    removed = [line for n, line in own.items() if n in objs]
    return block, removed, groups


def record(groups):
    """The grouped objects' fields for ld, and their sizes for splat."""
    fields = {}
    for n, a, s, inner in groups:
        for x in inner:
            fields[x] = (n, M.sizes()[x][0] - a)
        if inner:
            fields[n] = (n, None, s)
    if not fields:
        return
    ali = M.ALIASES.read_text()
    add = "".join(f"{x} = {b} + 0x{off:X};\n" for x, v in fields.items() if v[1] is not None
                  for b, off in [v[:2]])
    M.ALIASES.write_text(ali.rstrip("\n") + "\n/* ? */\n" + add)
    lines = []
    for line in CARVE.read_text().split("\n"):
        m = re.match(r"(\w+) = ", line)
        if m and m.group(1) in fields:
            v = fields[m.group(1)]
            if v[1] is not None:
                continue
            line = re.sub(r"size:0x[0-9A-F]+", f"size:0x{v[2]:X}", line)
        lines.append(line)
    CARVE.write_text("\n".join(lines))
    M.regroup_aliases(M.sizes())


if __name__ == "__main__":
    b, _, _ = absorb((ROOT / sys.argv[1]).read_text(), sys.argv[2:])
    print(b)
