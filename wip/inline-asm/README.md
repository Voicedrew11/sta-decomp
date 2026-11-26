# Inline-asm matches

These units match the retail code, but they reach it with inline asm (`sqrt.s`,
`rsqrt.s` and the like), which `tools/compile_c.sh` refuses in game code: inline
asm only retypes the retail instructions. They stay out of the build until the
same code comes from plain C. They are from KiskarFisk's shadow-tower-abyss.
Check one with `tools/match.py diff wip/inline-asm/func_X.c`.
