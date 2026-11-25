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
