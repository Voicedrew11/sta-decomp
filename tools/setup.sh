#!/usr/bin/env bash
# =============================================================================
# tools/setup.sh — one-shot, idempotent host setup.
#
#   1. Python venv at .venv with tools/requirements.txt.
#   2. Compilers from decompme/compilers into tools/cc/:
#        mwcps2-*                 Metrowerks CodeWarrior for PS2 (the game);
#                                 every build dated before the game shipped,
#                                 since which one was used is still open
#        ee-gcc 2.9-ee-991111-01  its ee-as 2.9 assembles splat's output
#        ee-gcc 2.96-ee-001003-1  the SCE toolchain of SDK 2.5's era, for the
#                                 Sony libraries
#   3. wibo (pinned release binary) to run the Win32 CodeWarrior tools.
#   4. GNU ld 2.10 (+ R5900/DVP patches) and dvp-as, built from public source.
#   5. objdiff-cli (pinned release binary) for the objdiff progress reports.
#
# The binutils patches and the obstack shim come from the ico decompilation
# (github.com/nathanialf/ico, MIT), by way of kfiv-decomp.
#
# Nothing downloaded here is game data.  SKIP_TOOLCHAIN=1 skips steps 2-5.
# =============================================================================
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

PYTHON="${PYTHON:-python3}"
VENV="${VENV:-.venv}"
CC_DIR="$ROOT/tools/cc"
CCSRC="$CC_DIR/src"
# binutils' autoconf trees and LD_PRELOAD (tools/period_env.sh) both break on
# paths with spaces.
case "$ROOT" in *" "*) echo "==> the checkout path must not contain spaces: $ROOT" >&2; exit 1 ;; esac

echo "==> sta setup at $ROOT"

# --- 1. Python venv ----------------------------------------------------------
if [[ ! -d "$VENV" ]]; then
    echo "==> creating venv at $VENV"
    "$PYTHON" -m venv "$VENV"
fi
"$VENV/bin/python" -m pip install -q --upgrade pip
"$VENV/bin/python" -m pip install -q -r tools/requirements.txt

[[ "${SKIP_TOOLCHAIN:-0}" == "1" ]] && { echo "==> SKIP_TOOLCHAIN=1; done"; exit 0; }

