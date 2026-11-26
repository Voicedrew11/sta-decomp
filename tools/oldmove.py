#!/usr/bin/env python3
"""tools/oldmove.py IN OUT : assemble newlib's code as its older gas did.

In that gas `move`, `dli`, `li.d`, `ld`, `sd` and any load or store with a
symbolic address were macros, and gas never put a macro's instructions into
a branch's delay slot.  Ours treats them as plain
instructions and fills delay slots with them.  Each one gas could reorder is
wrapped in `.set noreorder` / `.set reorder`, which stops that."""
import re,sys
# a load or store whose address names a symbol (`ld $5,dp_l($3)`) is a macro too
MEM_SYM=re.compile(r'(l[bhwd]u?|lw[lr]|ld[lr]|s[bhwd]|sw[lr]|sd[lr]|lwc1|swc1|ldc1|sdc1|lq|sq)\s+[^,]+,\s*[A-Za-z_.]')
out=[]; noreorder=False
for l in open(sys.argv[1]):
    s=l.strip()
    if s.startswith('.set') and 'noreorder' in s: noreorder=True
    elif s.startswith('.set') and re.search(r'\breorder\b',s): noreorder=False
    if not noreorder and (re.match(r'(move|dli|li\.d|ld|sd)\s',s) or MEM_SYM.match(s)):
        out.append('\t.set\tnoreorder\n'+l+'\t.set\treorder\n'); continue
    out.append(l)
open(sys.argv[2],'w').writelines(out)
