#!/usr/bin/env python3
"""Find Shadow Tower Abyss functions that look like decompiled KFIV ones.

    tools/engine_match.py [--holyland DIR] [--top N]      rank and write the table
    tools/engine_match.py --show STA_ADDR KFIV_NAME       side-by-side token diff

Both games are FromSoftware's and are said to share an engine, so a
function kfiv-decomp (holyland) has in C is a starting point for the sta
function that does the same. The games were built with different compilers
(KFIV: ee-gcc 2.9; sta: CodeWarrior, two modules ee-gcc 2.96), so functions
are compared as normalised instruction sequences:

  * operands are dropped (registers, immediates, offsets, relocations);
  * nops, the stack adjustment and the prologue/epilogue saves and restores
    of callee-saved registers ($s0-$s7, $fp, $ra, $f20-$f31) are dropped;
  * equivalent forms are merged: daddu/addu, daddiu/addiu, dsubu/subu, the
    branch-likely forms into the plain ones, the move idioms into `move`,
    and dsll32/dsra32 sign extension pairs into `ext`;
  * a jal to a named SDK/libc function keeps the callee's name (`jal:memset`):
    those names are the same in both games, and they anchor the comparison.

Candidates come from shared token 4-grams; each sta function's best KFIV
candidates are scored with difflib's ratio on the token sequences, weighted
by how well the SDK calls and the lengths agree. The table goes to
build/engine_match.tsv, best first: sta address and size, compiler module
(mw or ee), KFIV address and name, score, holyland source file.

KFIV's code comes from the user's disc (baserom/kfiv_us.iso, SHA-1 checked),
extracted to baserom/kfiv/SLUS_203.18. KFIV's function names and their C
come from the holyland checkout.
"""
import argparse
import difflib
import hashlib
import io
import os
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

import rabbitizer

ROOT = Path(__file__).resolve().parent.parent
KFIV_ELF = ROOT / "baserom/kfiv/SLUS_203.18"
KFIV_ISO = ROOT / "baserom/kfiv_us.iso"
KFIV_SHA1 = "8031536201dec92889d3013ca80f09374571d626"
STA_ROM = ROOT / "baserom/jp/sta.rom"
OUT = ROOT / "build/engine_match.tsv"

STA_GAME = (0x00128210, 0x001EDE80)
STA_EE = [(0x001D3A90, 0x001D7EC0), (0x001DC328, 0x001DC900), (0x001E1E08, 0x001E5E80)]   # ee-gcc modules
KFIV_GAME = (0x001000C8, 0x00216778)   # after crt0, before libvu0 (most of the game)

SAVED = {16, 17, 18, 19, 20, 21, 22, 23, 30, 31}
CANON = {"daddu": "addu", "daddiu": "addiu", "dsubu": "subu", "beql": "beq", "bnel": "bne",
         "beqzl": "beqz", "bnezl": "bnez", "blezl": "blez", "bgtzl": "bgtz", "bltzl": "bltz",
         "bgezl": "bgez", "bc1tl": "bc1t", "bc1fl": "bc1f", "j": "b"}


# --------------------------------------------------------------------------- input

def kfiv_text() -> tuple[int, bytes]:
    if not KFIV_ELF.exists():
        import pycdlib
        if not KFIV_ISO.exists():
            sys.exit(f"KFIV disc image not found: link it at {KFIV_ISO.relative_to(ROOT)}")
        iso = pycdlib.PyCdlib()
        iso.open(str(KFIV_ISO))
        buf = io.BytesIO()
        iso.get_file_from_iso_fp(buf, iso_path="/SLUS_203.18;1")
        iso.close()
        KFIV_ELF.parent.mkdir(parents=True, exist_ok=True)
        KFIV_ELF.write_bytes(buf.getvalue())
    elf = KFIV_ELF.read_bytes()
    if hashlib.sha1(elf).hexdigest() != KFIV_SHA1:
        sys.exit(f"{KFIV_ELF}: not the KFIV USA retail ELF (SHA-1 mismatch)")
    phoff, = struct.unpack_from("<I", elf, 0x1C)
    phnum, = struct.unpack_from("<H", elf, 0x2C)
    for i in range(phnum):
        p_type, off, vaddr, _, filesz = struct.unpack_from("<5I", elf, phoff + 32 * i)
        if p_type == 1 and filesz:
            return vaddr, elf[off:off + filesz]
    sys.exit("KFIV ELF: no load segment")


