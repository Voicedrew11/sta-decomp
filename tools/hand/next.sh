#!/bin/bash
# next.sh N : the N smallest unmatched game functions (outside the VU0 module and the deferred list)
cd /home/fatalis/code/sta
skip=$(grep -o "func_[0-9A-F]\{8\}" docs/LEDGER.md | sort -u | tr '\n' '|')
awk '$4!="MATCH"{print $3}' build/m2c/results.tsv | while read n; do
  a=$((16#${n#func_})); [ $a -ge $((16#1DC328)) ] && [ $a -lt $((16#1DC900)) ] && continue
  [ -f src/game/$n.c ] || [ -f src/game/ee/$n.c ] && continue
  case "|$skip" in *"|$n|"*) continue;; esac
  echo $n
done | head -${1:-8}
