#!/usr/bin/env python3
"""Apply config/game_func_names.txt to the tree.

    tools/apply_names.py [--dry-run]

Every game function symbol (func_ADDR, or an earlier Name_C_ADDR) becomes
<name>_<certainty>_<ADDR>: in the sources (src/, wip/, include/), config/,
docs/, and in file names (a unit named after its function is renamed with
it, and sta.jp.yaml / link_order.jp.txt follow). symbol_addrs.txt gets one
entry per named function so splat writes the names into asm/. Run it again
after changing a name or a certainty, then rerun tools/split.py.
"""
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from names import ROOT, FUNC, load  # noqa: E402

SYMS = ROOT / "config/symbol_addrs.txt"
HEAD = "// game function names (config/game_func_names.txt, tools/apply_names.py)"
TEXT_DIRS = ["src", "wip", "include", "config", "docs"]
SKIP = {ROOT / "config/game_func_names.txt"}
WORD = re.compile(r"\b[A-Za-z_]\w*[0-9A-F]{8}\w*\b")


def tracked() -> list[Path]:
    out = subprocess.run(["git", "ls-files", "--", *TEXT_DIRS], cwd=ROOT,
                         capture_output=True, text=True, check=True).stdout.split("\n")
    others = subprocess.run(["git", "ls-files", "-o", "--exclude-standard", "--", *TEXT_DIRS],
                            cwd=ROOT, capture_output=True, text=True, check=True).stdout.split("\n")
    return [ROOT / p for p in out + others if p and (ROOT / p).is_file()]


def main() -> None:
    dry = "--dry-run" in sys.argv
    names = load()

    def new(addr: int, old: str) -> str:
        n = names.get(addr)
        return f"{n[0]}_{n[1]}_{addr:08X}" if n else old

    # the names a function may have now: func_ADDR, or what the last run
    # wrote into symbol_addrs.txt
    olds = {a: {f"func_{a:08X}"} for a in names}
    prev = SYMS.read_text().split("\n" + HEAD + "\n")
    sources = prev[1:] + [(ROOT / "config/symbol_addrs.carve.txt").read_text()]
    for src in sources:
        for m in re.finditer(r"^([A-Za-z]\w*?_[0-5]_[0-9A-F]{8})\s*=\s*0x([0-9A-F]{8});", src, re.M):
            olds.setdefault(int(m.group(2), 16), set()).add(m.group(1))

    def one(ident: str) -> str:
        # an identifier that is a function's name, or ends in _<name> (the
        # m2c-style types named after their function, Mtx_func_001294A0)
        if not re.search(r"[0-9A-F]{8}$", ident):
            return ident
        a = int(ident[-8:], 16)
        for o in olds.get(a, ()):
            if ident == o or ident.endswith("_" + o):
                return ident[:len(ident) - len(o)] + new(a, o)
        return ident

    def sub(m: re.Match) -> str:
        # NAME__as_PART aliases (tools/merge_tu.py) name two functions
        return "__as_".join(one(x) for x in m.group(0).split("__as_"))

    changed = renamed = 0
    for p in tracked():
        if p in SKIP or p == SYMS:
            continue
        try:
            t = p.read_text()
        except UnicodeDecodeError:
            continue
        u = WORD.sub(sub, t)
        if u != t:
            changed += 1
            if not dry:
                p.write_text(u)
    for p in tracked():
        m = re.fullmatch(r"(\w*[0-9A-F]{8})(\..+)", p.name)
        if m:
            q = p.with_name(WORD.sub(sub, m.group(1)) + m.group(2))
            if q != p:
                renamed += 1
                if not dry:
                    subprocess.run(["git", "mv", "-k", str(p), str(q)], cwd=ROOT, check=True)
                    if p.exists():
                        p.rename(q)
    # symbol_addrs.txt: regenerate our section, rename the rest
    t = SYMS.read_text()
    t = t.split("\n" + HEAD + "\n")[0].rstrip("\n") + "\n"
    t = WORD.sub(sub, t)
    have = set(re.findall(r"^(\w+)\s*=", t, re.M))
    have |= set(re.findall(r"^(\w+)\s*=", (ROOT / "config/symbol_addrs.carve.txt").read_text(), re.M))
    lines = [f"{new(a, '')} = 0x{a:08X}; // type:func" for a in sorted(names)
             if new(a, '') not in have]
    t += "\n" + HEAD + "\n" + "\n".join(lines) + "\n"
    if not dry:
        SYMS.write_text(t)
    print(f"{changed} files rewritten, {renamed} files renamed, {len(lines)} symbol entries")


if __name__ == "__main__":
    main()
