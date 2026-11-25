#!/usr/bin/env python3
"""Which compiler and flags reproduce the retail code?

    tools/probe_compiler.py            every candidate, a table of matches
    tools/probe_compiler.py -v         also the differing words per function

tools/probes/mw*.c hold game functions written in C, compiled with every
mwccps2 build in tools/cc/ at several optimisation levels; tools/probes/ee.c
holds functions of the gcc-built game modules, compiled with ee-gcc 2.9 and
2.96 with and without -fno-strict-aliasing. Each func_XXXXXXXX in the object
is compared with the retail bytes at XXXXXXXX, relocated bits masked. The
objects go to build/probe/.

The result recorded in docs/ROADMAP.md: the game is mwccps2 3.0b38, 3.0b50
or 3.0b52 at -O4,p (all probes match under each; b50 and b52 produce the
same code on everything tried), and the gcc modules are ee-gcc 2.96 -O2
-G 8 -fno-strict-aliasing.
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = Path(__file__).resolve().parent.parent
CC = ROOT / "tools/cc"
OUT = ROOT / "build/probe"
PROBES = ROOT / "tools/probes"
MASK = {4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000, 7: 0xFFFF0000}   # R_26, HI16, LO16, GPREL16
MW_FLAGS = ["-O4,p", "-O4,s", "-O3", "-O2"]
EE_FLAGS = ["-O2 -G 8", "-O2 -G 8 -fno-strict-aliasing"]


def compare(obj: Path, rom: bytes, verbose: bool) -> dict:
    """func name -> number of differing words (0 = match)."""
    e = ELFFile(open(obj, "rb"))
    secs = list(e.iter_sections())
    masks = {}
    for s in secs:
        if isinstance(s, RelocationSection):
            for r in s.iter_relocations():
                masks[(s["sh_info"], r["r_offset"] & ~3)] = MASK.get(r["r_info_type"], 0)
    out = {}
    for sym in e.get_section_by_name(".symtab").iter_symbols():
        m = re.fullmatch(r"func_([0-9A-F]{8})", sym.name)
        if not m or sym["st_info"]["type"] != "STT_FUNC":
            continue
        si = sym["st_shndx"]       # CodeWarrior gives each function its own .text
        data = secs[si].data()
        off = sym["st_value"]
        end = off + (sym["st_size"] or len(data) - off)
        base = int(m.group(1), 16) - 0x100000
        bad = []
        for k in range(off, end, 4):
            w = struct.unpack_from("<I", data, k)[0]
            rw = struct.unpack_from("<I", rom, base + k - off)[0]
            if (w ^ rw) & masks.get((si, k), 0xFFFFFFFF):
                bad.append(f"+{k - off:#x} {w:08x}/{rw:08x}")
        out[sym.name] = len(bad)
        if verbose and bad:
            print(f"      {sym.name}: {' '.join(bad[:6])}")
    return out


def mw(build: str, flags: str, src: Path, obj: Path) -> bool:
    cmd = [str(CC / "wibo"), str(CC / build / "mwccps2.exe"), "-c", *flags.split(), "-o", str(obj), str(src)]
    r = subprocess.run(cmd, capture_output=True, env={"MWCIncludes": str(ROOT / "include")})
    return r.returncode == 0


def ee(gcc: str, flags: str, src: Path, obj: Path) -> bool:
    if gcc == "2.9":
        d = CC / "ee-gcc2.9-991111-01"
        drv = [str(d / "ee-gcc"), "-B", str(d / "gcc-lib/ee/2.9-ee-991111-01") + "/"]
    else:
        d = CC / "ee-gcc2.96"
        drv = [str(d / "bin/gcc"), "-B", str(d / "gcc-lib/ee/2.96-ee-001003-1") + "/"]
    env = ROOT / "tools/period_env.sh"
    s = obj.with_suffix(".s")
    r = subprocess.run([str(env), *drv, "-S", *flags.split(), "-mips3", "-EL", "-o", str(s), str(src)],
                       capture_output=True)
    if r.returncode:
        return False
    r = subprocess.run([str(env), str(CC / "ee-gcc2.96/bin/as"), "-EL", "-mcpu=5900", "-mabi=eabi",
                        "-G", "8", "-o", str(obj), str(s)], capture_output=True)
    return r.returncode == 0


def defined(src: Path) -> int:
    """Functions a probe file defines (a definition starts in column 0)."""
    return sum(1 for l in src.read_text().splitlines()
               if re.match(r"[A-Za-z].*\bfunc_[0-9A-F]{8}\(", l) and not l.rstrip().endswith(");"))


def row(label: str, results: dict, total: int) -> None:
    ok = sum(1 for v in results.values() if v == 0)
    miss = " ".join(f"{n[5:]}({v})" for n, v in sorted(results.items()) if v)
    print(f"  {label:34s} {ok:2d}/{total}  {miss}")


def main() -> None:
    verbose = "-v" in sys.argv
    rom = (ROOT / "baserom/jp/sta.rom").read_bytes()
    OUT.mkdir(parents=True, exist_ok=True)
    mw_srcs = sorted(PROBES.glob("mw*.c"))
    builds = sorted(p.name for p in CC.glob("mwcps2-*") if (p / "mwccps2.exe").exists())
    mw_total = sum(defined(src) for src in mw_srcs)
    print("CodeWarrior (tools/probes/mw*.c):")
    for b in builds:
        for fl in MW_FLAGS:
            res = {}
            for src in mw_srcs:
                obj = OUT / f"{src.stem}_{b}_{re.sub(r'[^A-Za-z0-9]', '_', fl)}.o"
                if mw(b, fl, src, obj):
                    res.update(compare(obj, rom, verbose))
            row(f"{b} {fl}", res, mw_total)
    src = PROBES / "ee.c"
    total = defined(src)
    print("ee-gcc (tools/probes/ee.c):")
    for g in ("2.9", "2.96"):
        for fl in EE_FLAGS:
            obj = OUT / f"ee_{g}_{re.sub(r'[^A-Za-z0-9]', '_', fl)}.o"
            res = compare(obj, rom, verbose) if ee(g, fl, src, obj) else {}
            row(f"ee-gcc {g} {fl}", res, total)


if __name__ == "__main__":
    main()
