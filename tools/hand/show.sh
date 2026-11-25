#!/bin/bash
# show.sh NAME... : asm + m2c output + first diff lines
cd ~/code/sta
for n in "$@"; do
  echo "=== $n"
  grep "/\*" build/m2c/$n.s | grep -v "^\s*/\* [0-9A-F]* [0-9A-F]* 00000000 \*/  nop$" | sed -E 's|/\* [0-9A-F]+ ([0-9A-F]+) [0-9A-F]+ \*/|\1|'
  grep -v "^#include" build/m2c/$n.c | grep -v '^$'
  grep -E "^  (>>|  )" build/m2c/$n.txt | head -${DIFFN:-0}
done
