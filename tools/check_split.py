#!/usr/bin/env python3
"""Audit splat's function boundaries in the game code.

    tools/check_split.py [-v]

Takes every glabel under asm/ (asm/matchings included) and every function
of build/sta.elf at or after the game start and checks each function against the retail bytes:

  align     a CodeWarrior function starts 16-byte aligned (8 in the ee-gcc
            modules)
  end       the last instruction before the zero fill is the delay slot of
            jr $ra, j or an unconditional b (a function falling into the next
            one is a bad split)
  fill      only zero words follow that last delay slot
  branch    every branch and j target lies inside the function, or j goes
            to a function start (a tail call)
  call      every jal goes to a function start (else a function is missing)
  stack     addiu $sp,$sp,-N in the prologue has a matching +N before
            each jr $ra
  entered   no other function branches into this one's middle
  merged    code after an unconditional jump's delay slot is reached by a
            branch or a code address in .data/.rodata (else it is a second
            function)

Prints one line per problem; -v also lists the functions that pass.
"""
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x00100000
GAME, TEXT_END = 0x00128210, 0x001EDE80
EE = [(0x001D3A90, 0x001D7EC0), (0x001DC328, 0x001DC900), (0x001E1E08, 0x001E5E80)]


def starts():
    """address -> name of every function: glabels under asm/, and the
    functions of the C units (from the linked build/sta.elf)."""
    from elftools.elf.elffile import ELFFile
    out = {}
    elf = ROOT / "build/sta.elf"
    if elf.exists():
        for sym in ELFFile(open(elf, "rb")).get_section_by_name(".symtab").iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_value"]:
                out[sym["st_value"]] = sym.name
    for f in (ROOT / "asm").rglob("*.s"):
        for m in re.finditer(r"^glabel (\S+)\n(?:.*\n){0,3}?\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ", f.read_text(), re.M):
            out[int(m.group(2), 16)] = m.group(1)
    return out


def sext(v):
    return v - 0x10000 if v & 0x8000 else v


def decode(w, pc):
    """(kind, target): kind in jr_ra, jr, j, jal, b (unconditional), cb
    (conditional branch), likely (branch-likely), None."""
    op = w >> 26
    if op == 0:
        fn = w & 0x3F
        if fn == 8:
            return ("jr_ra" if (w >> 21) & 31 == 31 else "jr"), None
        if fn == 9:
            return "jalr", None
        return None, None
    if op == 2:
        return "j", (pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
    if op == 3:
        return "jal", (pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
    tgt = pc + 4 + (sext(w & 0xFFFF) << 2)
    if op == 4 and (w >> 16) & 0x3FF == 0:              # beq $0,$0 = b
        return "b", tgt
    if op in (4, 5, 6, 7):
        return "cb", tgt
    if op in (0x14, 0x15, 0x16, 0x17):
        return "likely", tgt
    if op == 1:
        rt = (w >> 16) & 31
        if rt == 0x11 and (w >> 21) & 31 == 0:          # bgezal $0 = bal
            return "jal", tgt
        if rt in (0, 1, 0x10, 0x11):
            return "cb", tgt
        if rt in (2, 3, 0x12, 0x13):
            return "likely", tgt
    if op in (0x11, 0x12) and (w >> 21) & 31 == 8:      # bc1x / bc2x
        return ("likely" if (w >> 17) & 1 else "cb"), tgt
    return None, None


def jump_targets(rom):
    """Code addresses stored in .data/.rodata (jump tables, function pointers)."""
    lo, hi = 0x001EDE80, 0x00201B80
    ws = struct.unpack_from("<%dI" % ((hi - lo) // 4), rom, lo - BASE)
    return {w for w in ws if GAME <= w < TEXT_END and not w & 3}


def main():
    verbose = "-v" in sys.argv
    rom = (ROOT / "baserom/jp/sta.rom").read_bytes()
    word = lambda a: struct.unpack_from("<I", rom, a - BASE)[0]
    st = starts()
    game = sorted(a for a in st if GAME <= a < TEXT_END)
    bounds = list(zip(game, game[1:] + [TEXT_END]))
    owner = {}
    problems = []
    jt = jump_targets(rom)
    for a, b in bounds:
        ee = any(lo <= a < hi for lo, hi in EE)
        name = st[a]
        bad = []
        if a % (8 if ee else 16):
            bad.append(f"align: starts at {a:#x}")
        end = b
        while end > a and word(end - 4) == 0 and not (end - 8 >= a and decode(word(end - 8), end - 8)[0]):
            end -= 4
        if end - a < 8:
            bad.append("end: empty or a single word")
        else:
            k, _ = decode(word(end - 8), end - 8)
            if k not in ("jr_ra", "jr", "j", "b"):
                bad.append(f"end: last word before the fill is not a jump's delay slot ({word(end - 8):08x})")
        frame = 0
        w0 = word(a)
        for pc in range(a, min(a + 16, end), 4):      # MW may schedule the frame setup
            w = word(pc)
            if w >> 16 == 0x27BD and w & 0x8000:
                frame = -sext(w & 0xFFFF)
                break
        for pc in range(a, end, 4):
            owner[pc] = a
            w = word(pc)
            k, t = decode(w, pc)
            if k in ("b", "cb", "likely") and not a <= t < end:
                bad.append(f"branch: {pc:#x} leaves the function for {t:#x}")
            elif k == "j" and not a <= t < end and t not in st:
                bad.append(f"branch: {pc:#x} j to {t:#x}, not a function start")
            elif k == "jal" and t not in st:
                bad.append(f"call: {pc:#x} jal to {t:#x}, not a function start")
            elif k == "jr_ra" and frame:
                window = [word(x) for x in range(max(a, pc - 32), pc + 8, 4)]
                if not any(x >> 16 == 0x27BD and sext(x & 0xFFFF) == frame for x in window):
                    bad.append(f"stack: jr $ra at {pc:#x} without addiu $sp,{frame:#x}")
        targets = {decode(word(pc), pc)[1] for pc in range(a, end, 4)} | jt
        for pc in range(a, end - 8, 4):
            if decode(word(pc), pc)[0] in ("jr_ra", "jr", "j", "b"):
                nxt = pc + 8
                while nxt < end and word(nxt) == 0 and nxt not in targets:
                    nxt += 4
                # CodeWarrior branches to just past a copy of the branch's
                # delay slot, which leaves that one word unreachable
                if nxt < end and nxt not in targets and nxt + 4 not in targets:
                    bad.append(f"merged: code at {nxt:#x} after {pc:#x} is never branched to")
        problems += [(a, name, p) for p in bad]
        if verbose and not bad:
            print(f"ok    {name}")
    # branches into another function's middle
    for a, b in bounds:
        for pc in range(a, b, 4):
            k, t = decode(word(pc), pc)
            if k in ("b", "cb", "likely", "j", "jal") and t in owner and owner[t] != owner.get(pc) \
                    and t not in st:
                problems.append((owner[t], st[owner[t]], f"entered: {pc:#x} ({st[owner[pc]] if pc in owner else '?'}) "
                                 f"{k} into the middle at {t:#x}"))
    for a, name, p in sorted(set(problems)):
        print(f"{name:16s} {p}")
    n = len({a for a, *_ in problems})
    print(f"{len(game)} game functions, {n} with problems", file=sys.stderr)


if __name__ == "__main__":
    main()
