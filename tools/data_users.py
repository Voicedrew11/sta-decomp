#!/usr/bin/env python3
"""Note in each data-only unit which code uses its objects.

    tools/data_users.py

Writes (or rewrites) a `/* used by: ... */` comment under the header comment
of every src/game/data/*.c: the C units and asm files that refer to its
objects (by name or through a field alias), from the built objects. A data
object waits in src/game/data/ until it can move into the code that uses it
(tools/move_data.py); the list says which code that is. Run after a build.
"""
import collections
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import move_data as M     # noqa: E402

ROOT = M.ROOT
NOTE = re.compile(r"^/\* used by: .*?\*/\n", re.M | re.S)


def main():
    alias = M.aliases()
    defs = {}
    for p in sorted((ROOT / "src/game/data").glob("*.c")):
        defs[p] = set(m.group("name") for m in M.DEF.finditer(p.read_text()))
    us = M.users(set().union(*defs.values()), alias)
    for p, names in defs.items():
        who = collections.Counter()
        for n in names:
            for u in us[n]:
                who[Path(u).stem if u.startswith("src/") else Path(u).name] += 1
        text = NOTE.sub("", p.read_text())
        if who:
            items = sorted(who)
            lines, cur = [], "/* used by: "
            for i, w in enumerate(items):
                piece = w + (", " if i < len(items) - 1 else " */")
                if len(cur) + len(piece) > 78:
                    lines.append(cur.rstrip())
                    cur = "   "
                cur += piece
            lines.append(cur)
            note = "\n".join(lines) + "\n"
        else:
            note = "/* used by: no code by name (reached through other data) */\n"
        # after the first comment block
        m = re.search(r"\*/\n", text)
        at = m.end() if m else 0
        p.write_text(text[:at] + note + text[at:])


if __name__ == "__main__":
    main()
