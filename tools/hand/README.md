Shell helpers for hand matching, smallest functions first:

- `next.sh N`: the N smallest unmatched game functions (from build/m2c/results.tsv,
  skipping the VU0 module and every function named in docs/LEDGER.md)
- `show.sh FUNC...`: asm, m2c starting point and (with DIFFN=n) the first diff lines
- `try.sh FILE.c...`: match status of each candidate C file
- `inst.sh DIR`: copy every func_*.c in DIR that matches into src/game/ (src/game/ee/)
- `commit.sh "message"`: carve, rebuild, near-duplicates, diff ledger, progress,
  commit, and notify-send with the gain and the largest new match
- `rules_table.py [COMMIT]`: for each function a commit matched, the differing words
  of m2c's output, of the m2c + rules starting point, and the final match (0)
