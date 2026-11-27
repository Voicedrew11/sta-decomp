#!/usr/bin/env python3
"""objdiff's base object for a CodeWarrior game unit.

    tools/objdiff_base.py BASE.o TARGET.o OUT.o

CodeWarrior puts each jump table, string and constant in a .rodata (or .data,
.sdata, ...) section of its own, under a compiler-local name (@123). The
target object (build/target/) has one section per kind, as retail lays the
unit out, with splat's names (jtbl_/D_ + address). objdiff pairs data by
symbol name within a section, so none of it pairs.

OUT is BASE relinked with `ld -r`, which merges the same-named sections in
file order (as the final link lays them out), and with each @-local data
symbol renamed to the target symbol at the same section offset. The linked
object (BASE) is untouched; OUT is only for objdiff.

CodeWarrior's jump tables also relocate against the function symbol, where
the target's .L labels assemble to relocations against the .text section
symbol; OUT's are moved to the section symbol (the function's offset added
to the stored word, as the relocations are REL), so they pair.
"""
import struct
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
LD = ROOT / "tools/cc/binutils-2.10-ee/bin/ld"
DATA = (".rodata", ".data", ".sdata", ".sbss", ".bss")


def data_syms(path: Path) -> dict:
    """(section name, offset) -> name, for the defined symbols in data sections."""
    out = {}
    with open(path, "rb") as f:
        elf = ELFFile(f)
        for sym in elf.get_section_by_name(".symtab").iter_symbols():
            ndx = sym["st_shndx"]
            if not isinstance(ndx, int) or sym["st_info"]["type"] in ("STT_SECTION", "STT_FILE"):
                continue
            sec = elf.get_section(ndx).name
            if sec in DATA and sym.name:
                out.setdefault((sec, sym["st_value"]), sym.name)
    return out


def rename(path: Path, names: dict) -> None:
    """Rename symbols in place: a new .strtab is appended to the file."""
    data = bytearray(path.read_bytes())
    with open(path, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        strtab_idx = symtab["sh_link"]
        old = elf.get_section(strtab_idx).data()
        sh_off, sh_size = elf["e_shoff"], elf["e_shentsize"]
        sym_off, sym_size = symtab["sh_offset"], symtab["sh_entsize"]
        count = symtab.num_symbols()
    new = bytearray(old)
    for i in range(count):
        o = sym_off + i * sym_size
        st_name = struct.unpack_from("<I", data, o)[0]
        cur = old[st_name:old.index(b"\0", st_name)].decode()
        if cur in names:
            struct.pack_into("<I", data, o, len(new))
            new += names[cur].encode() + b"\0"
    # point the string table's section header at the appended copy
    hdr = sh_off + strtab_idx * sh_size
    struct.pack_into("<II", data, hdr + 16, len(data), len(new))  # sh_offset, sh_size
    data += new
    path.write_bytes(data)


def section_relative(path: Path) -> None:
    """Data relocations against a .text symbol -> against the .text section symbol."""
    data = bytearray(path.read_bytes())
    with open(path, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        syms = list(symtab.iter_symbols())
        text = elf.get_section_by_name(".text")
        if text is None:
            return
        tidx = next(i for i, s in enumerate(elf.iter_sections()) if s.name == ".text")
        secsym = next((i for i, s in enumerate(syms)
                       if s["st_info"]["type"] == "STT_SECTION" and s["st_shndx"] == tidx), None)
        if secsym is None:
            return
        for rel in elf.iter_sections():
            if rel["sh_type"] != "SHT_REL":
                continue
            target = elf.get_section(rel["sh_info"])
            if target.name not in DATA:
                continue
            for i, r in enumerate(rel.iter_relocations()):
                s = syms[r["r_info_sym"]]
                if r["r_info_type"] != 2 or s["st_shndx"] != tidx or r["r_info_sym"] == secsym:
                    continue    # R_MIPS_32 only
                o = rel["sh_offset"] + i * rel["sh_entsize"]
                struct.pack_into("<I", data, o + 4, (secsym << 8) | 2)
                w = target["sh_offset"] + r["r_offset"]
                v = struct.unpack_from("<I", data, w)[0]
                struct.pack_into("<I", data, w, (v + s["st_value"]) & 0xFFFFFFFF)
            # CodeWarrior writes relocations in descending address order;
            # objdiff looks them up as if they were ascending
            n, es, base = rel.num_relocations(), rel["sh_entsize"], rel["sh_offset"]
            ents = sorted((bytes(data[base + i * es:base + (i + 1) * es]) for i in range(n)),
                          key=lambda e: struct.unpack_from("<I", e)[0])
            data[base:base + n * es] = b"".join(ents)
    path.write_bytes(data)


def main() -> None:
    base, target, out = map(Path, sys.argv[1:4])
    out.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([str(LD), "-r", "-o", str(out), str(base)], check=True)
    want = data_syms(target)
    names = {}
    for key, name in data_syms(out).items():
        if name.startswith("@") and key in want:
            names[name] = want[key]
    if names:
        rename(out, names)
    section_relative(out)


if __name__ == "__main__":
    main()
