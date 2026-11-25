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
