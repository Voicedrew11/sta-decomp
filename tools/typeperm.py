#!/usr/bin/env python3
"""Try every assignment of types to the slots of a C template.

    tools/typeperm.py TEMPLATE.c [-t TYPES] [-o OUT.c] [-j JOBS] [--max N]

TEMPLATE.c holds slots @T0@, @T1@, ...; each slot ranges over TYPES (a
comma list, default below), or over its own list written @T0:s32|u8@ at its
first use. Every combination (at most --max) is compiled with
tools/match.py diff on all cores; the first match is written to OUT.c (the
template's func_XXXXXXXX.c next to it by default) and printed. The fewest
differing words seen is reported when nothing matches.
"""
import argparse
import concurrent.futures as cf
import itertools
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TYPES = "s32,u32,s16,u16,s8,u8,s64,u64,f32,void *"
SLOT = re.compile(r"@T(\d+)(?::([^@]*))?@")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("template")
    ap.add_argument("-t", default=TYPES)
    ap.add_argument("-o")
    ap.add_argument("-j", type=int, default=os.cpu_count())
    ap.add_argument("--max", type=int, default=20000)
    a = ap.parse_args()
    text = Path(a.template).read_text()
    default = [t.strip() for t in a.t.split(",")]
    choices = {}
    for m in SLOT.finditer(text):
        k = int(m.group(1))
        if m.group(2):
            choices[k] = m.group(2).split("|")
        choices.setdefault(k, default)
    base = SLOT.sub(lambda m: f"@T{m.group(1)}@", text)
    keys = sorted(choices)
    combos = list(itertools.islice(itertools.product(*(choices[k] for k in keys)), a.max))
    func = re.search(r"\b((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})\s*\([^;]*\)\s*\{", base)
    out = Path(a.o) if a.o else Path(a.template).with_name(f"{func.group(1)}.c")
    tmp = tempfile.mkdtemp(prefix="typeperm")

    def run(i, combo):
        c = base
        for k, t in zip(keys, combo):
            c = c.replace(f"@T{k}@", t)
        p = Path(tmp) / f"v{i}" / f"{func.group(1)}.c"
        p.parent.mkdir()
        p.write_text(c)
        r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), "diff", str(p)],
                           capture_output=True, text=True, cwd=ROOT)
        if r.returncode == 0:
            return 0, c, combo
        m = re.search(r"(\d+) of \d+ words differ", r.stdout)
        return (int(m.group(1)) if m else 10 ** 6), c, combo

    best = (10 ** 6, None, None)
    with cf.ThreadPoolExecutor(a.j) as ex:
        futs = [ex.submit(run, i, c) for i, c in enumerate(combos)]
        for f in cf.as_completed(futs):
            r = f.result()
            if r[0] < best[0]:
                best = r
            if r[0] == 0:
                for g in futs:
                    g.cancel()
                break
    if best[0] == 0:
        out.write_text(best[1])
        print(f"MATCH {dict(zip(keys, best[2]))} -> {out}")
    else:
        print(f"no match in {len(combos)} combinations; best {best[0]} words differ with "
              f"{dict(zip(keys, best[2])) if best[2] else None}")
        sys.exit(1)


if __name__ == "__main__":
    main()
