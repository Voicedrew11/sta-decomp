#!/usr/bin/env python3
"""Split a CodeWarrior object at its INCLUDE_ASM markers (include/include_asm.h).

    tools/include_asm.py file.o        in place; run by tools/compile_c.sh
    tools/include_asm.py --names file.c

CodeWarrior writes each function to a .text section of its own, in source
order. The section of each marker function __include_asm_<name> becomes
.text.iastub (the link discards it) and every .text section after the Nth
marker .text.iaN, so the link script can put the asm chunk of <name> between
unit(.text...) and unit(.text.iaN). Only section names change: a new
section-name table is appended and the headers point at it.

--names prints the INCLUDE_ASM names of a source, in order.
"""
import re
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

MARK = "__include_asm_"
USE = re.compile(r"^\s*INCLUDE_ASM\(\s*(\w+)\s*\)\s*;", re.M)


def names(src: str) -> list[str]:
    return USE.findall(Path(src).read_text())


def split(path: Path) -> int:
    data = bytearray(path.read_bytes())
    with open(path, "rb") as f:
        elf = ELFFile(f)
        marks = {s["st_shndx"] for s in elf.get_section_by_name(".symtab").iter_symbols()
                 if s.name.startswith(MARK) and isinstance(s["st_shndx"], int)}
        if not marks:
            return 0
        new_names, k = {}, 0
        for i, s in enumerate(elf.iter_sections()):
            if s.name != ".text":
                continue
            if i in marks:
                k += 1
                new_names[i] = ".text.iastub"
            elif k:
                new_names[i] = f".text.ia{k}"
        shoff, shentsize = elf["e_shoff"], elf["e_shentsize"]
        shstr = elf.get_section(elf["e_shstrndx"])
        old = shstr.data()
        str_hdr = shoff + elf["e_shstrndx"] * shentsize
    table = bytearray(old)
    for i, name in new_names.items():
        struct.pack_into("<I", data, shoff + i * shentsize, len(table))
        table += name.encode() + b"\0"
    struct.pack_into("<II", data, str_hdr + 16, len(data), len(table))   # sh_offset, sh_size
    data += table
    path.write_bytes(data)
    return k


def main() -> None:
    if sys.argv[1:2] == ["--names"]:
        print(" ".join(names(sys.argv[2])))
        return
    split(Path(sys.argv[1]))


if __name__ == "__main__":
    main()
