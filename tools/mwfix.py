#!/usr/bin/env python3
"""Make a CodeWarrior object readable by GNU ld 2.10.

    tools/mwfix.py file.o

mwccps2 writes a `.mwcats` section (code-analysis data for its own linker)
of type SHT_LOUSER + 0x4A2A82C2. BFD 2.10 refuses any object holding a
section type it does not know ("file format not recognized"), so the
section's type becomes SHT_PROGBITS; it is not allocated, and the linker
script discards it. No code or data byte changes.
"""
import struct
import sys

SHT_PROGBITS = 1
SHT_LOUSER = 0x80000000


def fix(path: str) -> int:
    data = bytearray(open(path, "rb").read())
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 1:
        sys.exit(f"{path}: not a little-endian ELF32 object")
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    str_off, = struct.unpack_from("<I", data, shoff + shstrndx * shentsize + 0x10)
    changed = 0
    for i in range(shnum):
        hdr = shoff + i * shentsize
        name, typ = struct.unpack_from("<II", data, hdr)
        sname = data[str_off + name:data.index(0, str_off + name)].decode()
        if typ >= SHT_LOUSER:
            if not sname.startswith(".mwcats"):
                sys.exit(f"{path}: unexpected user section type {typ:#x} on {sname}")
            struct.pack_into("<I", data, hdr + 4, SHT_PROGBITS)
            changed += 1
    if changed:
        open(path, "wb").write(data)
    return changed


if __name__ == "__main__":
    for p in sys.argv[1:]:
        fix(p)
