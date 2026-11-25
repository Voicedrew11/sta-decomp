#!/bin/bash
# try.sh FILE... : match status of each variant
set -- $(realpath "$@"); cd ~/code/sta
for f in "$@"; do echo "$(basename $f): $(.venv/bin/python tools/match.py diff $f 2>&1 | grep -m1 -E 'MATCH|differ|rror')"; done
