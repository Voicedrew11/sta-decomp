#!/usr/bin/env python3
"""Carve the library translation units under src/sce/ out of splat's asm.

    tools/carve.py            place every unit, rewrite the splat subsegments
                              and config/link_order.jp.txt
    tools/carve.py --check    place every unit and report, write nothing

Every .c and .s under src/sce/ is compiled with tools/compile_c.sh into
build/carve/ and placed in the retail ELF by tools/lib_layout.py. Each unit
must be placed whole: every section found, and every initialized byte equal
to the retail one. Then:

  * config/sta.jp.yaml gets one subsegment per unit and section, and an asm
    (or data/rodata/bss) subsegment for each stretch between units that no
    unit claims. A stretch that is only the next unit's alignment fill gets
    none: ld reproduces it.
  * config/link_order.jp.txt gets one order that every section agrees with:
    a merge of the per-section address orders. mwldps2 put the libraries
    before the game in every section, so the library and gap units come
    first and the game's splat units (the last stretch of each section)
    last. Units in different orders in different sections are an error.
  * config/symbol_addrs.carve.txt names, for splat, every global the units
    define, every static function, object and data label they define (with
    size, and allow_duplicated where a name repeats: statics may), and every
    symbol they reference that the asm defines (resolved from the retail jal
    targets and %hi/%lo pairs). The asm and the C then agree on names. Statics
    a game data word points into are left unnamed: the game asm cannot link to
    them. Constants the retail code builds with a lui and lo16 (0x00FFFFFF) are
    listed with ignore:True, so splat writes the bare value and not a symbol.
    A name config/symbol_addrs.txt puts at another address is an error: one of
    the two is wrong.

Run tools/split.py and the build afterwards (./build.sh does both when asm/ is
gone). The last asm stretch of each section is the game's and keeps the
section's name (text, data, rodata, bss); it also holds whatever library code
after the last placed unit is still asm.
"""
import bisect
import os
import re
import struct
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lib_layout import (GAME_START, GP, R_26, R_GPREL16, R_HI16, R_LO16, Obj,  # noqa: E402
                        layout, load_retail,
                        load_symbols, sext16)

ROOT = Path(__file__).resolve().parent.parent
YAML = ROOT / "config/sta.jp.yaml"
LINK_ORDER = ROOT / "config/link_order.jp.txt"
CARVE_SYMS = ROOT / "config/symbol_addrs.carve.txt"
OBJDIR = "build/carve"
ROM_BASE = 0x00100000

# Splat sections of the main segment: (section, splat type, C-owned type, base
# unit name, vram start, vram end, alignment of a gap unit's start).
# mwldps2 wrote every .data and then every .rodata into one range; the
# .rodata run starts at libgraph's "rom0:ROMVER" (0x1F8880).
SECTIONS = [
    (".text", "asm", "c", "text", 0x00100000, 0x001EDE80, 8),
    (".data", "data", ".data", "data", 0x001EDE80, 0x001F8880, 4),
    (".rodata", "rodata", ".rodata", "rodata", 0x001F8880, 0x00201B80, 4),
    # .bss ends at 0x4BE120 for carve: after it come only the commons (libc's
    # errno, from sbrkr.c) and the end's 0x80 alignment, which ld lays out
    # (config/sta.jp.ld.in)
    (".bss", "bss", ".bss", "bss", 0x00202480, 0x004BE120, 4),
]
BSS_ROM = 0x101E80

# The subsegments carve.py does not touch, in ROM order, keyed by the section
# they follow.
# .sdata and .sbss are all the game's (the libraries are built with -G 0):
# each is one unit, the data-only C unit tools/data_to_c.py wrote for it
# when there is one, else splat's asm.
SDATA_C = "src/game/data/sdata.c"
SBSS_C = "src/game/data/sbss.c"
_sdata = (ROOT / SDATA_C).exists()
_sbss = (ROOT / SBSS_C).exists()
FIXED = {
    ".rodata": ['      - [0x101B80, .sdata, game/data/sdata]' if _sdata
                else '      - [0x101B80, sdata, sdata]',
                '      - { start: 0x101E80, type: .sbss, vram: 0x00201E80, name: game/data/sbss }'
                if _sbss else
                '      - { start: 0x101E80, type: sbss, vram: 0x00201E80, name: sbss }'],
}
# the units of the sections carve.py leaves whole
FIXED_UNITS = [SDATA_C if _sdata else "asm/data/sdata.sdata.s",
               SBSS_C if _sbss else "asm/data/sbss.sbss.s"]
