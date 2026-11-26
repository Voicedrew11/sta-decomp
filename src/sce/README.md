# src/sce: Sony SDK and compiler runtime libraries

Sony's EE libraries (libkernl, libgraph, libdev, libipu, libmpeg, libcdvd,
...) and the compiler install's newlib libc, libm and libgcc, as linked into
`SLPS_252.17`.

The sources come from the ICO decompilation
([nathanialf/ico](https://github.com/nathanialf/ico), MIT, © the ico
decompilation contributors; notice in [`tools/LICENSE.ico`](../../tools/LICENSE.ico)),
by way of kfiv-decomp, whose additions are marked `KFIV:`. Comments that give
addresses or link positions describe ICO's or KFIV's build, not this one.
Changes for Shadow Tower Abyss are marked `STA:`.

ICO's sources are SDK 2.2.x; this game links SDK 2.5.0.0 libraries (built
with ee-gcc 2.9-ee-991111-01) and a libc/libm/libgcc built with ee-gcc 2.96.
Only the members that compile to this ELF's bytes as a whole are here; the
rest are still asm. Members kfiv-decomp lacks (libsdr, several newlib libc
and libm members) were written from this game's bytes, and libmpeg is
kfiv-decomp's SDK 2.2 source converted to SDK 2.5 (its globals moved into the
decoder record). Headers for members not here stay, since the other members
include them.

Every `.c` and `.s` here is a translation unit of the build. `tools/carve.py`
compiles them, finds where each one sits in the retail ELF and writes the
splat subsegments, the link order and `config/symbol_addrs.carve.txt` from
that. A file that does not match the retail bytes as a whole stops it.

## Temporary inline asm (to be removed)

Four functions are retail's instructions in a top-level `__asm__` block until
their C matches. Each is marked `TODO(STA): TEMPORARY inline asm` with its C
attempt kept beside it, under `#if 0` or in a comment, for the next attempt.
`tools/asm2inline.py` generated the blocks. Delete the asm, and the `#if 0`,
once the C compiles to the same bytes:

| Function | File | What is left |
| --- | --- | --- |
| `_vfprintf_r` | `libc/stdio/vfprintf.c` | Retail has nops before case labels and copies `ap` to a register, likely a different compiler for this one function. The asm block also carries the function's `.rodata` (strings and jump table). |
| `sceGsSetDefDispEnv` | `libgraph/graph003.c` | About 47 words of register and scheduling differences in the display-register arithmetic. |
| `__ieee754_sqrtf` | `libm/math/ef_sqrt.c` | 8 words of instruction ordering. |
| `_sendRefTags` | `libmpeg/mpc.c` | gcc allocates `i` and `tag` to each other's registers. |
