#!/usr/bin/env python3
"""Merge a run of one-function game files into one translation unit.

    tools/merge_tu.py src/game/func_A.c ... src/game/func_B.c   [--keep]

The files (in .text order, as tools/infer_tus.py lists a candidate) become
the first one: their #includes once at the top, then each part in turn.
Names a part defines for itself (typedefs, statics) and that another part
defines differently are renamed for that part with #define NAME
NAME_<func> ... #undef; a typedef or prototype every part spells the same
is kept once. The other files are deleted (git rm).

Then every function of the merged file must still match
(tools/match.py diff); if one does not, or the merge does not compile, the
files are put back and the reason printed, unless --keep.
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TYPEDEF = re.compile(r"^typedef\b(?:[^;{}]|\{[^{}]*(?:\{[^{}]*\}[^{}]*)*\})*?\b(\w+)\s*"
                     r"(?:__attribute__\(\(\w+(?:\([^()]*\))?\)\)\s*)?;[ \t]*\n", re.M)
STATIC = re.compile(r"^static\b[^;{=(]*?\b(\w+)\s*[\[(=;]", re.M)
INCLUDE = re.compile(r'^#include\s+["<][^">]+[">][ \t]*\n', re.M)


def parts(paths):
    out = []
    for p in paths:
        text = (ROOT / p).read_text()
        incs = INCLUDE.findall(text)
        body = INCLUDE.sub("", text).strip("\n") + "\n"
        tds = {m.group(1): m.group(0) for m in TYPEDEF.finditer(body)}
        sts = set(STATIC.findall(body))
        out.append((p, incs, body, tds, sts))
    return out


# top-level only: a declaration starts at column 0 with a type word
PROTO = re.compile(r"^(?!typedef\b|static\b|return\b|else\b|if\b)(?:extern[ \t]+)?([A-Za-z_][\w \t\*]*?)[ \t\*]*\b(\w+)[ \t]*\(([^;{}()]*)\)[ \t]*;[ \t]*\n", re.M)
DEFN = re.compile(r"^(?!static\b)([A-Za-z_][\w \t\*]*?)[ \t\*]*\b(func_[0-9A-F]{8})[ \t]*\(([^;{}()]*)\)\s*\{", re.M)


ALIAS_T = {"float": "f32", "double": "f64", "int": "s32", "unsigned int": "u32", "char": "s8"}


def norm(t):
    t = re.sub(r"\s+", " ", t.strip()).replace(" *", "*").replace("* ", "*")
    return ALIAS_T.get(t, t)


def param_list(params):
    """Parameter types, names dropped."""
    out = []
    for x in params.split(",") if params.strip() and params.strip() != "void" else []:
        x = norm(x)
        m = re.fullmatch(r"(.*?[\w\*])\s*\b([a-z_]\w*)", x)
        if m and m.group(2) not in ALIAS_T and not re.fullmatch(r"[su](8|16|32|64)|f(32|64)|void|const|volatile|unsigned|signed", m.group(2)) \
                and " " in x.replace("*", "* ").strip():
            x = norm(m.group(1))
        out.append(ALIAS_T.get(x, x))
    return out


def unify(sigs):
    """One prototype for several (ret, params) spellings, or None: the same
    but for what pointer parameters point at (those become void *)."""
    rets = {norm(r) for r, _ in sigs}
    lists = [param_list(p) for _, p in sigs]
    if len(rets) == 2 and "void" in rets:
        rets.discard("void")        # a part that ignores the result declared it void
    if len(rets) != 1 and all(r in ("s32", "u32") for r in rets):
        rets = {"s32"}
    if len(rets) != 1 or len({len(l) for l in lists}) != 1:
        return None
    out = []
    for col in zip(*lists):
        if len(set(col)) == 1:
            out.append(col[0])
        elif all(c.endswith("*") for c in col):
            out.append("void *")
        elif set(col) <= {"s32", "u32", "int", "unsigned int"} or set(col) <= {"s16", "u16"} \
                or set(col) <= {"s8", "u8", "char"}:
            out.append(col[0])      # the same register either way
        else:
            return None
    return rets.pop(), out


HEADER_TYPES = None


def visible_types():
    """Type names the headers give (and the basic ones)."""
    global HEADER_TYPES
    if HEADER_TYPES is None:
        text = "".join(p.read_text() for p in list((ROOT / "include").glob("*.h")) + list((ROOT / "src/game").glob("*.h")))
        HEADER_TYPES = set(re.findall(r"\}\s*(\w+)\s*(?:__attribute__\(\([^;]*\)\))?\s*;", text)) \
            | set(re.findall(r"typedef\s+[\w\s\*]+?\b(\w+)\s*;", text)) \
            | {"void", "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64", "char", "int",
               "short", "long", "float", "double", "unsigned", "signed", "const", "volatile", "struct"}
    return HEADER_TYPES


def from_definition(name):
    """The signature of a C function defined in its own file, with any type
    local to that file written as void * (pointers) -- or None."""
    p = ROOT / "src/game" / f"{name}.c"
    if not p.exists():
        return None
    m = re.search(rf"^(?!static\b)([A-Za-z_][\w \t\*]*?)[ \t\*]*\b{name}[ \t]*\(([^;{{}}()]*)\)\s*\{{",
                  p.read_text(), re.M)
    if not m:
        return None
    # the return type: a pointer star may sit with the name
    whole = m.group(0)
    ret = norm(whole[:whole.index(name)])
    ok = visible_types()

    def fix(t):
        words = set(re.findall(r"[A-Za-z_]\w*", t))
        if words <= ok:
            return t
        return "void *" if t.endswith("*") else None
    r = fix(ret)
    ps = [fix(x) for x in param_list(m.group(2))]
    if r is None or None in ps:
        return None
    return r, ps


def prototypes(paths_bodies, local=frozenset()):
    """Reconcile function declarations across the parts: a function defined
    in the merged file is declared with its definition's signature; one
    declared differently by several parts gets a unified prototype. Returns
    (bodies, problems)."""
    defs = {}
    for body in paths_bodies:
        for m in DEFN.finditer(body):
            # the return type with its stars (they may sit by the name)
            whole = m.group(0)
            defs[m.group(2)] = (whole[:whole.index(m.group(2))], m.group(3))
    decls = {}
    for body in paths_bodies:
        for m in PROTO.finditer(body):
            decls.setdefault(m.group(2), set()).add((norm(m.group(1)), ", ".join(param_list(m.group(3)))))
    want, problems = {}, []
    for name, sigs in decls.items():
        if name in defs:
            r, p = defs[name]
            words = set(re.findall(r"[A-Za-z_]\w*", p))
            if words & local and not set(re.findall(r"[A-Za-z_]\w*", r)) & local:
                want[name] = f"{norm(r)} {name}();\n"     # its types come later
            else:
                want[name] = f"{norm(r)} {name}({p.strip()});\n"
        elif len(sigs) > 1:
            u = unify(sigs)
            if u is None:
                u = from_definition(name)
            if u is None:
                problems.append(f"{name}: declared as " + " / ".join(f"{r} ({p})" for r, p in sorted(sigs)))
            else:
                want[name] = f"{u[0]} {name}({', '.join(u[1])});\n"
    out = []
    for body in paths_bodies:
        body = PROTO.sub(lambda m: want.get(m.group(2), m.group(0)), body)
        out.append(body)
    return out, problems


def merge(paths):
    ps = parts(paths)
    local_all = set()
    for _, _, _, tds, _ in ps:
        local_all |= set(tds)
    bodies, problems = prototypes([b for _, _, b, _, _ in ps], frozenset(local_all))
    if problems:
        raise SystemExit("prototypes differ:\n  " + "\n  ".join(problems))
    ps = [(p, i, b, t, s) for (p, i, _, t, s), b in zip(ps, bodies)]
    # a function a part calls before the part that defines it: declared
    # after the includes, when its signature names only types visible there
    defined = []
    for _, _, b, _, _ in ps:
        for m in DEFN.finditer(b):
            whole = m.group(0)
            defined.append((m.group(2), norm(whole[:whole.index(m.group(2))]), m.group(3).strip()))
    local = set()
    for _, _, _, tds, _ in ps:
        local |= set(tds)
    forward = []
    for name, ret, params in defined:
        words = set(re.findall(r"[A-Za-z_]\w*", ret + " " + params))
        if not words & local:
            forward.append(f"{ret} {name}({params or 'void'});\n")
            continue
        # its parameters name a part's own type: an unprototyped declaration
        # (compatible with the definition while its parameters are pointers
        # or ints and its return type is visible here)
        rwords = set(re.findall(r"[A-Za-z_]\w*", ret))
        plist = param_list(params)
        if not rwords & local and all(t.endswith("*") or t in ("s32", "u32") for t in plist):
            forward.append(f"{ret} {name}();\n")
    includes = []
    for _, incs, *_ in ps:
        for i in incs:
            if i not in includes:
                includes.append(i)
    # a typedef spelled the same everywhere it appears is kept once (first
    # use); one spelled differently in two parts is renamed in each
    spellings = {}
    for _, _, _, tds, _ in ps:
        for n, t in tds.items():
            spellings.setdefault(n, set()).add(t.strip())
    seen_td, out = set(), []
    for p, _, body, tds, sts in ps:
        tag = Path(p).stem
        rename = [n for n in tds if len(spellings[n]) > 1]
        rename += [n for n in sts if sum(n in o[4] for o in ps) > 1]
        # typedefs already given by an earlier part (same spelling): drop
        for n, t in tds.items():
            if n not in rename and n in seen_td:
                body = body.replace(t, "", 1)
            seen_td.add(n)
        head = "".join(f"#define {n} {n}_{tag}\n" for n in rename)
        tail = "".join(f"#undef {n}\n" for n in rename)
        out.append(f"/* {tag} */\n" + head + body.strip("\n") + "\n" + tail)
    return "".join(includes) + "".join(forward) + "\n" + "\n".join(out)


def check(path):
    r = subprocess.run([str(ROOT / ".venv/bin/python"), "tools/match.py", "diff", str(path)],
                       capture_output=True, text=True, cwd=ROOT)
    text = r.stdout + r.stderr
    bad = [l for l in text.splitlines() if re.search(r"differ|rror|failed", l)]
    return (not bad and "MATCH" in text), text


def main():
    paths = [a for a in sys.argv[1:] if a.startswith("src/")]
    keep = "--keep" in sys.argv
    saved = {p: (ROOT / p).read_text() for p in paths}
    try:
        merged = merge(paths)
    except SystemExit as e:
        print(f"{paths[0]}..{Path(paths[-1]).name}: not merged ({e})")
        return 1
    first = ROOT / paths[0]
    first.write_text(merged)
    for p in paths[1:]:
        (ROOT / p).unlink()
    ok, text = check(first)
    if ok or keep:
        for p in paths[1:]:
            subprocess.run(["git", "rm", "-q", "--cached", p], cwd=ROOT)
        print(f"{paths[0]}: merged {len(paths)} files" + ("" if ok else " (kept, does not match)"))
        if not ok:
            print(text)
        return 0
    for p, t in saved.items():
        (ROOT / p).write_text(t)
    print(f"{paths[0]}..{Path(paths[-1]).name}: not merged\n" +
          "\n".join(l for l in text.splitlines() if re.search(r"differ|rror|Error|failed|#", l))[:2000])
    return 1


if __name__ == "__main__":
    sys.exit(main())
