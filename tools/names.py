"""Game function names: config/game_func_names.txt.

Every game function is named <name>_<certainty>_<ADDR> (certainty 0-5, how
sure the name is right); unnamed functions keep splat's func_<ADDR>. Tools
that look for function symbols use FUNC (a regex whose group 1 is the
address) and func_name(addr) instead of building "func_%08X" themselves.
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
NAMES = ROOT / "config/game_func_names.txt"

# a function symbol: func_ADDR, or Name_C_ADDR; group 1 is the address
FUNC_PAT = r"(?:func|[A-Za-z]\w*?_[0-5])_([0-9A-F]{8})"
FUNC = re.compile(FUNC_PAT)
FUNC_FULL = re.compile(FUNC_PAT + r"$")


def load() -> dict[int, tuple[str, int]]:
    """address -> (base name, certainty)"""
    out = {}
    if NAMES.exists():
        for line in NAMES.read_text().splitlines():
            p = line.split("#", 1)[0].split()
            if len(p) == 3:
                out[int(p[0], 16)] = (p[1], int(p[2]))
    return out


_cache = None


def func_name(addr: int) -> str:
    """The symbol for the function at addr."""
    global _cache
    if _cache is None:
        _cache = load()
    n = _cache.get(addr)
    return f"{n[0]}_{n[1]}_{addr:08X}" if n else f"func_{addr:08X}"


def is_func(sym: str) -> bool:
    return FUNC_FULL.match(sym) is not None
