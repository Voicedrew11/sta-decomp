#!/usr/bin/env python3
"""Carry matched C over to near-duplicate functions.

    tools/dupes.py [-j JOBS] [--list] [FUNC ...]

Two functions are near-duplicates when their instructions agree in
everything but symbols and immediates (registers and branch shapes equal).
For every matched game function (src/game/**/func_*.c, or just the FUNCs
named) and every unmatched near-duplicate, the matched C is rewritten with
the duplicate's names (functions, data symbols) and its differing immediates
(as hex or decimal literals), compiled, and kept in src/game/ when it
matches. --list only prints the groups.
"""
import argparse
import concurrent.futures as cf
import os
import re
import subprocess
import sys
import tempfile
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
GAME = 0x00128210
EE = [(0x001D3A90, 0x001D7EC0), (0x001DC328, 0x001DC900), (0x001E1E08, 0x001E5E80)]
INSN = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$")
SYM = re.compile(r"^-?[A-Za-z_][\w.]*$|^%\w+\((\w+)\)")


def functions():
    """name -> (addr, [(mnemonic, operands)]) for every game function in asm/."""
    out = {}
    for f in (ROOT / "asm").rglob("*.s"):
        if "/data/" in str(f):
            continue
        cur = None
        for line in f.read_text().splitlines():
            if line.startswith("glabel "):
                cur = line.split()[1]
                out[cur] = [None, []]
                continue
            if line.startswith(("endlabel", "nonmatching")):
                cur = None if line.startswith("endlabel") else cur
                continue
            m = INSN.match(line)
            if m and cur:
                if out[cur][0] is None:
                    out[cur][0] = int(m.group(1), 16)
                rest = re.sub(r"/\*.*?\*/|#.*$", "", m.group(3)).strip()
                ops = [o.strip() for o in rest.split(",")] if rest else []
                out[cur][1].append((m.group(2), ops, int(m.group(1), 16)))
    return {k: v for k, v in out.items() if v[0] is not None and v[0] >= GAME}


def shape(addr, insns):
    """The skeleton (symbols and immediates abstracted) and the abstracted
    values in order."""
    key, vals = [], []
    for mn, ops, pc in insns:
        if mn == "nop" and pc >= addr + 4 * len(insns):
            continue
        k = [mn]
        for o in ops:
            if o.startswith("$"):
                k.append(o)
            elif o.startswith(".L"):
                k.append("L%x" % (int(o[2:], 16) - addr))
            else:
                mm = re.match(r"^(.*?)(\(\$\w+\))?$", o)
                body, base = mm.group(1), mm.group(2) or ""
                for tok in re.findall(r"[A-Za-z_][\w]*|-?0x[0-9A-Fa-f]+|-?\d+", body):
                    if tok in ("hi", "lo", "gp_rel"):
                        continue
                    vals.append(tok)
                k.append("X" + base)
        key.append(" ".join(k))
    # drop the trailing alignment nops
    while key and key[-1] == "nop":
        key.pop()
    return tuple(key), vals


def as_int(t):
    try:
        return int(t, 0)
    except ValueError:
        return None


def substitute(c, src_name, dst_name, src_vals, dst_vals):
    """Rewrite the C of src_name for dst_name, or None if the values do not
    pair up consistently."""
    names, nums = {src_name: dst_name}, {}
    for a, b in zip(src_vals, dst_vals):
        ia, ib = as_int(a), as_int(b)
        if (ia is None) != (ib is None):
            return None
        if ia is None:
            if names.get(a, b) != b:
                return None
            names[a] = b
        elif ia != ib:
            if nums.get(ia, ib) != ib:
                return None
            nums[ia] = ib
    # placeholders first, so a chain a->b, b->c cannot collide
    ph = {}
    for k, (a, b) in enumerate(names.items()):
        if a != b:
            c = re.sub(r"\b%s\b" % re.escape(a), f"@@N{k}@@", c)
            ph[f"@@N{k}@@"] = b
    for k, (a, b) in enumerate(nums.items()):
        if a < 0 or b < 0:
            continue
        c = re.sub(r"\b0[xX]0*%X\b" % a, f"@@H{k}@@", c, flags=re.I)
        ph[f"@@H{k}@@"] = f"0x{b:X}"
        if a >= 10:
            c = re.sub(r"(?<![\w.])%d(?![\w.])" % a, f"@@D{k}@@", c)
            ph[f"@@D{k}@@"] = str(b)
    for k, v in ph.items():
        c = c.replace(k, v)
    return c


def matched():
    out = {}
    for f in (ROOT / "src/game").rglob("func_*.c"):
        out[f.stem] = f
    return out


def try_one(cand, dst, addr):
    ee = any(lo <= addr < hi for lo, hi in EE)
    with tempfile.TemporaryDirectory() as tmp:
        p = Path(tmp) / f"{dst}.c"
        p.write_text(cand)
        r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), "diff", str(p)],
                           capture_output=True, text=True, cwd=ROOT)
        if r.returncode == 0:
            out = ROOT / "src/game" / ("ee" if ee else "") / f"{dst}.c"
            out.write_text(cand)
            return dst, out
    return dst, None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=os.cpu_count())
    ap.add_argument("--list", action="store_true")
    ap.add_argument("funcs", nargs="*")
    a = ap.parse_args()
    funcs = functions()
    done = matched()
    groups = defaultdict(list)
    shapes = {}
    for name, (addr, insns) in funcs.items():
        key, vals = shape(addr, insns)
        if len(key) < 2:
            continue
        shapes[name] = (key, vals, addr)
        groups[key].append(name)
    jobs, seen = [], set()
    for key, names in groups.items():
        srcs = [n for n in names if n in done and (not a.funcs or n in a.funcs)]
        todo = [n for n in names if n not in done]
        if not srcs or not todo:
            continue
        if a.list:
            print(f"{len(key):4d} insns: {' '.join(sorted(srcs))} -> {' '.join(sorted(todo))}")
            continue
        for dst in todo:
            for src in srcs:
                cand = substitute(done[src].read_text(), src, dst, shapes[src][1], shapes[dst][1])
                if cand is not None and (dst, cand) not in seen:
                    seen.add((dst, cand))
                    jobs.append((cand, dst, shapes[dst][2]))
    if a.list:
        return
    won = set()
    with cf.ThreadPoolExecutor(a.j) as ex:
        for dst, out in ex.map(lambda j: try_one(*j), jobs):
            if out and dst not in won:
                won.add(dst)
                print(f"MATCH {dst} -> {out.relative_to(ROOT)}")
    print(f"{len(won)} near-duplicates matched ({len(jobs)} candidates tried)", file=sys.stderr)


if __name__ == "__main__":
    main()
