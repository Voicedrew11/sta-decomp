#!/usr/bin/env python3
"""Move units from their own partial view of a global struct to one type.

    tools/struct_views.py show GLOBAL            each unit's fields by offset
    tools/struct_views.py migrate GLOBAL TYPE    switch units to TYPE

TYPE must be defined in an include/ header. A unit's view is the struct its
`extern ... GLOBAL;` declares (inline or through a local typedef). migrate
rewrites the declaration to `extern TYPE GLOBAL;` (`TYPE *` for a pointer
view), adds the header's #include, and renames member accesses made through
GLOBAL (GLOBAL.f, GLOBAL->f, and `#define X GLOBAL` / `#define X (&GLOBAL)`
aliases) to TYPE's member at the same offset. A view's `a[i][j]` on an array
TYPE declares flat becomes `a[(i) * N + (j)]`. A unit is kept only if its
object stays the same (run ninja first; an undefined symbol's recorded size
may change); otherwise it keeps its view.
"""
import re
import shutil
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import headers as H     # noqa: E402
import merge_tu as MT   # noqa: E402

ROOT = H.ROOT
SIZE = {"char": 1, "s8": 1, "u8": 1, "signed char": 1, "unsigned char": 1, "Flags8": 1, "Bits8": 1,
        "s16": 2, "u16": 2, "short": 2, "unsigned short": 2,
        "s32": 4, "u32": 4, "int": 4, "unsigned int": 4, "f32": 4, "float": 4, "unsigned": 4,
        "s64": 8, "u64": 8, "f64": 8, "double": 8, "Vec": 16, "Mtx": 64}
ALIGN = {"Vec": 16, "Mtx": 16}


SIZE.update({"s128": 16, "u128": 16})


class Unsized(Exception):
    pass


def dim(x):
    """An array bound: a number or plain arithmetic on numbers."""
    x = x.strip()
    if not re.fullmatch(r"[0-9A-Fa-fxX\s+\-*/()]+", x):
        raise Unsized(x)
    return int(eval(re.sub(r"0[xX][0-9A-Fa-f]+|\d+", lambda m: str(int(m.group(0), 0)), x).replace("/", "//")))


def split_top(body):
    """Member declarations of a struct body, nested braces kept whole."""
    out, depth, cur = [], 0, ""
    for ch in body:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
        if ch == ";" and depth == 0:
            if cur.strip():
                out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def layout(body, union=False):
    try:
        return _layout(body, union)
    except Unsized:
        return None


def _layout(body, union=False):
    """([(offset, name, base type, dims, is pointer)], size, align) of a
    struct (or union) body, or None when a member cannot be sized."""
    out, off, size_max, al_max, bits = [], 0, 0, 1, None
    for decl in split_top(body):
        agg = re.match(r"(struct|union)\s*\{(.*)\}\s*(\w+)\s*((?:\[[^\]]*\])*)$", decl, re.S)
        bf = re.match(r"((?:unsigned |signed )?\w+)\s*(\w*)\s*:\s*(\d+)$", decl)
        if agg:
            inner = _layout(agg.group(2), agg.group(1) == "union")
            if not inner:
                return None
            size, align, base, name, dims, ptr = inner[1], inner[2], agg.group(1), agg.group(3), [], False
            dims = [dim(x) for x in re.findall(r"\[([^\]]*)\]", agg.group(4))]
        elif bf:
            # a run of bitfields packs into units of its base type
            unit = SIZE.get(bf.group(1))
            if not unit:
                return None
            w = int(bf.group(3))
            if bits is None or bits[1] + w > unit * 8 or bits[0] != unit:
                off = (off + unit - 1) // unit * unit
                bits = [unit, 0, off]
                off += unit
                al_max = max(al_max, min(unit, 8))
            if bf.group(2):
                out.append((bits[2], bf.group(2), bf.group(1), [], False))
            bits[1] += w
            size_max = max(size_max, off)
            continue
        else:
            bits = None
            if "(" in decl or "{" in decl:
                return None
            m = re.match(r"((?:unsigned |signed |volatile )?\w+)\s+(.*)$", decl)
            if not m:
                return None
            items = [x.strip() for x in m.group(2).split(",")]
            res = []
            for item in items:
                nm = re.match(r"(\**)\s*(\w+)\s*((?:\[[^\]]*\])*)$", item)
                if not nm:
                    return None
                res.append((nm.group(2), [dim(x) for x in re.findall(r"\[([^\]]*)\]", nm.group(3))],
                            bool(nm.group(1))))
            base = m.group(1).replace("volatile ", "")
            for name, dims, ptr in res:
                if ptr:
                    size = align = 4
                elif base in SIZE:
                    size = SIZE[base]
                    align = ALIGN.get(base, min(size, 16))
                else:
                    return None
                off = 0 if union else (off + align - 1) // align * align
                n = 1
                for d in dims:
                    n *= d
                out.append((off, name, base, dims, ptr))
                off += size * n
                size_max, al_max = max(size_max, off), max(al_max, align)
            continue
        bits = None
        off = 0 if union else (off + align - 1) // align * align
        n = 1
        for d in dims:
            n *= d
        out.append((off, name, base, dims, ptr))
        off += size * n
        size_max, al_max = max(size_max, off), max(al_max, align)
    size = (size_max + al_max - 1) // al_max * al_max
    return out, size, al_max


