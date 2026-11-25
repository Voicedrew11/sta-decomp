#!/usr/bin/env python3
"""How much do tools/m2c_rules.py's rules help?

    tools/m2c_rules_eval.py [-j JOBS]

For every function with an m2c starting point in build/m2c/<func>.raw.c
(written by tools/m2c_batch.py; the function's asm is build/m2c/<func>.s),
compiles the raw output, each rule applied alone, and all rules together,
and compares the differing words against retail (a compile error counts
as the function's full length). Prints per rule: functions it changes,
improves, worsens, the words it saves net, and new matches.
"""
import argparse
import concurrent.futures as cf
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import m2c_rules  # noqa: E402

OUT = ROOT / "build/m2c"


def score(text, name, n_words):
    with tempfile.TemporaryDirectory() as tmp:
        p = Path(tmp) / f"{name}.c"
        p.write_text(text)
        r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), "diff", str(p)], capture_output=True,
                           text=True, cwd=ROOT, env={**os.environ, "GAME_CFLAGS": "-O4,p -relax_pointers"})
    if r.returncode == 0:
        return 0
    m = re.search(r": (\d+) of (\d+) words differ", r.stdout)
    return int(m.group(1)) if m else n_words


def variants(raw, body):
    out = {"all": m2c_rules.apply(raw, body)}
    for r in m2c_rules.RULES:
        try:
            out[r.__name__] = r(raw)
        except Exception:
            out[r.__name__] = raw
    for r in m2c_rules.BODY_RULES:
        try:
            out[r.__name__] = r(raw, body)
        except Exception:
            out[r.__name__] = raw
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=os.cpu_count())
    a = ap.parse_args()
    jobs = []
    for raw_p in sorted(OUT.glob("func_*.raw.c")):
        name = raw_p.name[:-len(".raw.c")]
        body = (OUT / f"{name}.s").read_text()
        n = len(re.findall(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} ", body, re.M))
        raw = raw_p.read_text()
        for rule, text in variants(raw, body).items():
            if text != raw:
                jobs.append((name, rule, text, n, raw))
    names = {j[0] for j in jobs}
    raws = {}
    with cf.ThreadPoolExecutor(a.j) as ex:
        for name, sc in zip(sorted(names), ex.map(
                lambda nm: score((OUT / f"{nm}.raw.c").read_text(), nm,
                                 len(re.findall(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} ",
                                                (OUT / f"{nm}.s").read_text(), re.M))), sorted(names))):
            raws[name] = sc
        res = list(ex.map(lambda j: (j[0], j[1], score(j[2], j[0], j[3])), jobs))
    total = len(list(OUT.glob("func_*.raw.c")))
    print(f"{total} functions with an m2c starting point; rules change {len(names)}")
    print(f"{'rule':20s} {'changed':>8s} {'better':>7s} {'worse':>6s} {'words saved':>12s} {'new MATCH':>10s}")
    for rule in ["all"] + [r.__name__ for r in m2c_rules.RULES + m2c_rules.BODY_RULES]:
        rows = [(nm, sc) for nm, rl, sc in res if rl == rule]
        better = sum(1 for nm, sc in rows if sc < raws[nm])
        worse = sum(1 for nm, sc in rows if sc > raws[nm])
        saved = sum(raws[nm] - sc for nm, sc in rows)
        new = sum(1 for nm, sc in rows if sc == 0 and raws[nm] > 0)
        print(f"{rule:20s} {len(rows):8d} {better:7d} {worse:6d} {saved:12d} {new:10d}")


if __name__ == "__main__":
    main()
