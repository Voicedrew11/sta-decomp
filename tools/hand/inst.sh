#!/bin/bash
# inst.sh DIR : copy every func_*.c in DIR that matches into src/game (src/game/ee for the gcc modules)
cd /home/fatalis/code/sta
for f in "$1"/func_*.c; do
  r=$(.venv/bin/python tools/match.py diff "$f" 2>&1 | head -1)
  case "$r" in
    *"(mwccps2): MATCH"*) cp "$f" src/game/; echo "ok $(basename $f)";;
    *"(ee-gcc 2.96): MATCH"*) cp "$f" src/game/ee/; echo "ok ee/$(basename $f)";;
    *) echo "-- $(basename $f): $r";;
  esac
done