def flat(body, base=0, prefix=""):
    """Every member, nested ones too: [(offset, path, base type, dims)]."""
    r = layout(body)
    if not r:
        return None
    out = []
    decls = {}
    for decl in split_top(body):
        agg = re.match(r"(struct|union)\s*\{(.*)\}\s*(\w+)", decl, re.S)
        if agg:
            decls[agg.group(3)] = (agg.group(1), agg.group(2))
    for o, n, b, dims, p in r[0]:
        out.append((base + o, prefix + n, b, dims))
        if n in decls:
            kind, inner = decls[n]
            sub = layout(inner, kind == "union")
            for io, iname, ib, idims, ip in sub[0]:
                out.append((base + o + io, prefix + n + "." + iname, ib, idims))
                if ib in ("struct", "union"):
                    out += [x for x in flat_inner(inner, kind, iname, base + o + io, prefix + n + ".")]
    return out


def flat_inner(body, kind, name, base, prefix):
    for decl in split_top(body):
        agg = re.match(r"(struct|union)\s*\{(.*)\}\s*(\w+)", decl, re.S)
        if agg and agg.group(3) == name:
            sub = layout(agg.group(2), agg.group(1) == "union")
            for io, iname, ib, idims, ip in sub[0]:
                yield (base + io, prefix + name + "." + iname, ib, idims)
            return


def learn(text):
    """Size the struct typedefs of a text (a unit or a header) for layout()."""
    clean = H.strip_comments(text)
    for _ in range(3):      # typedefs that use later ones
        for m in MT.TYPEDEF.finditer(clean):
            b = re.search(r"\{(.*)\}", clean[m.start():m._b], re.S)
            alias = re.match(r"typedef\s+(\w+)\s+(\w+)\s*;", clean[m.start():m._b].strip())
            if alias and alias.group(1) in SIZE:
                SIZE[alias.group(2)] = SIZE[alias.group(1)]
                ALIGN[alias.group(2)] = ALIGN.get(alias.group(1), min(SIZE[alias.group(1)], 16))
            if not b:
                continue
            r = layout(b.group(1), clean[m.start():m._b].lstrip().startswith("typedef union"))
            if r:
                SIZE[m.group(1)], ALIGN[m.group(1)] = r[1], r[2]


def fields(body):
    """[(offset, name, base type, dims, is pointer)] of a struct body, or None."""
    r = layout(body)
    return r[0] if r else None


