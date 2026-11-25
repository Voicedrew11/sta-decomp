#!/usr/bin/env python3
"""Brute-force the order of a function's statements.

    tools/stmtperm.py OUT.c HEAD TAIL FIXED... -- FREE...

The function's text is HEAD, the statements, then TAIL. FIXED statements keep
their relative order; every FREE statement may go anywhere (all positions and
orders are tried, on all cores). The first order that matches retail
(tools/match.py diff) is written to OUT.c, whose name gives the function.
ee-gcc's scheduling of constant stores is the typical use (docs/LEDGER.md).
"""
import itertools, subprocess, sys, os, concurrent.futures as cf, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
out, head, tail = sys.argv[1], sys.argv[2], sys.argv[3]
rest = sys.argv[4:]
k = rest.index("--")
fixed, free = rest[:k], rest[k + 1:]
n = len(fixed) + len(free)
cands = []
for pos in itertools.combinations(range(n), len(free)):
    for perm in itertools.permutations(free):
        seq, fi, pi = [], iter(fixed), iter(perm)
        for i in range(n):
            seq.append(next(pi) if i in pos else next(fi))
        cands.append(seq)
name = Path(out).stem
def run(seq):
    d = tempfile.mkdtemp()
    p = Path(d) / f"{name}.c"
    p.write_text(head + "".join(f"    {s}\n" for s in seq) + tail)
    r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), "diff", str(p)], capture_output=True, text=True, cwd=ROOT)
    return r.returncode == 0, p.read_text()
with cf.ThreadPoolExecutor(os.cpu_count()) as ex:
    futs = [ex.submit(run, c) for c in cands]
    for f in cf.as_completed(futs):
        ok, text = f.result()
        if ok:
            Path(out).write_text(text); print("MATCH", out)
            for g in futs: g.cancel()
            break
    else:
        print("no match in", len(cands))