GAME_UNITS = ["asm/text.s", "asm/data/data.data.s", "asm/data/rodata.rodata.s",
              *FIXED_UNITS, "asm/data/bss.bss.s"]
# defined by config/sta.jp.ld.in, not by any unit (_gp is named for splat: the
# units reference it through %hi/%lo)
LINKER_SYMS = {"_fbss", "_end", "_stack", "_stack_size", "_heap_size", "_gp"}
# and every symbol config/linker_syms.txt gives ld: the link defines them, so
# splat must not be handed them (a game alias at a library function's address
# would clash with the function's name)
LINKER_SYMS |= set(re.findall(r"^(\w+)\s*=", (ROOT / "config/linker_syms.txt").read_text(), re.M))
# and the field names tools/data_to_c.py gives ld (config/data_aliases.txt)
if (ROOT / "config/data_aliases.txt").exists():
    LINKER_SYMS |= set(re.findall(r"^(\w+)\s*=", (ROOT / "config/data_aliases.txt").read_text(), re.M))
BEGIN = "      # --- tools/carve.py: generated from here ---"
END = "      # --- tools/carve.py: generated up to here ---"


def align_up(v, a):
    return (v + a - 1) // a * a


def compile_all(units):
    def one(u):
        out = ROOT / OBJDIR / (u + ".o")
        r = subprocess.run(["tools/compile_c.sh", u, f"{OBJDIR}/{u}.o"], cwd=ROOT,
                           capture_output=True, text=True)
        return u, r.returncode, r.stderr
    if (ROOT / OBJDIR).exists():
        subprocess.run(["rm", "-rf", str(ROOT / OBJDIR)], check=True)
    with ThreadPoolExecutor(os.cpu_count()) as ex:
        bad = [(u, err) for u, rc, err in ex.map(one, units) if rc]
    for u, err in bad:
        print(f"{u}: compile failed\n{err}", file=sys.stderr)
    if bad:
        sys.exit(1)


def is_pad(sec, cursor, addr, align):
    """Is [cursor, addr) only the fill ld puts before a unit of this alignment?

    The run must be what the unit's alignment explains, and zero: a unit with
    a large alignment (64) can sit after a short object no unit claims yet
    (libvu0's .data before cdvd000's). .bss has no bytes to check; a variable
    hiding in its fill would show up as an undefined symbol at link time."""
    if addr != align_up(cursor, max(align, 1)):
        return False
    if sec == ".bss":
        return True
    vbase, data = RETAIL[sec]
    return not any(data[cursor - vbase:addr - vbase])


def asm_path(sec, name):
    return {".text": f"asm/{name}.s", ".data": f"asm/data/{name}.data.s",
            ".rodata": f"asm/data/{name}.rodata.s", ".bss": f"asm/data/{name}.bss.s"}[sec]