def view(text, g):
    """(declaration match, struct body, is pointer) of g in a unit, or None.
    A plain `void *` / `u8 *` / `s8 *` declaration is a view with no body."""
    clean = H.strip_comments(text)
    for m in MT.EXTERN.finditer(clean):
        if m.group(3) != g:
            continue
        d = text[m.start():m._b]
        if re.match(r"extern\s+(void|u8|s8|char)\s*\*\s*" + g + r"\s*;", d.strip()):
            return m, None, True
        b = re.search(r"\{(.*)\}", d, re.S)
        if b:
            return m, b.group(1), bool(re.search(r"\}\s*\*", d))
        t = re.match(r"extern\s+(?:volatile\s+)?(\w+)\s*(\*?)\s*" + g + r"\s*;", d.strip())
        if not t:
            return None
        for tm in MT.TYPEDEF.finditer(clean):
            if tm.group(1) == t.group(1):
                b = re.search(r"\{(.*)\}", text[tm.start():tm._b], re.S)
                return (m, b.group(1), bool(t.group(2))) if b else None
        return None
    return None


def canon(typename):
    for h in sorted((ROOT / "include").rglob("*.h")):
        learn(h.read_text())
    for h in sorted((ROOT / "include").rglob("*.h")):
        t = H.strip_comments(h.read_text())
        for m in MT.TYPEDEF.finditer(t):
            if m.group(1) == typename:
                return h, flat(re.search(r"\{(.*)\}", t[m.start():m._b], re.S).group(1))
    sys.exit(f"{typename}: no typedef in include/")


def units_of(g):
    return [p for p in H.units() if re.search(r"\b" + g + r"\b", p.read_text())]


def show(g):
    for p in units_of(g):
        learn(p.read_text())
        v = view(p.read_text(), g)
        f = (fields(v[1]) if v[1] is not None else []) if v else None
        rel = p.relative_to(ROOT)
        if not f:
            print(f"{rel}: (not a sized struct view)")
            continue
        print(f"{rel}{' (pointer)' if v[2] else ''}: " +
              " ".join(f"{o:#x}:{n}{''.join(f'[{d}]' for d in dims)}" for o, n, b, dims, ptr in f
                       if not re.fullmatch(r"(p|pad|rest)[0-9A-Fa-fx_]*\d*", n)))


