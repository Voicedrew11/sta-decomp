#!/usr/bin/env python3
"""Tidy a unit tools/merge_tu.py wrote: one type and one declaration per name
where the code allows it.

    tools/tidy_tu.py src/game/func_X.c [...]

merge_tu.py keeps every part's view: a type a part spelled its own way is
renamed T_<part>, a name a part declared its own way is reached as
NAME__as_<part>. Many of those differ only through another renamed type, or
not at all once the parts' types are one. This:

  1. unifies per-part types whose definitions read the same once the types
     they name are unified (repeated until nothing changes): the later ones
     become the first, their typedefs go;
  2. drops each part's NAME__as_<part> alias (its #define, declaration and
     #undef), so the part uses the unit's declaration of NAME;

  3. renames a per-part type or static left alone back to its base name;

and keeps a change only if every function of the unit still matches
(tools/match.py diff). Aliases are tried all at once, then by halves where
that fails, so the ones the code needs stay.
"""
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import merge_tu as MT     # noqa: E402

ROOT = MT.ROOT
PART_TYPE = re.compile(r"^(\w+?)_(func_[0-9A-F]{8}|text_\w+)$")


def matches(path, text):
    old = path.read_text()
    path.write_text(text)
    ok, _ = MT.check(path)
    if not ok:
        path.write_text(old)
    return ok


def norm(t):
    return re.sub(r"\s+", " ", t.strip())


def unify_types(text):
    """One pass: (new text, number of types unified)."""
    tds = [(m.group(1), m.group(0)) for m in
           sorted(list(MT.TYPEDEF.finditer(text)) + list(MT.FPTYPEDEF.finditer(text)), key=lambda m: m.start())]
    groups = {}
    for name, decl in tds:
        m = PART_TYPE.match(name)
        base = m.group(1) if m else name
        groups.setdefault(base, []).append((name, decl))
    n = 0
    for base, members in groups.items():
        if len(members) < 2:
            continue
        seen = {}       # body with its own name taken out -> first name
        for name, decl in members:
            body = norm(re.sub(rf"\b{re.escape(name)}\b", "@", decl))
            if body in seen:
                keep = seen[body]
                text = text.replace(decl, "", 1)
                text = re.sub(rf"\b{re.escape(name)}\b", keep, text)
                n += 1
            else:
                seen[body] = name
    return text, n


def plain_names(text):
    """A per-part type or static left alone under its base name: renamed
    back (when nothing else, here or in the headers, has that name)."""
    names = {m.group(1) for m in MT.TYPEDEF.finditer(text)} | {m.group(1) for m in MT.FPTYPEDEF.finditer(text)}
    names |= set(MT.STATIC.findall(text))
    taken = set(re.findall(r"\b\w+\b", text)) | set(MT.header_decls(MT.INCLUDE.findall(text))["types"])
    by_base = {}
    for n in names:
        m = PART_TYPE.match(n)
        if m:
            by_base.setdefault(m.group(1), []).append(n)
    for base, ns in by_base.items():
        if len(ns) == 1 and base not in taken:
            text = re.sub(rf"\b{re.escape(ns[0])}\b", base, text)
    return text


ALIAS_DEF = re.compile(r"^#define (\w+) (\1__as_\w+)\n", re.M)


def aliases(text):
    """[(name, alias)] in text order."""
    return [(m.group(1), m.group(2)) for m in ALIAS_DEF.finditer(text)]


def drop_aliases(text, pairs):
    for name, al in pairs:
        # the #define, the declarations of the alias, and the part's #undef
        m = re.search(rf"^#define {name} {al}\n", text, re.M)
        if not m:
            continue
        start = m.start()
        text = text[:start] + text[m.end():]
        u = re.compile(rf"^#undef {name}\n", re.M).search(text, start)
        end = u.start() if u else len(text)
        span = text[start:end]
        span = re.sub(rf"^[^\n;{{}}]*\b{al}\b[^\n;{{}}]*;[^\n]*\n", "", span, flags=re.M)
        span = re.sub(rf"\b{al}\b", name, span)
        text = text[:start] + span + (text[u.end():] if u else "")
    return text


def tidy(path):
    path = ROOT / path
    text = path.read_text()
    assert MT.check(path)[0], f"{path}: does not match before tidying"
    typed = 0
    while True:
        new, n = unify_types(text)
        if not n or not matches(path, new):
            break
        text, typed = new, typed + n
    new = plain_names(text)
    if new != text and matches(path, new):
        text = new
    pending = [aliases(text)]
    dropped = 0
    while pending:
        batch = pending.pop()
        if not batch:
            continue
        new = drop_aliases(text, batch)
        if matches(path, new):
            text = new
            dropped += len(batch)
        elif len(batch) > 1:
            pending += [batch[len(batch) // 2:], batch[:len(batch) // 2]]
    path.write_text(text)
    left = len(aliases(text))
    print(f"{path.relative_to(ROOT)}: {typed} types unified, {dropped} aliases dropped, {left} kept")


if __name__ == "__main__":
    for p in sys.argv[1:]:
        tidy(p)