def read_syms(path: Path) -> dict[int, str]:
    out = {}
    if path.exists():
        for line in path.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+);", line)
            if m and "type:func" in line:
                out[int(m.group(2), 16)] = m.group(1)
    return out


C_DEF = re.compile(r"^(?!static\s+inline)[A-Za-z_][\w \t\*]*?\b([A-Za-z_]\w*)\s*\(([^;{}]*)\)\s*\{?\s*$")


def holyland_sources(hl: Path) -> dict[str, Path]:
    """function name -> the holyland C file that defines it (src/game, then
    src/nonmatching)."""
    out = {}
    for sub in ("src/game", "src/nonmatching"):
        for p in sorted((hl / sub).rglob("*.c")):
            lines = p.read_text(errors="replace").splitlines()
            for i, l in enumerate(lines):
                m = C_DEF.match(l)
                if not m or m.group(1) in ("if", "while", "for", "switch", "return", "sizeof"):
                    continue
                nxt = l.rstrip().endswith("{") or (i + 1 < len(lines) and lines[i + 1].lstrip().startswith("{"))
                if nxt:
                    out.setdefault(m.group(1), p)
    return out


# --------------------------------------------------------------------------- tokens

def tokens(words: list[int], vram: int, names: dict[int, str]) -> list[str]:
    out = []
    i = 0
    while i < len(words):
        w = words[i]
        ins = rabbitizer.Instruction(w, vram=vram + 4 * i, category=rabbitizer.InstrCategory.R5900)
        op = ins.getOpcodeName()
        i += 1
        if w == 0:
            continue
        rs, rt = (w >> 21) & 31, (w >> 16) & 31
        opc = w >> 26
        # stack frame and callee-saved register traffic
        if opc in (0x09, 0x19) and rs == 29 and rt == 29:          # addiu/daddiu sp, sp, n
            continue
        if rs == 29 and opc in (0x2B, 0x3F, 0x1F, 0x23, 0x37, 0x1E) and rt in SAVED:   # sw/sd/sq/lw/ld/lq
            continue
        if rs == 29 and opc in (0x39, 0x31) and 20 <= rt <= 31:     # swc1/lwc1 $f20-$f31
            continue
        # moves: addu/daddu/or rd, rs, $zero
        if opc == 0 and (w & 0x3F) in (0x21, 0x2D, 0x25) and rt == 0:
            out.append("move")
            continue
        # dsll32 x,16 / dsra32 x,16 (CodeWarrior's sign extension) vs sll/sra
        if op in ("dsll32", "dsra32", "dsrl32") and i < len(words) + 1:
            out.append("ext" if op != "dsrl32" else "extu")
            continue
        if op == "jal":
            t = ins.getInstrIndexAsVram()
            out.append("jal:" + names[t] if t in names else "jal")
            continue
        out.append(CANON.get(op, op))
    # collapse adjacent `ext ext` (the two halves of one extension)
    col = []
    for t in out:
        if t in ("ext", "extu") and col and col[-1] == t:
            continue
        col.append(t)
    return col


def is_jump(w: int) -> bool:
    """jr/jalr, j/jal, or a branch: an instruction with a delay slot."""
    op = w >> 26
    if op == 0:
        return (w & 0x3F) in (0x08, 0x09)
    if op == 1:
        return ((w >> 16) & 0x1F) in (0x00, 0x01, 0x02, 0x03, 0x10, 0x11, 0x12, 0x13)
    if op == 0x11 or op == 0x12:                  # bc1x / bc2x
        return ((w >> 21) & 0x1F) == 0x08
    return op in (0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17)