# --- 2. Compilers ------------------------------------------------------------
DECOMPME="https://github.com/decompme/compilers/releases/download/compilers"
# name sha256 (of the release asset)
COMPILERS=(
    "ee-gcc2.9-991111-01.tar.xz    ed684fd98f89d36b0121caab311052089103e3b36241fcef4338cc9ea41c75b8"
    "ee-gcc2.96.tar.xz             0590d2ca9da8f5903889d66761220d14b47a8d14ba987ca53db84a1650a1fd0a"
    "mwcps2-2.3.3-000906.tar.gz    c2a4e463f8f7b324350d6bfb26d6daed83f4d5cb46df8b20dcfec8617b22ad5d"
    "mwcps2-2.4-001213.tar.gz      0ebe09436b4163c3a109b0431517281501d2de1bd5a0b049d33057710a943e3e"
    "mwcps2-3.0-011126.tar.gz      b83fef398fd765aaeb48576dae0fa0751bf9c1496036d0d878e7a2a0e71c2a7f"
    "mwcps2-3.0.1-020123.tar.gz    72d823d85943c92ca13378e93d56ac1870298ccbfda0ef8a2efb9650692e968c"
    "mwcps2-3.0.3-020716.tar.gz    63f89baae691403294724178efbcfc9e1b9ac48151536b6a321b17eb8f9970e5"
    "mwcps2-3.0b38-030307.tar.gz   db3d0606c77d4335d2ad884a1285a4bc3b9e68cdd6161dd46d6e2a2cd3313276"
    "mwcps2-3.0.1b44-030325.tar.gz 90d99e3e6272369215b317548fe2626694aa1ead57cec0251f7343d266d9b0ed"
    "mwcps2-3.0.1b51-030512.tar.gz 985fce55737848ce46c145cd357df247a3cd12d1c944d8cc325cfe46cde5a124"
    "mwcps2-3.0b50-030527.tar.gz   74afc8c7cc13d129d3da205ebaed749a3f5eb789a321c7a669709f11d3d7c653"
    "mwcps2-3.0b52-030722.tar.gz   5c2f5f96c0a360cc6d4fc866226768f7ab9b290777bcd5cadeeba030b1d596a5"
    "mwcps2-3.0.1b74-030811.tar.gz 5c14bea69f68cf46498a4eab3e18ea89aff289e6e12c613c55ff2d05b06dd23c"
    "mwcps2-3.0.1b75-030916.tar.gz f665dc6ce76f3551097a87cd1c36672d93cd23b10021ca412fbd23d38e3444d8"
)
fetch_compiler() {
    local asset="$1" sha="$2" name dir tmp strip=0
    name="${asset%.tar.*}"; dir="$CC_DIR/$name"
    if [[ "$(cat "$dir/.stamp" 2>/dev/null)" == "$sha" ]]; then
        echo "==> $name already at $dir"; return 0
    fi
    echo "==> fetching $name"
    rm -rf "$dir"; mkdir -p "$dir"
    tmp="$dir.part"
    curl -fsSL -o "$tmp" "$DECOMPME/$asset" || { rm -rf "$dir" "$tmp"; echo "==> $name fetch failed" >&2; return 1; }
    echo "$sha  $tmp" | sha256sum -c --status || { rm -rf "$dir" "$tmp"; echo "==> $name sha256 mismatch" >&2; return 1; }
    # the ee-gcc archives have a top-level directory, the mwcps2 ones do not
    [[ "$name" == ee-gcc* ]] && strip=1
    tar -xf "$tmp" -C "$dir" --strip-components=$strip
    rm -f "$tmp"
    echo "$sha" > "$dir/.stamp"
}
for c in "${COMPILERS[@]}"; do fetch_compiler $c || exit 1; done

if ! "$CC_DIR/ee-gcc2.9-991111-01/bin/as" --version >/dev/null 2>&1; then
    cat >&2 <<'EOF'
==> ee-as is a 32-bit i386 binary and does not run on this host.
    Install 32-bit glibc (Arch: lib32-glibc; Fedora: glibc.i686 libstdc++.i686;
    Debian: libc6:i386 libstdc++6:i386) and re-run.
EOF
fi

# --- 3. wibo -----------------------------------------------------------------
WIBO_VERSION="1.2.0"
WIBO_BIN="$CC_DIR/wibo"
case "$(uname -m)" in
    x86_64) WIBO_ASSET="wibo-x86_64"; WIBO_SHA256="13f86a2d618f0dbe67179d349625345eabf9b46450295cb4c904e49f6aff85af" ;;
    i686)   WIBO_ASSET="wibo-i686";   WIBO_SHA256="2575d3b0a2f408b2c2b0850db56f1af5d005a138394a6774eba77b6708ecc304" ;;
    *)      WIBO_ASSET="" ;;
esac
fetch_wibo() {
    if [[ -z "$WIBO_ASSET" ]]; then
        echo "==> warning: no pinned wibo for $(uname -m); the CodeWarrior tools need wibo or wine" >&2
        return 0
    fi
    if [[ -x "$WIBO_BIN" && "$(cat "$WIBO_BIN.stamp" 2>/dev/null)" == "$WIBO_SHA256" ]]; then
        echo "==> wibo $WIBO_VERSION already at $WIBO_BIN"; return 0
    fi
    echo "==> fetching wibo $WIBO_VERSION ($WIBO_ASSET)"
    local tmp="$WIBO_BIN.part"
    curl -fsSL -o "$tmp" "https://github.com/decompals/wibo/releases/download/$WIBO_VERSION/$WIBO_ASSET" ||
        { rm -f "$tmp"; echo "==> wibo fetch failed" >&2; return 1; }
    echo "$WIBO_SHA256  $tmp" | sha256sum -c --status || { rm -f "$tmp"; echo "==> wibo sha256 mismatch" >&2; return 1; }
    chmod +x "$tmp"; mv -f "$tmp" "$WIBO_BIN"
    echo "$WIBO_SHA256" > "$WIBO_BIN.stamp"
}
fetch_wibo || exit 1

