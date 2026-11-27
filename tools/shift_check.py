#!/usr/bin/env python3
"""Check that a shifted link moved every pointer with what it points at.

    tools/shift_check.py BASE.elf SHIFTED.elf [...]

Each SHIFTED.elf is the same objects linked with a pad inserted somewhere
(tools/gen_ninja.py's shift variants). An address of BASE maps to SHIFTED
through the nearest symbol at or below it (both links have the same
symbols), so padding the alignment adds after the insertion is followed too.
Then, for every word of BASE's loaded sections, at its mapped place in
SHIFTED:

  data   a word whose value v is an image address must read map(v);
  code   a jal/j must target map(target), and a lui + lo16 pair that builds
         an image address v must build map(v).

A value that stayed v although map(v) != v did not follow. Where it is
decides what it is (build/sta.map gives the object):
  asm (splat's or hand-written)   an error: a pointer written as a number;
  a relocated word of a C object  an error: a symbol the link did not move;
  C (src/game/data/)              an error unless the value is one
                                  tools/fake_pointers.py found to be a number;
  other C, unrelocated            a number in the source (a constant), so
                                  counted but not an error.
Exit status 1 on any error.
"""
import bisect
import struct
import sys

from elftools.elf.elffile import ELFFile

IMAGE = (0x00100000, 0x004BE180)
LOADED = (".text", ".data", ".sdata")
ROOT = __import__("pathlib").Path(__file__).resolve().parent.parent


def known_numbers():
    """Values tools/fake_pointers.py found to be numbers that only look like
    image addresses (ignored_ entries in config/symbol_addrs.txt)."""
    import re
    text = (ROOT / "config/symbol_addrs.txt").read_text()
    return {int(a, 16) for a in re.findall(r"^ignored_([0-9A-F]{8}) =", text, re.M)}


def objects(mapfile):
    """[(start, end, object path, relocated addresses)] of the loaded input
    sections, from ld's map; an object's sections of one name are matched to
    its map lines in file order."""
    import re
    from collections import defaultdict
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    lines = defaultdict(list)       # (object, section) -> [(start, size)]
    for line in open(mapfile):
        m = re.match(r"^ (\.text|\.data|\.rodata|\.sdata)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(\S+\.o)", line)
        if m and int(m.group(3), 16):
            lines[(m.group(4), m.group(1))].append((int(m.group(2), 16), int(m.group(3), 16)))
    out = []
    by_obj = defaultdict(list)
    for (o, sec), parts in lines.items():
        by_obj[o].append((sec, parts))
    for o, secs in by_obj.items():
        rel = defaultdict(set)      # section index -> relocated offsets
        names = []
        with open(ROOT / o, "rb") as f:
            e = ELFFile(f)
            for i, s in enumerate(e.iter_sections()):
                names.append((s.name, s["sh_size"]))
                if isinstance(s, RelocationSection):
                    rel[s["sh_info"]].update(r["r_offset"] for r in s.iter_relocations())
        for sec, parts in secs:
            idx = [i for i, (n, size) in enumerate(names) if n == sec and size]
            for (start, size), i in zip(parts, idx):
                out.append((start, start + size, o, {start + r for r in rel[i]}))
    return sorted(out, key=lambda t: t[0])


class Image:
    def __init__(self, path):
        self.f = open(path, "rb")
        self.e = ELFFile(self.f)
        self.secs = {s.name: (s["sh_addr"], s.data()) for s in self.e.iter_sections()
                     if s.name in LOADED}
        # syms: every named symbol; placed: those in a section (an absolute
        # symbol says nothing about where things moved)
        self.syms, self.placed = {}, {}
        for s in self.e.get_section_by_name(".symtab").iter_symbols():
            if s["st_info"]["type"] == "STT_FILE" or not s.name:
                continue
            if isinstance(s["st_shndx"], int):
                self.placed.setdefault(s.name, s["st_value"])
                self.syms.setdefault(s.name, s["st_value"])
            elif s["st_shndx"] == "SHN_ABS":
                self.syms.setdefault(s.name, s["st_value"])

    def word(self, addr):
        for base, data in self.secs.values():
            if base <= addr < base + len(data) - 3:
                return struct.unpack_from("<I", data, addr - base)[0]
        return None


def mapper(a, b):
    """old address -> new address, through the nearest symbol at or below."""
    pairs = sorted((v, b.placed[n]) for n, v in a.placed.items() if n in b.placed)
    keys = [p[0] for p in pairs]

    def m(addr):
        i = bisect.bisect_right(keys, addr) - 1
        if i < 0:
            return addr
        return pairs[i][1] + (addr - pairs[i][0])
    return m