def migrate_text(text, g, typename, hdr, cf):
    v = view(text, g)
    if not v:
        return None, "no struct view"
    m, body, ptr = v
    learn(text)
    vf = fields(body) if body is not None else []
    if vf is None:
        return None, "view not sized"
    ren = {}
    for o, n, b, dims, p in vf:
        if re.fullmatch(r"(p|pad|rest)[0-9A-Fa-fx_]*\d*", n) and n not in re.findall(r"[.>]\s*(\w+)", text):
            continue
        at = [c for c in cf if c[0] == o]
        hit = ([c for c in at if c[1].split(".")[-1] == n] or
               [c for c in at if MT.ALIAS_T.get(c[2], c[2]) == MT.ALIAS_T.get(b, b) and bool(c[3]) == bool(dims)] or
               [c for c in at if bool(c[3]) and bool(dims)])
        if not hit:
            for co, cn, cb, cd in cf:
                if cd and co < o < co + SIZE.get(cb, 4) * eval("*".join(map(str, cd))):
                    return None, f"{n} at {o:#x} inside {cn}"
            return None, f"no member at {o:#x} ({n})"
        ren[n] = (hit[0][1], dims, hit[0][3])
    aliases = [g] + re.findall(r"^#define\s+(\w+)\s+\(?&?\s*" + g + r"\s*\)?\s*$", text, re.M)
    acc = "|".join(re.escape(a) for a in aliases)
    t = text

    def fix(mm):
        old = mm.group(3)
        if old not in ren:
            return mm.group(0)
        return mm.group(1) + mm.group(2) + ren[old][0]
    t = re.sub(r"(\b(?:" + acc + r")\b\s*)(\.|->)\s*(\w+)", fix, t)

    def field(mm):
        typ, off = re.sub(r"\s+", "", mm.group(2)).rstrip("*"), int(mm.group(3), 0)
        hit = [c for c in cf if c[0] == off and c[2] == typ and not c[3]]
        return f"{mm.group(1)}->{hit[0][1]}" if hit and ptr else mm.group(0)
    t = re.sub(r"M2C_FIELD\(\s*(" + acc + r")\s*,\s*([\w\s]+\*)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*\)", field, t)
    # a[i][j] where the type is flat
    for old, (new, vd, cd) in ren.items():
        if len(vd) == 2 and len(cd) == 1:
            t = re.sub(r"(\b(?:" + acc + r")\b\s*(?:\.|->)\s*" + new + r")\[([^\[\]]+)\]\[([^\[\]]+)\]",
                       lambda mm: f"{mm.group(1)}[({mm.group(2)}) * {vd[1]} + ({mm.group(3)})]", t)
        elif len(vd) != len(cd) and vd and cd:
            return None, f"{old}: dims {vd} vs {cd}"
    decl = f"extern {typename} {'*' if ptr else ''}{g};\n"
    t = t[:m.start()] + decl + t[m._b:]
    # drop the local typedef if the declaration was its only use
    tm = re.match(r"extern\s+(\w+)\s*\*?\s*" + g, text[m.start():m._b].strip())
    if tm and tm.group(1) != typename:
        local = tm.group(1)
        if len(re.findall(r"\b" + local + r"\b", H.strip_comments(t))) == 1:
            for d in MT.TYPEDEF.finditer(t):
                if d.group(1) == local:
                    t = t[:d.start()] + t[d._b:]
                    break
    inc = hdr.relative_to(ROOT / "include").as_posix()
    if f'"{inc}"' not in t:
        ms = list(MT.INCLUDE.finditer(t))
        at = ms[-1].end() if ms else 0
        t = t[:at] + f'#include "{inc}"\n' + t[at:]
    return t, ""


def same(a, b):
    """Objects equal but for the size gcc records on an undefined symbol (the
    declared type's size; the linker ignores it)."""
    if a == b:
        return True
    import io
    from elftools.elf.elffile import ELFFile

    def norm(data):
        e = ELFFile(io.BytesIO(data))
        secs = {x.name: x.data() for x in e.iter_sections() if x.name != ".symtab"}
        syms = [(y.name, y["st_value"], 0 if y["st_shndx"] == "SHN_UNDEF" else y["st_size"], y["st_info"]["bind"],
                 y["st_info"]["type"], y["st_shndx"]) for y in e.get_section_by_name(".symtab").iter_symbols()]
        return secs, syms
    return norm(a) == norm(b)


def migrate(g, typename):
    hdr, cf = canon(typename)
    snap = {}
    todo = {}
    for p in units_of(g):
        text = p.read_text()
        new, why = migrate_text(text, g, typename, hdr, cf)
        if new is None:
            print(f"keep {p.relative_to(ROOT)}: {why}")
            continue
        o = H.obj(p)
        snap[p] = o.read_bytes()
        todo[p] = (text, new)
    for p, (old, new) in todo.items():
        p.write_text(new)
        H.obj(p).unlink()
    subprocess.run(["ninja", "-k", "0"] + [str(H.obj(p).relative_to(ROOT)) for p in todo],
                   cwd=ROOT, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    bad = [p for p in todo if not H.obj(p).exists() or not same(H.obj(p).read_bytes(), snap[p])]
    for p in bad:
        p.write_text(todo[p][0])
        print(f"keep {p.relative_to(ROOT)}: object differs")
    if bad:
        subprocess.run(["ninja", "-k", "0"] + [str(H.obj(p).relative_to(ROOT)) for p in bad],
                       cwd=ROOT, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    print(f"{len(todo) - len(bad)} units moved to {typename}")


def main():
    if len(sys.argv) == 3 and sys.argv[1] == "show":
        show(sys.argv[2])
    elif len(sys.argv) == 4 and sys.argv[1] == "migrate":
        migrate(sys.argv[2], sys.argv[3])
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
