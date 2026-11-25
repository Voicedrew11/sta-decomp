#!/usr/bin/env python3
"""Extract the boot ELF from the user's Shadow Tower Abyss disc.

    tools/extract_elf.py [path/to/disc.iso]

Writes baserom/jp/SLPS_252.17 (the ELF, unchanged) and baserom/jp/sta.rom
(the bytes of its one non-empty PT_LOAD segment, i.e. `objcopy -O binary`), then checks
both against config/sha1sums.txt. Default image: baserom/sta_jp.iso.
"""
import hashlib
import io
import struct
import sys
from pathlib import Path

import pycdlib

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "baserom" / "jp"
ELF_NAME = "SLPS_252.17"


def sha1(b: bytes) -> str:
    return hashlib.sha1(b).hexdigest()


def load_sums() -> dict:
    sums = {}
    for line in (ROOT / "config" / "sha1sums.txt").read_text().splitlines():
        line = line.split("#", 1)[0].strip()
        if line:
            digest, name = line.split()
            sums[name] = digest
    return sums


def rom_view(elf: bytes) -> bytes:
    """The PT_LOAD segment's file bytes (what objcopy -O binary writes)."""
    phoff, = struct.unpack_from("<I", elf, 0x1C)
    phnum, = struct.unpack_from("<H", elf, 0x2C)
    loads = []
    for i in range(phnum):
        p_type, p_off, _vaddr, _paddr, p_filesz = struct.unpack_from("<5I", elf, phoff + 32 * i)
        # the retail ELF has a second, empty PT_LOAD at the end of .bss
        if p_type == 1 and p_filesz:
            loads.append((p_off, p_filesz))
    if len(loads) != 1:
        sys.exit(f"expected one non-empty PT_LOAD segment, found {len(loads)}")
    off, size = loads[0]
    return elf[off:off + size]


def main() -> None:
    iso_path = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / "baserom" / "sta_jp.iso"
    if not iso_path.exists():
        sys.exit(f"disc image not found: {iso_path}")
    iso = pycdlib.PyCdlib()
    iso.open(str(iso_path))
    files = {}
    for name in (ELF_NAME, "SYSTEM.CNF"):
        buf = io.BytesIO()
        iso.get_file_from_iso_fp(buf, iso_path=f"/{name};1")
        files[name] = buf.getvalue()
    iso.close()
    files["sta.rom"] = rom_view(files[ELF_NAME])

    sums = load_sums()
    OUT.mkdir(parents=True, exist_ok=True)
    ok = True
    for name, data in files.items():
        (OUT / name).write_bytes(data)
        want = sums.get(name)
        got = sha1(data)
        status = "OK" if want == got else ("UNCHECKED" if want is None else "MISMATCH")
        ok &= status != "MISMATCH"
        print(f"{status:9s} {got}  baserom/jp/{name}")
    if not ok:
        sys.exit("SHA-1 mismatch: this is not the Japanese retail disc (SLPS-25217)")


if __name__ == "__main__":
    main()
