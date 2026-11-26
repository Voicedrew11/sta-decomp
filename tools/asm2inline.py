#!/usr/bin/env python3
"""tools/asm2inline.py FUNC [--rodata FILE] [OLD=NEW ...] : print a retail function from asm/*.s as a C top-level
__asm__ block, for TEMPORARY use while its C does not match yet.

OLD=NEW renames a symbol the splat asm references (a D_ address of a string
the C file now names, a func_ the C file defines under another name).
--rodata FILE also emits that splat .rodata file (the function's own
constants and jump tables) after the code, its labels made file-local."""
import glob, re, sys

args = sys.argv[1:]
fn = args.pop(0)
rodata = None
if args[:1] == ['--rodata']:
    rodata = args[1]
    args = args[2:]
ren = dict(a.split('=', 1) for a in args)
if rodata:
    for lab in re.findall(r'^dlabel (\w+)', open(rodata).read(), re.M):
        ren.setdefault(lab, '.L' + lab)
for path in glob.glob('asm/*.s'):
    text = open(path).read()
    m = re.search(r'^glabel %s\n(.*?)^endlabel %s\n' % (re.escape(fn), re.escape(fn)), text, re.M | re.S)
    if m:
        break
else:
    sys.exit('%s not found in asm/*.s' % fn)
lines = []
for line in m.group(1).split('\n'):
    line = re.sub(r'/\*.*?\*/', '', line).rstrip()
    if not line.strip():
        continue
    line = re.sub(r'^\s*jlabel\s+(\S+)', r'\1:', line)
    for old, new in ren.items():
        line = re.sub(r'(?<![\w.])%s\b' % re.escape(old), new, line)
    lines.append(line.strip() if line.strip().endswith(':') else '    ' + line.strip())
out = ['__asm__(".section .text\\n"', '        "    .set noat\\n"', '        "    .set noreorder\\n"',
       '        "    .align 3\\n"', '        "    .globl %s\\n"' % fn, '        "    .type %s, @function\\n"' % fn,
       '        "%s:\\n"' % fn]
out += ['        "%s\\n"' % l.replace('\\', '\\\\').replace('"', '\\"') for l in lines]
out.append('        "    .size %s, . - %s\\n"' % (fn, fn))
if rodata:
    out.append('        "    .section .rodata\\n"')
    for line in open(rodata).read().split('\n'):
        line = re.sub(r'/\*.*?\*/', '', line).strip()
        if not line or line.startswith(('.include', '.section', 'nonmatching', 'enddlabel')):
            continue
        line = re.sub(r'^dlabel\s+(\w+)', r'\1:', line)
        for old, new in ren.items():
            line = re.sub(r'(?<![\w.])%s\b' % re.escape(old), new, line)
        out.append('        "%s\\n"' % line.replace('\\', '\\\\').replace('"', '\\"'))
    out.append('        "    .section .text\\n"')
out += ['        "    .set reorder\\n"', '        "    .set at\\n");']
print('\n'.join(out))