# --- 4. GNU ld 2.10 + dvp-as -------------------------------------------------
BU210_URL="https://ftp.gnu.org/gnu/binutils/binutils-2.10.tar.gz"
BU210_SHA256="fd7d227c0dd15cf5448385e56b8ad8313cd491839834b57c0c086ac7b7819a15"
BU210_PATCHES=("$ROOT/tools/binutils-2.10-ee.patch" "$ROOT/tools/binutils-2.10-dvp-ld.patch")
BU210_DIR="$CC_DIR/binutils-2.10-ee"
DVP_REPO="https://github.com/ps2dev/binutils-gdb"
DVP_COMMIT="3eb45ea37f0efd498d1de3cf9562de07197aefa8"   # dvp-v2.45.1
DVP_DIR="$CC_DIR/dvp-as"

apply_patch() {  # host may lack patch(1); git apply works outside a repo
    if command -v patch >/dev/null 2>&1; then patch -s -p1 < "$1"; else git apply -p1 "$1"; fi
}

build_dvp_as() {
    local stamp="$DVP_DIR/.stamp"
    if [[ -x "$DVP_DIR/bin/dvp-as" && "$(cat "$stamp" 2>/dev/null)" == "$DVP_COMMIT" ]]; then
        echo "==> dvp-as already at $DVP_DIR"; return 0
    fi
    echo "==> fetching ps2dev binutils-gdb $DVP_COMMIT"
    rm -rf "$CCSRC/dvp-binutils" "$CCSRC/build-dvp"
    mkdir -p "$CCSRC/dvp-binutils" "$CCSRC/build-dvp" "$DVP_DIR/bin"
    git -C "$CCSRC/dvp-binutils" init -q
    git -C "$CCSRC/dvp-binutils" fetch -q --depth 1 "$DVP_REPO" "$DVP_COMMIT"
    git -C "$CCSRC/dvp-binutils" checkout -q FETCH_HEAD
    echo "==> building dvp-as"
    ( cd "$CCSRC/build-dvp" &&
      ../dvp-binutils/configure --target=dvp --prefix="$DVP_DIR" \
          --disable-nls --disable-werror --disable-gdb --disable-gdbserver \
          --disable-sim --disable-gprof --disable-gprofng --disable-libdecnumber \
          --disable-readline --without-zstd > configure.log 2>&1 &&
      make -j"$(nproc)" all-gas MAKEINFO=true > make.log 2>&1 ) ||
        { echo "==> dvp-as build failed; see $CCSRC/build-dvp/*.log" >&2; return 1; }
    cp "$CCSRC/build-dvp/gas/as-new" "$DVP_DIR/bin/dvp-as"
    echo "$DVP_COMMIT" > "$stamp"
}

