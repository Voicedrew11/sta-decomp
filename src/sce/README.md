# src/sce: Sony SDK and compiler runtime libraries

Sony's EE libraries (libkernl, libgraph, libdev, libipu, libmpeg, libcdvd,
...) and the compiler install's newlib libc, libm and libgcc, as linked into
`SLPS_252.17`.

The sources come from the ICO decompilation
([nathanialf/ico](https://github.com/nathanialf/ico), MIT, © the ico
decompilation contributors; notice in [`tools/LICENSE.ico`](../../tools/LICENSE.ico)),
by way of kfiv-decomp, whose additions are marked `KFIV:`. Comments that give
addresses or link positions describe ICO's or KFIV's build, not this one.
Changes for Shadow Tower Abyss are marked `SAB:`.

ICO's sources are SDK 2.2.x; this game links SDK 2.5.0.0 libraries (built
with ee-gcc 2.9-ee-991111-01) and a libc/libm/libgcc built with ee-gcc 2.96.
Only the members that compile to this ELF's bytes as a whole are here (71 of
kfiv-decomp's 183); the rest are still asm. Headers for members not here stay,
since the other members include them.

Every `.c` and `.s` here is a translation unit of the build. `tools/carve.py`
compiles them, finds where each one sits in the retail ELF and writes the
splat subsegments, the link order and `config/symbol_addrs.carve.txt` from
that. A file that does not match the retail bytes as a whole stops it.