def unit_symbols(placed):
    """name -> (addr, is_func, size) for globals the units define or reference,
    and a list of (name, addr, is_func, size) for their static functions and
    objects. Statics may repeat across units, so splat is told they may."""
    retail = load_retail(str(ROOT / "baserom/jp/SLPS_252.17"))
    tbase, tdata = retail[".text"]
    out, clash, statics = {}, [], []

    def add(name, addr, func, why, size=0):
        if name in LINKER_SYMS or "__as_" in name or name.startswith("__include_asm_"):
            return      # merge aliases (ld: tools/rel_syms.py) and INCLUDE_ASM markers
        if name in out and out[name][0] != addr:
            clash.append(f"{name}: {out[name][0]:#x} and {addr:#x} ({why})")
        if name not in out or size:
            out[name] = (addr, func, size)

    from elftools.elf.elffile import ELFFile
    for unit, secs in placed.items():
        path = ROOT / OBJDIR / (unit + ".o")
        o = Obj(str(path), unit)
        with open(path, "rb") as f:
            e = ELFFile(f)
            # an INCLUDE_ASM unit's .text.iaN are its .text; the marker is nothing
            names = {i: (".text" if s.name.startswith(".text.ia") and s.name != ".text.iastub"
                         else None if s.name == ".text.iastub" else s.name)
                     for i, s in enumerate(e.iter_sections())}
            symlist = list(e.get_section_by_name(".symtab").iter_symbols())
            starts = {}   # section -> sorted symbol offsets, to size unsized asm labels
            for s in symlist:
                if isinstance(s["st_shndx"], int) and s["st_info"]["type"] != "STT_SECTION":
                    starts.setdefault(names.get(s["st_shndx"]), set()).add(o.offset_of(s))
            for s in symlist:
                shndx = s["st_shndx"]
                sec = names.get(shndx) if isinstance(shndx, int) else None
                value = o.offset_of(s)
                bind, typ = s["st_info"]["bind"], s["st_info"]["type"]
                if sec not in secs or typ == "STT_SECTION" or not s.name:
                    continue
                # statics: functions and objects, and the data labels ee-gcc gives
                # its static variables (NOTYPE, outside .text)
                static = bind == "STB_LOCAL" and not s.name.startswith(".L") and (
                    typ in ("STT_FUNC", "STT_OBJECT") or
                    (typ == "STT_NOTYPE" and sec != ".text"))
                if bind == "STB_GLOBAL" or static:
                    # an unsized symbol runs to the next one in its section
                    size = s["st_size"] or min([v for v in starts[sec] if v > value]
                                               + [secs[sec][1]]) - value
                    func = typ == "STT_FUNC"
                    if bind == "STB_GLOBAL":
                        add(s.name, secs[sec][0] + value, func, f"defined by {unit}", size)
                    else:
                        statics.append((s.name, secs[sec][0] + value, func, size, unit))
        for sec in (".data", ".rodata"):
            if sec not in secs:
                continue
            rbase, rdata = retail[sec]
            sdata = o.secs[sec][3]
            for off, typ, tsec, sval, sname in o.relocs[sec]:
                if typ == 2 and tsec is None and sname:   # R_MIPS_32 to an undefined symbol
                    ow = struct.unpack_from("<I", sdata, off)[0]
                    rw = struct.unpack_from("<I", rdata, secs[sec][0] - rbase + off)[0]
                    add(sname, rw - ow, False, f"pointed to by {unit} {sec}")
        if ".text" not in secs:
            continue
        base = secs[".text"][0]
        data = o.secs[".text"][3]
        hi = {}
        for off, typ, tsec, sval, sname in sorted(o.relocs[".text"]):
            if tsec is not None or not sname:
                continue
            ow = struct.unpack_from("<I", data, off)[0]
            rw = struct.unpack_from("<I", tdata, base - tbase + off)[0]
            if typ == R_26:
                add(sname, ((rw & 0x3FFFFFF) << 2) | ((base + off) & 0xF0000000), True,
                    f"called from {unit}")
            elif typ == R_HI16:
                # keyed by the lui's target register: CodeWarrior gives every
                # access its own lui/%lo pair, each with its own addend
                hi[(sname, (ow >> 16) & 31)] = (ow, rw)
            elif typ == R_LO16 and (sname, (ow >> 21) & 31) in hi:
                how, hrw = hi[(sname, (ow >> 21) & 31)]
                addend = ((how & 0xFFFF) << 16) + sext16(ow)
                add(sname, ((hrw & 0xFFFF) << 16) + sext16(rw) - addend, False,
                    f"referenced from {unit}")
            elif typ == R_GPREL16:
                # small data the game C reaches through $gp: the retail offset
                # from _gp, less the object's in-place addend
                add(sname, GP + sext16(rw) - sext16(ow), False, f"referenced from {unit}")
    return out, statics, clash


# opcodes of the I-type instructions that take a lui's register as rs and
# finish an address: ALU immediates, loads and stores
LO_OPS = set(range(0x08, 0x0F)) | set(range(0x20, 0x40))
ZERO_EXT = {0x0C, 0x0D, 0x0E}      # andi, ori, xori


