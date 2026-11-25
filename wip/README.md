# Near-misses

Best attempts at functions that don't match yet. Each compiles; what still differs is noted below.
Check one with `tools/diff_func.sh wip/func_X.c START END`. `tools/order_search.py` can help with
register and scheduling differences.

| Function | What still differs |
|---|---|
| func_001544C0 | register choice only (orig p=a0, c=a1, div/n=v1). volatile globals give the reloads |
| func_001B1D00 | one `addu` operand order (orig `addu a2,a1,a0`) |
| func_00132A70 | orig moves the loop setup after the loop and branches back into it; ours keeps invariants in s-regs (frame 0x70 vs 0xA0) |
| func_001B1050 | t1/t2 swapped between the two slot pointers (inline helpers from func_001B16E0) |
| func_0017E5B0 | regalloc of inlined find-object temps; likely same fix as func_001B1050 |
| func_001B0EB0 | regalloc in inlined `find` (orig slots t1/t2, result a3); same family as func_001B1050 |
| func_001A4420 | store of `a.n` lands 2 slots late; all 24 store orders tried |
| func_0016A9D0 | one `addu` operand order (orig `addu v0,a0,v0`) |
| func_0015DBF0 | ~18 instrs: v70[3] store order, table-update regs, a0/a1 swap |
| func_0013D8A0 | else-branch: `negu` scheduled before the `andi`/`sw` of `*q` (Actor accessor block) |
| func_001AF4A0 | case-1 list remove: orig reloads count each pass and puts the shift loop's setup after the function |
| func_001B85B0 | ours keeps idx*0x30 in s4 across calls (extra s-reg, frame +0x10) |
| func_001B87C0 | first block regs: load from 0x180 to t1 (ours a2) |
| func_00167310 | `b` delay slot left empty (orig fills with next `lwc1 f21`); `move s0,a0` before null check |
| func_00146EF0 | float regs: hh/d swapped between $f22/$f24 |
| func_001717A0 | 4 words, regs only: orig tbl=a1 and keeps q+0x40 in a2 |
| func_0014C890 | &v should be s1 below the loop pointers; multiply operand order |
| func_001BA3F0 | `mul.s` operand order and `lbu` of t+0x13 scheduled late |
| func_00147E90 | last flag: orig writes `c = 0` in a branch delay slot; ours gets an else branch or `sltu` |
| func_0012F0F0 | arg setup of the `func_001DAC70` call in state 1: orig loads `ch` first and `off` before `addr[arg1]` |
| func_00162700 | shared inline count helper: orig has 2 nops before `div` in the `rate < fp` branch, `(f32)period` in $f1 (ours $f2) |
| func_001629E0 | same inline helper as func_00162700; fixing one should fix both |
| func_00146C70 | 4 words, regs only: loaded entry `e` (`lw 0x4B4(s0)`) lands in a1, orig a3 |
| func_001BC610 | 23 words, scheduling: orig computes the `b1` bitfield value (`andi t0,zero,1`) before the `f&1` andi |
| func_0014BC90 | final float block: orig computes `2.0f * 0.05f` at runtime; MWCC folds it to 0.1f in every form tried |
| func_001C55A0 | arg copies land one temp reg higher in orig (a2→t5, a1→t6, a3→t4, t0→t3, t1→t2) |
| func_00182C10 | float load/mul order for pos[0..3]; `lq` vs `ld`/`sd` on a 24-byte copy; loop init not in `beqz` delay slot |
| func_001789E0 | tail copy: orig keeps dead pointer updates `a1/a0 += a2<<4` that MWCC removes (pragmas didn't help) |
| func_00181420 | orig uses the loop induction pointer as the final `sq` dest; ours copies it (`move t2,v0`) |
| func_0013FCC0 | `f32 sz[2]` kept in memory needs `&sz`, which hoists the address into s0; orig uses sp offsets |
| func_001B3240 | saved-reg allocation (orig spills d/cb/b0/off at 0xD0..0xA0) and 0xEE/0xEF home-slot swap of the u8 args |
| func_001CE4B0 | 1 word: default 3 set with `daddiu t0,zero,3` (orig) vs `li`; `u16 h` gives daddiu but breaks the mask/float conversion |
| func_00151E50 | 1 word: late clear loop count `li v0,16` vs orig 8; the C slot only lands at 0x40 with a 16-byte struct |
| func_0015DFA0 | quaternion slerp; saved regs only: orig `out` in s6, ours s0 (permuter candidate) |
| func_0016DC70 | GIF packet; saved regs rotated (orig gives p and &q.w[1]/[3] the high s-regs) (permuter candidate) |
| func_001B8350 | first block regs shifted by one; orig `li v1,1; movz v1,zero,a2` for `a2 ? 1 : 0` (MWCC gives sltu) |
| func_00136DB0 | inlined axis-angle rotation (as func_0015EBB0 times a vector): float scheduling/regs only |
| func_0017EAF0 | adapted func_0017E940 inlines; shape identical, temp regs only (slot pointer v1 vs a2) |
| func_0016EF70 | right size/branches, loop regalloc differs (orig spills a0, i in t9); far (155 words) |
| func_001777C0 | ~50 words, regs only (size calc reuses a0; func_00176BF0 result in a1; TEX0 bitfield temps t0/v0 vs ours t1/t0) |
| func_00176FB0 | 159 words; saved-reg swap (orig: sign-extended idx/return in s2, raw param s1) shifts all temps |
| func_0016FB80 | 6 words; only a0/a1 spill slots (orig 0x110/0x10C) |
| func_001BBCC0 | 8 words; one `mult1` dest v1 vs a0 (2800 statement orders tried) |
| func_00177BB0 | 88 words; free-list unlink/insert regalloc (idx in a3 vs v1, idx*48 reused) |
| func_0013A720 | 2 words; `addu` operand order in `p->x2C + p->x18->xB5*0x140 + 0x234` |
| func_001A8700 | 45 words; saved-reg assignment / setup scheduling |
| func_001ADD30 | uses string literal `"CAPS"` (non-small-data); code matches but batch.py can't link literals |
| func_0016D830 | 6 words; byte from `m[idx].x130` in a3 vs a1 |
| func_00148120 | 8 words; float temps of the early constant multiplies |
| func_0018B860 | 3 words; `move s0,zero` vs loop-entry `sltu/beqz` order |
| func_001C6590 | 6 words; case 8 temp v1/v0 for 30.0f, final-call arg order |
| func_00189740 | 57 words; unrolled 2nd loop wants `p+0x10` in t1 |
| func_00134960 | 2 words; masked `func_001435D0` result in a0 vs a2 |
| func_00153770 | 6 words; t1/t2 swap in last 3 GS pushes |
| func_00165A30 | 5 words; orig has empty then-branch `bnez isf -> load; b join` |
| func_0013F210 | 16 words; v0/v1 swap in the two clamps of the `flag` branch |
| func_0019CEF0 | 3 words; `a3*9` temp a0 vs a2 in case 400 |
| func_0014E230 | 65 words, stack offsets only: orig spills pointer params o1/o2 to 16-aligned slots (frame 0x2A0) |
| func_00185740 | 40 words; orig reloads `o->x38` after `o->x38 += 4.0f` |
| func_001B51F0 | 56 words; prologue moves a2 to s3, saved regs for n/cur/&PP(n) rotated |
| func_0013CBC0 | code identical when func_0013C360 is a `static` definition earlier in the same file (MWCC then knows a0/t0 survive the call); needs file regrouping |
| func_00137E60 | 16 words; f22/f23 swap for t/dd, `out` param spill slot 0xC0 vs 0xC4 |
| func_001797E0 | 118 words; needs static func_00179720 earlier in file (included); r/n v1/a0 swap in inlined bit reads |
| func_001B9F10 | 14 words, stack only: orig spills pos/rot params to 16-byte slots |
| func_0014E680 | 60 words; frame 0x10 bigger in orig (unknown 8-byte slots), one mov.s swap |
| func_0016D380 | 126 words; `flag & 1` kept in s5 from prologue, spills differ |
| func_001973F0 | 169 words; saved-reg order only (orig sel=s4,n=s3,k=s2,id=s1,o=s0) |
| func_001C0020 | 1 word; `addu a1,a0,s2` operand order |
| func_0015F540 | 177 words; s-reg choice only (p/q/converted value) |
| func_0016C7E0 | far: 16 bytes short, ctx spill not reproduced |
| func_001D31E0 | 48 words; innermost `h + n4*20` operand order, pointer table regs |
| func_00137870 | far; orig spills outer counter i and count na, keeps inner k in s3 |
| func_0016BD00 | far; right size, float temp allocation off throughout |
| func_00185D70 | 2 words; temp reg of the 24-byte `buf = D_001F26B0` lq/sq copy (a2 vs a0) |
| func_00148D00 | angle-wrap `PI + a` sum shared (orig recomputes), bitfield `++` reuses reg |
| func_0014FA30 | one extra spill slot, frame 16 bytes bigger |
| func_001B6190 | uses string literals "STMI"/"STEM"/"STOI" (>8 bytes padded); batch.py can't link literals |
| func_00196330 | 3 words; `func_001AFC90()[a3]` index temp a0 vs a2 (same as func_0019CEF0) |
| func_001A4990 | ~50 instrs; 11-entry loops start with `addu sN,v1,zero` + pad nop |
| func_00168480 | 73 words; GS setup regalloc, missing pad nop after clamp |
| func_0016CD80 | 29 words; hdr/q swapped (orig keeps q in reg, hdr on stack) |