def check(base, shifted, objs, numbers):
    a, b = Image(base), Image(shifted)
    starts = [o[0] for o in objs]

    def origin(addr):
        """(object, whether the object has a relocation at addr)."""
        i = bisect.bisect_right(starts, addr) - 1
        if i >= 0 and addr < objs[i][1]:
            return objs[i][2], addr in objs[i][3]
        return "?", False
    m = mapper(a, b)
    bad = []
    in_image = lambda v: IMAGE[0] <= v < IMAGE[1]
    for name, (start, data) in a.secs.items():
        n = len(data) // 4
        words = struct.unpack_from(f"<{n}I", data)
        for i, w in enumerate(words):
            addr = start + 4 * i
            nw = b.word(m(addr))
            if nw is None:
                continue
            if name != ".text":
                if in_image(w) and w % 4 == 0 and m(w) != w and nw == w:
                    bad.append((addr, w, f"{name} {addr:#010x}: pointer {w:#010x} did not move (-> {m(w):#010x})"))
                continue
            op = w >> 26
            if op in (2, 3):                     # j / jal
                t = ((addr + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
                nt = ((m(addr) + 4) & 0xF0000000) | ((nw & 0x3FFFFFF) << 2)
                if in_image(t) and nt != m(t):
                    bad.append((addr, t, f".text {addr:#010x}: jump to {t:#010x} went to {nt:#010x}, not {m(t):#010x}"))
            elif op == 15:                       # lui rt, hi: pair it with the next lo16 user
                rt = (w >> 16) & 31
                hi_rel = origin(addr)[1]
                for k in range(i + 1, min(i + 24, n)):
                    x = words[k]
                    xop, rs, xrt = x >> 26, (x >> 21) & 31, (x >> 16) & 31
                    if xop in (9, 13, 32, 33, 35, 36, 37, 40, 41, 43, 49, 57, 55, 63, 30, 31) and rs == rt \
                            and origin(start + 4 * k)[1] != hi_rel:
                        continue    # a %hi is paired with a %lo, a number with a number
                    if xop in (9, 13, 32, 33, 35, 36, 37, 40, 41, 43, 49, 57, 55, 63, 30, 31) and rs == rt:
                        lo = x & 0xFFFF
                        v = ((w & 0xFFFF) << 16) + (lo - 0x10000 if lo & 0x8000 and xop != 13 else lo)
                        v &= 0xFFFFFFFF
                        if in_image(v) and m(v) != v:
                            nlo_w = b.word(m(start + 4 * k))
                            if nlo_w is not None:
                                nlo = nlo_w & 0xFFFF
                                nv = ((nw & 0xFFFF) << 16) + (nlo - 0x10000 if nlo & 0x8000 and xop != 13 else nlo)
                                if nv & 0xFFFFFFFF == v:
                                    bad.append((addr, v, f".text {addr:#010x}: %hi/%lo of {v:#010x} did not move (-> {m(v):#010x})"))
                        break
                    if xop == 15 and xrt == rt:
                        break
    # a value that is a symbol in both links and follows that symbol (crt0's
    # _gp, which goes with .sdata, not with what lies at its address)
    by_value = {}
    for n, v in a.syms.items():
        if n in b.syms:
            by_value.setdefault(v, set()).add(b.syms[n])
    errors, constants = [], 0
    for addr, v, text in bad:
        o, relocated = origin(addr)
        if v in by_value and v in by_value[v]:
            continue        # v is a symbol that stays put in the shifted link
        if "/src/game/data/" in "/" + o:
            # text: four bytes of ASCII and NULs (a string, not a pointer)
            bs = v.to_bytes(4, "little")
            if all(c == 0 or 32 <= c < 127 for c in bs) and sum(32 <= c < 127 for c in bs) >= 2:
                constants += 1
                continue
        if not o.endswith(".c.o") or relocated:
            # asm, or a C object's relocated word (a symbol the link put in
            # the wrong place)
            errors.append(f"{text}  [{o}]")
        elif "/src/game/data/" in "/" + o and v not in numbers:
            errors.append(f"{text}  [{o}]")
        else:
            constants += 1
    return errors, constants


def main():
    base, rest = sys.argv[1], sys.argv[2:]
    objs = objects(base.rsplit(".", 1)[0] + ".map")
    numbers = known_numbers()
    status = 0
    for s in rest:
        errors, constants = check(base, s, objs, numbers)
        print(f"{s}: {len(errors)} pointer(s) that did not follow"
              f" ({constants} constants in C source and known numbers not counted)")
        for line in errors[:40]:
            print("  " + line)
        status |= bool(errors)
    sys.exit(status)


if __name__ == "__main__":
    main()