def code_end(data: bytes, base: int, a: int, b: int) -> int:
    """b less the zero fill after the function, keeping a nop that sits in
    the delay slot of its last jump."""
    while b > a and struct.unpack_from("<I", data, b - 4 - base)[0] == 0:
        if b - 8 >= a and is_jump(struct.unpack_from("<I", data, b - 8 - base)[0]):
            break
        b -= 4
    return b


def funcs_in(text: bytes, base: int, starts: list[int], lo: int, hi: int):
    """(start, end) of each function in [lo, hi): end is the next start, less
    trailing nops."""
    starts = sorted(s for s in set(starts) if lo <= s < hi) + [hi]
    for a, b in zip(starts, starts[1:]):
        b = code_end(text, base, a, b)
        if b > a:
            yield a, b


def words_of(text: bytes, base: int, a: int, b: int) -> list[int]:
    return list(struct.unpack_from("<%dI" % ((b - a) // 4), text, a - base))


def jal_targets(text: bytes, base: int, lo: int, hi: int) -> set[int]:
    out = set()
    for k in range((hi - lo) // 4):
        w = struct.unpack_from("<I", text, lo - base + 4 * k)[0]
        if w >> 26 == 3:
            out.add(((w & 0x3FFFFFF) << 2) | (lo & 0xF0000000))
    return out


# --------------------------------------------------------------------------- build

def kfiv_funcs(hl: Path):
    """KFIV functions holyland has C for. Those are game code wherever they
    sit: KFIV links FromSoftware's memory-card module (Mc_*) after the SDK, so
    an address range would miss it. Every other named function counts as SDK
    (its jal keeps the callee's name)."""
    base, text = kfiv_text()
    end = base + len(text)
    syms = read_syms(hl / "config/symbol_addrs.txt")
    by_name = {v: k for k, v in syms.items()}
    srcs = holyland_sources(hl)
    named = {}
    for name, path in srcs.items():
        m = re.fullmatch(r"(?:func|[A-Za-z]\w*?_[0-5])_([0-9A-F]{8})", name)
        addr = int(m.group(1), 16) if m else by_name.get(name)
        if addr and KFIV_GAME[0] <= addr < end:
            named[addr] = (name, path)
    starts = set(syms) | set(named) | jal_targets(text, base, KFIV_GAME[0], end)
    sdk = {a: n for a, n in syms.items() if n not in srcs}
    out = []
    for a, b in funcs_in(text, base, list(starts), KFIV_GAME[0], end):
        if a in named:
            name, path = named[a]
            out.append((a, b - a, name, path, tokens(words_of(text, base, a, b), a, sdk)))
    return out


def sta_funcs():
    rom = STA_ROM.read_bytes()
    base = 0x00100000
    starts = []
    names = {}
    for f in (ROOT / "asm").glob("*.s"):
        for m in re.finditer(r"^glabel (\S+)\n(?:nonmatching.*\n|\s*\n)*\s*/\* [0-9A-F]+ ([0-9A-F]{8})",
                             f.read_text(), re.M):
            starts.append(int(m.group(2), 16))
    for p in ("config/symbol_addrs.txt", "config/symbol_addrs.carve.txt"):
        names.update(read_syms(ROOT / p))
    sdk = {a: n for a, n in names.items() if a < STA_GAME[0]}
    out = []
    for a, b in funcs_in(rom, base, starts + [STA_GAME[0]], *STA_GAME):
        mod = "ee" if any(lo <= a < hi for lo, hi in STA_EE) else "mw"
        out.append((a, b - a, mod, tokens(words_of(rom, base, a, b), a, sdk)))
    return out


def grams(t: list[str], n: int = 4) -> set:
    return {tuple(t[i:i + n]) for i in range(len(t) - n + 1)} or {tuple(t)}


def score(sa: list[str], ka: list[str]) -> float:
    if not sa or not ka:
        return 0.0
    r = difflib.SequenceMatcher(None, sa, ka, autojunk=False).ratio()
    calls_s = Counter(t for t in sa if t.startswith("jal:"))
    calls_k = Counter(t for t in ka if t.startswith("jal:"))
    if calls_s or calls_k:
        inter = sum((calls_s & calls_k).values())
        union = sum((calls_s | calls_k).values())
        r = 0.8 * r + 0.2 * inter / union
    ln = min(len(sa), len(ka)) / max(len(sa), len(ka))
    return r * (0.7 + 0.3 * ln)


def rank(hl: Path, top: int, min_len: int):
    kf = kfiv_funcs(hl)
    sb = sta_funcs()
    print(f"KFIV: {len(kf)} functions with holyland C; sta: {len(sb)} game functions", file=sys.stderr)
    index = defaultdict(list)
    kgrams = []
    for i, (_, _, _, _, t) in enumerate(kf):
        g = grams(t)
        kgrams.append(g)
        for x in g:
            index[x].append(i)
    rows = []
    for a, size, mod, t in sb:
        if len(t) < min_len:
            continue
        g = grams(t)
        hits = Counter()
        for x in g:
            lst = index.get(x)
            if lst and len(lst) < 400:     # very common 4-grams say nothing
                hits.update(lst)
        cands = [i for i, _ in hits.most_common(25)]
        best = []
        for i in cands:
            kt = kf[i][4]
            if not 0.4 <= len(t) / max(len(kt), 1) <= 2.5:
                continue
            best.append((score(t, kt), i))
        best.sort(reverse=True)
        for s, i in best[:top]:
            ka, ksize, kname, kpath, _ = kf[i]
            rows.append((s, a, size, mod, ka, kname, kpath))
    rows.sort(key=lambda r: -r[0])
    OUT.parent.mkdir(parents=True, exist_ok=True)
    with open(OUT, "w") as f:
        f.write("score\tsta\tsize\tmodule\tkfiv\tname\tsource\n")
        for s, a, size, mod, ka, kname, kpath in rows:
            f.write(f"{s:.3f}\t{a:#010x}\t{size:#x}\t{mod}\t{ka:#010x}\t{kname}\t{kpath.relative_to(hl)}\n")
    print(f"wrote {OUT.relative_to(ROOT)} ({len(rows)} pairs)", file=sys.stderr)
    for s, a, size, mod, ka, kname, kpath in rows[:40]:
        print(f"{s:.3f}  {a:#010x} {size:#6x} {mod}  <- {kname} ({kpath.relative_to(hl)})")


def show(hl: Path, sta_addr: int, kname: str):
    kf = {k[2]: k for k in kfiv_funcs(hl)}
    sb = {s[0]: s for s in sta_funcs()}
    if kname not in kf or sta_addr not in sb:
        sys.exit("unknown function")
    kt, st = kf[kname][4], sb[sta_addr][3]
    print(f"score {score(st, kt):.3f}: sta {sta_addr:#x} ({len(st)} tokens) vs {kname} ({len(kt)} tokens)")
    sm = difflib.SequenceMatcher(None, st, kt, autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        a, b = st[i1:i2], kt[j1:j2]
        for k in range(max(len(a), len(b))):
            l = a[k] if k < len(a) else ""
            r = b[k] if k < len(b) else ""
            print(f"  {'=' if tag == 'equal' else '|'} {l:22s} {r}")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--holyland", default=os.environ.get("HOLYLAND", str(Path.home() / "code/holyland/decomp")))
    ap.add_argument("--top", type=int, default=1, help="KFIV candidates kept per sta function")
    ap.add_argument("--min-len", type=int, default=6, help="skip sta functions with fewer tokens")
    ap.add_argument("--show", nargs=2, metavar=("STA_ADDR", "KFIV_NAME"))
    args = ap.parse_args()
    hl = Path(args.holyland)
    if args.show:
        show(hl, int(args.show[0], 0), args.show[1])
    else:
        rank(hl, args.top, args.min_len)


if __name__ == "__main__":
    main()
