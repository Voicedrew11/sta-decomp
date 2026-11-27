#!/usr/bin/env python3
"""Record how hand-matched C differs from m2c's starting point.

    tools/m2c_diffs.py            write the missing diffs
    tools/m2c_diffs.py --stats    also summarise them

For every game function in src/game/ whose m2c starting point is still in
build/m2c/<func>.c (tools/m2c_batch.py output) and that has no
docs/m2c-diffs/<func>.diff yet, writes the unified diff from the m2c
output to the matching C. Functions m2c matched unchanged get no diff.
These diffs are the material for tools/m2c_rules.py.
"""
import difflib
import re
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "docs/m2c-diffs"


def norm(text):
    return [l.rstrip() for l in text.splitlines() if l.strip()]


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    new = 0
    for src in sorted((ROOT / "src/game").rglob("*.c")):
        base = ROOT / "build/m2c" / f"{src.stem}.c"
        out = OUT / f"{src.stem}.diff"
        if out.exists() or not base.exists():
            continue
        a, b = norm(base.read_text()), norm(src.read_text())
        if a == b:
            continue
        d = difflib.unified_diff(a, b, "m2c", "matched", lineterm="", n=1)
        out.write_text("\n".join(d) + "\n")
        new += 1
    print(f"{new} new diffs in {OUT.relative_to(ROOT)}", file=sys.stderr)
    if "--stats" in sys.argv:
        added, removed = Counter(), Counter()
        for f in OUT.glob("*.diff"):
            for l in f.read_text().splitlines():
                if l.startswith(("+++", "---", "@@")):
                    continue
                tok = re.findall(r"\b(?:u8|s8|u16|s16|u32|s32|u64|s64|f32|s128|u128|void|struct|typedef|"
                                 r"unsigned char|unsigned int|volatile|static|return|if|else|M2C_FIELD|"
                                 r"\.\.\.|NULL|\[\])", l)
                (added if l.startswith("+") else removed).update(tok)
        print("added:  ", added.most_common(20))
        print("removed:", removed.most_common(20))


if __name__ == "__main__":
    main()
