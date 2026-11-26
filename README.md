# sta-decomp

A matching decompilation of **Shadow Tower Abyss** (FromSoftware, 2003) for the
PlayStation 2. The target is the Japanese retail boot ELF, `SLPS_252.17`
(SLPS-25217). The goal is C source that the original toolchain compiles back
into the identical executable.

**Status:** the build reproduces the retail ROM image (all bytes the console
loads) **byte for byte**. 71 SDK, libc, libm and libgcc units build from C
and hand-written asm (`src/sce/`, about 26 KB of `.text`); the rest of the
libraries and the whole game are still splat-disassembled assembly. See
[`docs/ROADMAP.md`](docs/ROADMAP.md).

> No disc data is in this repository. You supply your own disc image; the
> build extracts the ELF from it and checks its SHA-1.

## Quickstart

```sh
mkdir -p baserom
ln -s "/path/to/Shadow Tower Abyss (Japan).iso" baserom/sta_jp.iso
./build.sh
```

`build.sh` runs whatever is missing:

1. `tools/setup.sh` creates `.venv`, fetches the compilers and wibo into
   `tools/cc/`, builds GNU ld 2.10 and dvp-as from source, and fetches
   objdiff-cli.
2. `tools/extract_elf.py` writes `baserom/jp/SLPS_252.17` and
   `baserom/jp/sta.rom` (the ELF's load segment) and checks both SHA-1s.
3. `tools/split.py` runs splat and writes `asm/`.
4. `tools/gen_ninja.py` and `ninja` assemble, compile and link with ld 2.10,
   then check the ROM SHA-1.

Host requirements: 64-bit Linux with 32-bit glibc (the ee-gcc tools are i386
binaries), a host gcc with `-m32` support, flex, bison, curl, git and Python 3.
Arch: `sudo pacman -S lib32-glibc lib32-gcc-libs flex bison`.

| file | SHA-1 |
| --- | --- |
| `SLPS_252.17` | `453dec1fb7f64de7cc6b08cc15719b1266231d59` |
| `sta.rom` (non-empty PT_LOAD bytes, i.e. `objcopy -O binary`) | `e2742b309441802b4a6809a346760a2dfcc6fd4d` |

## Progress

`ninja build/report.json` runs objdiff-cli over every unit (`objdiff.json`,
written by `tools/gen_ninja.py`, one unit per link-order entry in the
categories `game` and `sce`); C units get a target object assembled from
splat's per-function asm of the retail code, so the objdiff GUI also works on
this checkout. `ninja progress` prints the summary and writes
`build/progress.html`, a local per-function page (not committed).
`tools/progress.py --write` refreshes `docs/progress/` (a summary without
per-function data, shields badges and a static page) and the table below;
commit those with each batch of work. The disc is needed to build, so CI
cannot produce the report.

<!-- progress:start -->
| | code | functions | units complete |
| --- | ---: | ---: | ---: |
| overall | 62.06% | 2046 / 3090 | 7 / 2228 |
| game | 71.45% | 1895 / 2223 | 0 / 2108 |
| sce | 16.03% | 151 / 867 | 7 / 120 |
<!-- progress:end -->

## Adding library units

Put the source under `src/sce/<lib>/` and run `tools/carve.py --check`: it
compiles every unit, places it in the retail ELF (`tools/lib_layout.py`) and
stops on anything that does not match as a whole. `tools/carve.py` then
rewrites the splat subsegments in `config/sta.jp.yaml`,
`config/link_order.jp.txt` and `config/symbol_addrs.carve.txt`; delete `asm/`
and run `./build.sh` to re-split and check the ROM.

## Toolchain

Unlike King's Field IV (ee-gcc 2.9), the game is built with **Metrowerks
CodeWarrior for PS2** and linked with `mwldps2`, which wrote the ELF as one
PROGBITS blob with no section table. Three of the game's modules were built
with ee-gcc instead, and the Sony libraries are Sony's own ee-gcc builds.
`tools/probe_compiler.py` checks these choices against the retail code.

| tool | role |
| --- | --- |
| mwccps2 3.0b52-030722 `-O4,p` (or 3.0b38/b50: they match the same) | compiles the game |
| ee-gcc 2.96-ee-001003-1 `-O2 -G 8 -fno-strict-aliasing` | compiled the game's three gcc modules (`src/game/ee/`) |
| ee-gcc 2.9-ee-991111-01 | compiled Sony's SDK 2.5 libraries |
| ee-gcc 2.96-ee-001003-1 | compiled libc, libm and libgcc |
| SCE ee-as 2.10-ee-001003-1 (from ee-gcc 2.96) | assembles splat's asm and the ee-gcc output |
| GNU ld 2.10 + R5900/DVP patches | links (the ROM image does not depend on mwldps2) |
| wibo | runs the Win32 CodeWarrior tools |

SDK library versions in the binary: libkernl, libcdvd, libmc, libpad, libipu,
libgraph, libdma and libsdr, all 2.5.0.0. More than 540 library functions
compiled from ICO's reconstructed sources (SDK 2.2.x) are **byte-identical**
to code in this ELF and are named in `config/symbol_addrs.txt`.

## Layout

```
config/    splat yaml, symbol_addrs.txt (+ .carve.txt, generated),
           link_order.jp.txt (generated), linker-script template,
           linker_syms.txt, sha1sums.txt
include/   macro.inc (splat asm macros for the period assembler)
src/       C sources as they are decompiled (src/sce/ for SDK libraries)
tools/     setup, extraction, split, build generation and check scripts
wip/       near-misses and inline-asm matches, kept out of the build
docs/      roadmap and notes
asm/  baserom/  build/  tools/cc/  .venv/    generated or local, gitignored
```

## Credits and licence

About 780 of the game's matched functions, the shared game types in
`include/` and `docs/MATCHING.md` come from KiskarFisk's
[shadow-tower-abyss](https://github.com/KiskarFisk/shadow-tower-abyss)
(made on the English-patched ELF, whose code is the same as retail), merged
with its history.

The binutils patches, the obstack shim (`tools/period_obstack.c`) and the
toolchain recipe come from the ico decompilation (MIT, © the ico
decompilation contributors; notice in [`tools/LICENSE.ico`](tools/LICENSE.ico)),
by way of kfiv-decomp. This project has no affiliation with FromSoftware or
Sony Interactive Entertainment.