def constants(placed, real):
    """Constants that retail code builds with a lui and the lo16 instructions after it.

    Retail code builds these constants (0x00FFFFFF is lui 0x100, addiu -1), and
    splat cannot tell them from addresses. The register is followed through the
    instructions after the lui: each value it takes, and each address it forms,
    with no relocation on the instruction, is a constant. Those not in `real`
    (the addresses a symbol names) are returned: splat is told to ignore them,
    and writes the bare value as the C object has it."""
    out = set()
    for unit, secs in placed.items():
        if ".text" not in secs:
            continue
        o = Obj(str(ROOT / OBJDIR / (unit + ".o")), unit)
        data = o.secs[".text"][3]
        relocated = {off for off, *_ in o.relocs[".text"]}
        words = struct.unpack("<%dI" % (len(data) // 4), data[:len(data) // 4 * 4])
        for i, w in enumerate(words):
            if w >> 26 != 0xF or 4 * i in relocated:
                continue
            r = (w >> 16) & 31
            val = (w & 0xFFFF) << 16
            for j in range(i + 1, len(words)):
                x = words[j]
                op, rs, rt = x >> 26, (x >> 21) & 31, (x >> 16) & 31
                if 4 * j in relocated and r in (rs, rt):
                    break       # a symbol's lo16: the address is named
                if op == 0 and (x >> 11) & 31 == r or op == 0xF and rt == r:
                    break       # the register is written from elsewhere
                if rs != r or op not in LO_OPS:
                    if rt == r:
                        break   # a load, or another ALU op, into r
                    continue
                lo = x & 0xFFFF
                ea = (val | lo) if op in ZERO_EXT else (val + sext16(lo)) & 0xFFFFFFFF
                if ea and ea not in real:
                    out.add(ea)
                if rt == r and not 0x20 <= op < 0x40:   # an ALU result in r
                    val = ea
                elif rt == r:
                    break       # a load into r
        # an addiu or ori that adds to its own register and is not reached from a
        # lui in the straight run above: splat takes the nearest lui of that register
        for j, x in enumerate(words):
            op, rs, rt = x >> 26, (x >> 21) & 31, (x >> 16) & 31
            if op not in (0x09, 0x0D) or rs != rt or 4 * j in relocated:
                continue
            for i in range(j - 1, max(j - 400, -1), -1):
                if words[i] >> 26 == 0xF and (words[i] >> 16) & 31 == rt:
                    lo = x & 0xFFFF
                    hi = (words[i] & 0xFFFF) << 16
                    ea = (hi | lo) if op == 0x0D else (hi + sext16(lo)) & 0xFFFFFFFF
                    if ea and ea not in real:
                        out.add(ea)
                    break
    return out


def game_pointers(placed, statics):
    """The statics a word or a %hi/%lo pair outside the placed units points into.

    The game's own data holds pointers into some library statics (the vudata
    tables point into sdrStack, fsSendBuf). A static's name lives in its C
    object, which the link cannot reach from the game's asm, so such a static
    is not named for splat. Returns the set of (name, address) pairs."""
    spans = sorted((a, a + max(size, 1), (name, a)) for name, a, _, size, _ in statics)
    starts = [a for a, _, _ in spans]
    placed_spans = sorted((a, a + size) for secs in placed.values() for a, size, _ in secs.values())
    placed_starts = [a for a, _ in placed_spans]
    hit = set()

    def outside(w):
        j = bisect.bisect_right(placed_starts, w) - 1
        return j < 0 or w >= placed_spans[j][1]

    def note(v):
        i = bisect.bisect_right(starts, v) - 1
        if i >= 0 and v < spans[i][1]:
            hit.add(spans[i][2])

    # Code outside the placed units: unplaced library members can share an
    # object with a placed one in retail (the asm after mktime.o reads its
    # _DAYS_BEFORE_MONTH), so a %hi/%lo pair there pins the static as well.
    tbase, tdata = RETAIL[".text"]
    tw = struct.unpack("<%dI" % (len(tdata) // 4), tdata)
    lui = {}
    for k, x in enumerate(tw):
        if not outside(tbase + 4 * k):
            lui.clear()
            continue
        op, rs, rt = x >> 26, (x >> 21) & 31, (x >> 16) & 31
        if op == 0xF:
            lui[rt] = (k, (x & 0xFFFF) << 16)
        elif op in LO_OPS and rs in lui and k - lui[rs][0] < 32:
            note((lui[rs][1] + sext16(x & 0xFFFF)) & 0xFFFFFFFF)
    # Words in the data sections. Not .text: its words are instructions, and
    # one that happens to equal an address inside a static (0x00101880, an
    # sll, lands in libdma's _sceDmaWait) is no pointer; the loop above reads
    # the code's real references.
    for sec, (vbase, data) in RETAIL.items():
        if sec in (".bss", ".text"):
            continue
        for off in range(0, len(data) - 3, 4):
            v = struct.unpack_from("<I", data, off)[0]
            if outside(vbase + off):
                note(v)
    return hit


RETAIL = {}


def main():
    RETAIL.update(load_retail(str(ROOT / "baserom/jp/SLPS_252.17")))
    check = "--check" in sys.argv
    units = sorted(str(p.relative_to(ROOT)) for d in ("src/sce", "src/game")
                   for p in (ROOT / d).rglob("*") if p.suffix in (".c", ".s"))
    compile_all(units)
    rows = layout(str(ROOT / OBJDIR))

    # unit -> {section: (addr, size, align)}; every section must be placed
    placed, problems = {}, []
    for unit, sec, size, align, addr, how, ok in rows:
        if addr is None or ok == "NO":
            problems.append(f"{unit} {sec}: {how}, bytes {ok}")
            continue
        placed.setdefault(unit, {})[sec] = (addr, size, align)
    if problems:
        print("not placed whole:\n  " + "\n  ".join(problems), file=sys.stderr)
        sys.exit(1)

    # INCLUDE_ASM units (tools/include_asm.py): their chunks' gaps in .text
    asm_gaps = {}
    for u in placed:
        if u.endswith(".c"):
            o = Obj(str(ROOT / OBJDIR / (u + ".o")), u)
            if o.gaps:
                asm_gaps[u] = o.gaps

    # per-section order; units must not overlap
    order = {}
    for sec, *_ in SECTIONS:
        seq = sorted((v[sec][0], u) for u, v in placed.items() if sec in v)
        for (a1, u1), (a2, u2) in zip(seq, seq[1:]):
            if a1 + placed[u1][sec][1] > a2:
                problems.append(f"{sec}: {u1} overlaps {u2}")
        order[sec] = [u for _, u in seq]
    if problems:
        print("\n".join(problems), file=sys.stderr)
        sys.exit(1)

    # Subsegments, and each section's sequence of link-order nodes (unit
    # paths, asm paths). The last asm stretch of a section is the game's
    # unit and keeps the section's base name.
    yaml_lines, seqs, game = [], [], set()
    first_addr = {}
    n_gaps = 0
    for sec, asm_type, c_type, base, start, end, gap_align in SECTIONS:
        cursor, segs, seq = start, [], []

        def emit(vram, typ, name):
            if sec == ".bss":
                segs.append(f"      - {{ start: 0x{BSS_ROM:06X}, type: {typ}, vram: 0x{vram:08X}, name: {name} }}")
            else:
                segs.append(f"      - [0x{vram - ROM_BASE:06X}, {typ}, {name}]")

        game_start = GAME_START[sec]
        crossed = False

        def gap(upto):
            """An asm unit for [cursor, upto). The first one at or after the game
            start keeps the section's base name; the others are named after
            their address (gen_ninja.py files those below the game start under
            sce, the rest under game)."""
            nonlocal n_gaps
            g = start if cursor == start else align_up(cursor, gap_align)
            # zero fill up to the next 16-byte boundary is the alignment of
            # the (16-aligned) code that follows, not a function of its own
            if g != start and sec == ".text" and g < upto and is_pad(sec, cursor, align_up(cursor, 16), 16):
                g = align_up(cursor, 16)
            if g >= upto:
                return
            if g >= game_start and not any(n in game for n in seq):
                name = base
                game.add(asm_path(sec, name))
            else:
                name = f"{base}_{g:08X}"
                n_gaps += 1
            emit(g, asm_type, name)
            path = asm_path(sec, name)
            seq.append(path)
            first_addr[path] = g

        def cross():
            """Close the library stretch at the game start (unless it is only
            the zero fill the next unit's alignment reproduces)."""
            nonlocal cursor, crossed
            if crossed:
                return
            crossed = True
            if cursor < game_start and not is_pad(sec, cursor, game_start, 16):
                gap(game_start)
            cursor = max(cursor, game_start)

        for u in order[sec]:
            addr, size, align = placed[u][sec]
            if addr >= game_start:
                cross()
            elif u.startswith("src/game/"):
                print(f"{u}: {sec} at {addr:#x}, before the game start {game_start:#x}", file=sys.stderr)
                sys.exit(1)
            if not (cursor == start and addr == start) and not is_pad(sec, cursor, addr, align):
                gap(addr)
            uname = u[len("src/"):].rsplit(".", 1)[0]
            ugaps = asm_gaps.get(u, []) if sec == ".text" else []
            if not (ugaps and ugaps[0][0] == 0):        # a unit that starts with its chunk
                emit(addr, "hasm" if (sec == ".text" and u.endswith(".s")) else c_type, uname)
            seq.append(u)
            # an INCLUDE_ASM unit: each chunk stays its own asm subsegment,
            # linked right after the unit, and the unit resumes after it
            for off, n, _ in ugaps:
                cursor = addr + off
                gap(addr + off + n)
                if off + n < size:
                    emit(addr + off + n, c_type, uname)
            cursor = addr + size
        cross()
        gap(end)
        yaml_lines += segs + FIXED.get(sec, [])
        seqs.append(seq)
    for u, v in placed.items():
        first_addr[u] = min(a for a, _, _ in v.values())

    # one link order for all sections: a topological merge of the sequences.
    # Head units first, then the game's units in section order, then the rest
    # by address.
    nodes = set(first_addr) | set(FIXED_UNITS)
    succ = {n: set() for n in nodes}
    for seq in seqs:
        for x, y in zip(seq, seq[1:]):
            succ[x].add(y)
    indeg = {n: 0 for n in nodes}
    for x in succ:
        for y in succ[x]:
            indeg[y] += 1
    game_rank = {n: i for i, n in enumerate(GAME_UNITS)}

    def key(n):
        if n in game_rank:
            return (1, game_rank[n])
        return (0, first_addr[n])
    ready = sorted((n for n in nodes if not indeg[n]), key=key)
    link = []
    while ready:
        n = ready.pop(0)
        link.append(n)
        for y in succ[n]:
            indeg[y] -= 1
            if not indeg[y]:
                ready.append(y)
        ready.sort(key=key)
    if len(link) != len(nodes):
        print("units are in different orders in different sections", file=sys.stderr)
        sys.exit(1)

    print(f"tools/carve.py: {len(placed)} units placed, {n_gaps} gap units")
    for sec, *_ in SECTIONS:
        total = sum(placed[u][sec][1] for u in order[sec])
        print(f"  {sec}: {len(order[sec])} units, {total:#x} bytes")
    syms, statics, clash = unit_symbols(placed)
    n2a, _ = load_symbols(generated=False)
    for name, (addr, *_) in syms.items():
        if name in n2a and n2a[name] != addr:
            clash.append(f"{name}: symbol_addrs.txt says {n2a[name]:#x}, the units say {addr:#x}")
    real = {a for a, *_ in syms.values()} | set(n2a.values())
    real |= {a for _, a, *_ in statics}
    ignored = constants(placed, real)
    pointed = game_pointers(placed, statics)
    statics = [st for st in statics if (st[0], st[1]) not in pointed]
    if clash:
        print("symbol clashes:\n  " + "\n  ".join(clash), file=sys.stderr)
        sys.exit(1)
    if check:
        return

    lines = ["// Generated by tools/carve.py from the units under src/sce/; do not edit.",
             "// Globals the library units define, and the symbols they reference",
             "// (placed by the retail relocated words)."]
    # splat checks repeated names within one file: a name that is static in one
    # unit and defined again in another is listed with allow_duplicated
    static_names = {n for n, *_ in statics}
    entries = [(addr, name, func, size) for name, (addr, func, size) in syms.items()
               if name not in n2a]
    # CodeWarrior's compiler-made locals (@24: jump tables, float constants)
    # are no names for splat or gas; splat names them by address
    entries += [(addr, name, func, size) for name, addr, func, size, _ in statics
                if n2a.get(name) != addr and not name.startswith("@")]
    names = [name for _, name, *_ in entries]
    dup = {n for n in names if n in static_names and names.count(n) > 1}
    lines_out = [(addr, name, func, size, "allow_duplicated:True" if name in dup else "")
                 for addr, name, func, size in entries]
    lines_out += [(addr, f"ignored_{addr:08X}", False, 0, "ignore:True") for addr in ignored]
    for addr, name, func, size, extra in sorted(lines_out, key=lambda e: (e[0], e[1])):
        attrs = (["type:func"] if func else []) + ([f"size:0x{size:X}"] if size else [])
        attrs += [extra] if extra else []
        lines.append(f"{name} = 0x{addr:08X};" + (" // " + " ".join(attrs) if attrs else ""))
    CARVE_SYMS.write_text("\n".join(lines) + "\n")

    text = YAML.read_text()
    a = text.index(BEGIN) + len(BEGIN) + 1
    b = text.index(END)
    YAML.write_text(text[:a] + "\n".join(yaml_lines) + "\n" + text[b:])

    lo = LINK_ORDER.read_text().splitlines()
    comments = [l for l in lo if l.startswith("#") or not l.strip()]
    LINK_ORDER.write_text("\n".join(comments + link) + "\n")


if __name__ == "__main__":
    main()
