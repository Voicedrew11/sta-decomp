#!/usr/bin/env python3
"""For the functions a commit matched, how far were m2c and m2c + rules?

    tools/hand/rules_table.py [COMMIT]      (default HEAD)
    tools/hand/rules_table.py --staged      the files staged for the next commit

For each src/game function the commit added, compiles build/m2c/<f>.raw.c
(m2c as cleaned by m2c_batch.py) and build/m2c/<f>.c (the best variant
m2c_batch.py kept, rules included) against retail and prints the differing
words of each next to the function size. "-" means no starting point; "cc"
means it did not compile.
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
M2C = ROOT / "build/m2c"


def score(path):
    if not path.exists():
        return "-"
    r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), "diff", str(path)], capture_output=True,
                       text=True, cwd=ROOT, env={"GAME_CFLAGS": "-O4,p -relax_pointers", "PATH": "/usr/bin:/bin"})
    if r.returncode == 0:
        return "0"
    m = re.search(r": (\d+) of (\d+) words differ", r.stdout)
    return m.group(1) if m else "cc"


def main():
    commit = sys.argv[1] if len(sys.argv) > 1 else "HEAD"
    if commit == "--staged":
        span = ["--cached"]
    else:
        span = [f"{commit}~1", commit]
    files = subprocess.run(["git", "diff", "--name-only", "--diff-filter=A", *span, "--", "src/game"],
                           capture_output=True, text=True, cwd=ROOT).stdout.split()
    if not files:
        return
    names = sorted(Path(f).stem for f in files if re.search(r"func_[0-9A-F]{8}\.c$", f))
    sizes = {}
    tsv = M2C / "results.tsv"
    if tsv.exists():
        for line in tsv.read_text().splitlines():
            a, size, name, *_ = line.split("\t")
            sizes[name] = int(size, 16)
    print(f"| function | size | m2c | m2c + rules | final |")
    print(f"|---|---|---|---|---|")
    for n in names:
        raw = score(M2C / f"{n}.raw.c")
        best = score(M2C / f"{n}.c")
        size = sizes.get(n)
        words = f"{size // 4} words" if size else "?"
        print(f"| {n} | {words} | {raw} | {best} | 0 |")


if __name__ == "__main__":
    main()