build_ld210() {
    local stamp="$BU210_DIR/.stamp" want
    want="$BU210_SHA256 $(cat "${BU210_PATCHES[@]}" | sha256sum | cut -d' ' -f1)"
    if [[ -x "$BU210_DIR/bin/ld" && "$(cat "$stamp" 2>/dev/null)" == "$want" ]]; then
        echo "==> ld 2.10 already at $BU210_DIR"; return 0
    fi
    mkdir -p "$CCSRC" "$BU210_DIR/bin"
    local tgz="$CCSRC/binutils-2.10.tar.gz"
    if [[ ! -f "$tgz" ]] || ! echo "$BU210_SHA256  $tgz" | sha256sum -c --status; then
        echo "==> fetching GNU binutils 2.10"
        curl -fsSL -o "$tgz" "$BU210_URL"
        echo "$BU210_SHA256  $tgz" | sha256sum -c --status ||
            { echo "==> binutils-2.10.tar.gz sha256 mismatch" >&2; return 1; }
    fi
    echo "==> building ld 2.10"
    rm -rf "$CCSRC/binutils-2.10" "$CCSRC/build-ld210"
    tar -xzf "$tgz" -C "$CCSRC"
    ( cd "$CCSRC/binutils-2.10" && for p in "${BU210_PATCHES[@]}"; do apply_patch "$p"; done ) || return 1
    cp "$CCSRC/dvp-binutils/config.sub" "$CCSRC/dvp-binutils/config.guess" "$CCSRC/binutils-2.10/"
    mkdir -p "$CCSRC/build-ld210"
    ( cd "$CCSRC/build-ld210" &&
      ac_cv_prog_lex_root=lex.yy ac_cv_prog_LEX=flex ac_cv_prog_YACC="bison -y" LEXLIB= \
      CC="gcc -std=gnu89 -fcommon -w -g -O1" \
          ../binutils-2.10/configure --target=mipsel-elf --disable-nls > configure.log 2>&1 &&
      make -j"$(nproc)" all-ld MAKEINFO=true > make.log 2>&1 ) ||
        { echo "==> ld 2.10 build failed; see $CCSRC/build-ld210/*.log" >&2; return 1; }
    cp "$CCSRC/build-ld210/ld/ld-new" "$BU210_DIR/bin/ld"
    echo "$want" > "$stamp"
}

# dvp-as first: the 2.10 build borrows its config.sub/config.guess.
build_dvp_as || exit 1
build_ld210 || exit 1

# --- 5. objdiff-cli ----------------------------------------------------------
# Pinned release binary; the SHA-256s are of the release assets as published.
OBJDIFF_VERSION="3.8.2"
OBJDIFF_URL="https://github.com/encounter/objdiff/releases/download/v$OBJDIFF_VERSION"
OBJDIFF_BIN="$CC_DIR/objdiff-cli"
case "$(uname -m)" in
    x86_64)  OBJDIFF_ASSET="objdiff-cli-linux-x86_64"
             OBJDIFF_SHA256="e5445089a6f707e30cb5e02992451b604619cedfd2660ee2373a86bfefd9e718" ;;
    aarch64) OBJDIFF_ASSET="objdiff-cli-linux-aarch64"
             OBJDIFF_SHA256="087516e73e1b3223b39974f00bc2810fea5c3dc2c93a8e1f06442ec68acaacb4" ;;
    *)       OBJDIFF_ASSET="" ;;
esac

fetch_objdiff() {
    if [[ -z "$OBJDIFF_ASSET" ]]; then
        echo "==> warning: no pinned objdiff-cli for $(uname -m); skipping (progress reports unavailable)" >&2
        return 0
    fi
    if [[ -x "$OBJDIFF_BIN" && "$("$OBJDIFF_BIN" --version 2>/dev/null)" == "objdiff-cli $OBJDIFF_VERSION" ]]; then
        echo "==> objdiff-cli $OBJDIFF_VERSION already at $OBJDIFF_BIN"
        return 0
    fi
    echo "==> fetching objdiff-cli $OBJDIFF_VERSION ($OBJDIFF_ASSET)"
    mkdir -p "$CC_DIR"
    local tmp="$OBJDIFF_BIN.part"
    curl -fsSL -o "$tmp" "$OBJDIFF_URL/$OBJDIFF_ASSET" ||
        { rm -f "$tmp"; echo "==> objdiff-cli fetch failed" >&2; return 1; }
    if ! echo "$OBJDIFF_SHA256  $tmp" | sha256sum -c --status; then
        rm -f "$tmp"
        echo "==> objdiff-cli sha256 mismatch for $OBJDIFF_ASSET (expected $OBJDIFF_SHA256)" >&2
        return 1
    fi
    chmod +x "$tmp"
    mv -f "$tmp" "$OBJDIFF_BIN"
}
fetch_objdiff || exit 1

echo "==> setup complete"
