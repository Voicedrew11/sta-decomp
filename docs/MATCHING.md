# Matching notes

Code-shape tricks that made MWCC 3.0b52 (`-O4,p`) reproduce the original, collected while matching.
Function names point at examples in `src/`.

## General

- Saved regs assigned in declaration order from the top (first local -> highest s-reg); declaration order also sets temp regs. Try permutations of local order first.
- Stack locals laid out in reverse declaration order (last declared = lowest address). Buffer sizes set frame size (`addiu sp,-N`).
- `T x = {0};` gives the compiler's clear loop (no pad nop); hand loops get padded. Can go inside a case block.
- -O4,p pads branch targets with nop; a ternary instead of if/else avoids the pad (`h = c ? &A : &B;`, `return c ? x : z;`).
- u128 unions + struct assignment for lq/sq copies; `__attribute__((aligned(16)))` on vars (extern and local) for lq/ld copies.
- volatile (read once into a local) for reloads after stores.
- Bitfield typedefs for bit set/test (`|= 8` -> `.b3 = 1`); include/actor.h has Flags8 and the Actor struct.
- `x > N-1` / `v <= 311` style to get slti $at; `!f() == 0` for sltu/xori.
- for-loops may unroll; do-while over pointers avoids it. Plain `for(i=0;i<n;i++)` gives slt+beqz entry.
- Return the value to keep it in v0. u8 return type/var gives `daddiu v0,zero,1`.
- Index struct byte arrays (`a0->arr[i & 0xFF]`) to fix addu operand order.
- Typed struct instead of M2C_FIELD stops address-reuse CSE; `(s32)p + off` stops offset folding.
- One-case `switch` produces branch-into-body-then-jump shape. Switch cases tested in reverse source order.
- `static inline` helpers reproduce inlined lookup patterns (see src/ siblings 001B16E0, 0017E940).
- s32 locals passed to s16 params get re-sign-extended; explicit (s16) casts cost a saved reg.
- Last-resort scheduling barrier: a no-op `if (q && q) {}` (permuter-found), comment it.
- Permuter: `tools/perm_setup.py`; put the directory with the `cpp` shim (see README) first on PATH.

## More specific

- Float branch to a later "true" block (bc1t L; li r,2 in delay; ... L: li r,1): write `if (!(x < K)) return 2; return 1;` — ternaries and if/return-1-first give bc1f.
- `n = (n <= 0) ? 1 : n;` / `n = (n < 5) ? 5 : n;` reproduce s16 clamp via int temp (dsll/dsra re-truncate) with the right branch sense; plain if gives direct li to the s-reg.
- Bitfield value of an assignment is reused: `o->f88 = o->b1 = 0;` gives the dsll/dsrl extract + unsigned->float conversion of the stored byte.
- Order of pointer computations from the same base (t, e, s) decides temp registers; try permuting statement order before locals.
- Re-using an existing local (e.g. `b = idx;` then `b & 0xFFFF`) can shift register allocation in the right direction (permuter-found).
- Unrolled loops that come out in reverse index order: index with `[7 - i]` in an ascending for-loop (func_0019E090).
- A condition var read into a local BEFORE an earlier struct copy (`on = p->x8; t = D; if (on)`) gets the load hoisted into the copy sequence (func_001907D0).
- Accessing a global array directly by index (`D[idx] = i + 1`) instead of through a `u16 *cur = &D[idx]` pointer changed which temps got a2/a3 (func_0015B980).
- `0 > x` gives `slt at,x,zero`; `x < 0` gives bltz and `x <= -1` gives `slti at,x,0`.
- Float add operand order ignores source order; put the product in a temp first (`t = a*b; r = t + c;`) to get `add.s d,t,c`.
- A 4-byte colour copied with lwc1/swc1 needs a 4-aligned type: `union { u32 w; struct { u8 r,g,b,a; } c; }` (a plain u8 struct copies bytewise and shifts register allocation).
- To hoist byte loads above byte stores that may alias, read the fields into u8 locals first (declaration order = load order); s32 locals get folded back into the uses.
- A `b` to the very next instruction (delay slot filled) right before a join = early `return` inside an inlined static helper; a helper that also loads its own base pointer can fix register swaps.
- MWCC evaluates call arguments/operands right-to-left in one expression: `R2() + x * (R1() - 0.5f)` calls R1 first; splitting into statements changes float add operand order.
- Self-recursive function with 2-3 levels of call bodies duplicated inline = hand-written `static inline` copies (g2 -> g1 -> f); `inline` on the function itself doesn't do it.
- Statement order of independent global stores decides scheduling; brute-force permutations (5 stmts = 120 builds) are cheap.
- `x > 0xFF` (not `>= 0x100`) gives slti $at+bnez for early-return range checks; `*++s` keeps separate addiu+lhu 0 instead of folded offsets.
- Constants with bit31 set built as `ori; dsll 16; ori` (zero-extended) mean the parameter is 64-bit (u64/s64), not u32.
- Each loop with its own s-reg assignment wants its own counter/pointer variables (declared in the order of the regs, highest first); reusing one set across loops shares regs.
- Shared-struct globals: splat names each field address (D_004A1058...), but one struct extern at the base matches too; table accesses folded as `lbu 0x18(base+idx*4)` reveal the base.
- A bitfield's assigned value is reused without reloading when written as an expression: `o->x = (f32)(u32)(o->b1 = 0);` (separate statements reload the byte).
- When all s-regs are used, params spill to the stack at entry: a u8 param spills with sb, an int with sw; the callee's prototype param types (u8) decide lbu reloads at the call instead of hoisted andi.
- if/else assigning two constants to a local union becomes movz (select); storing via `*(u32 *)&col = K;` in each branch keeps the branches and separate sw.
- `if (cond && !inl(x) != 0)` keeps an inline bool materialized (xori/sltiu/xori + beqz) instead of folded into branches. Brute-forcing the declaration order of 5 locals (120 files, about 3 min) cut one diff from 87 lines to 35.
- u16->float showing the unsigned-convert pattern (bltz/srl/or/cvt/add.s): `static inline f32 u2f(u32 x) { return x; }`; the inline also stops MWCC sinking a nearby if/else past it.
- Keep an "empty" then-block (bc1f else; b join) with a self-assign: `if (a < b) { b = b; } else { b = a; }`.
- Commutative operand order stuck (mult/addu)? Update in place: `n *= 2; sz = n * esz;` instead of `sz = n * 2 * esz;`; fold offsets into the index: `p->tbl[k + 0x20]` instead of `*(s32 *)((s8 *)&p->tbl[k] + 0x80)`.
- Arg setup order (where mov.s f12 lands) depends on where the f32 params sit in the callee prototype; try moving them earlier, e.g. (s8 *, f32, u32, f32).
- 64-bit dsll + final dsll32/dsra32 on a GS PRIM value = PS2 SDK GS_SET_PRIM-style macro with (u64) casts on every field: `(u64)6 | ((u64)b0 << 3) | ... | ((u64)1 << 8)`.
- Extra `b epilogue` + pad nop at the very end of an else path = an explicit `return;` there (padded epilogue label).
- u16 global passed to several s16 params: hold it in an `s32` local; a `u16` local lets MWCC CSE the sign-extension into a saved reg (extra s-reg, bigger frame).
- `s16 += (s32)(float expr)` adds a redundant sext of the converted value; `+= (s16)(float expr)` matches.
- Operand order of `call() + x*y`: store the call result in an s16 temp first (`r = f(); if (r + x*y > 99)`).
- Globals addressed as one base + offsets (base symbol D_X used with large offsets) = one struct extern at D_X containing the arrays.
- Direct lq from a stack union (lq x,0x60(sp)) comes from copying the u128 member (p[i].q = q.q); whole-union assignment (p[i] = q) materializes &q in a register first.
- Chained float 'first nonzero difference' compares: an inline helper with early returns and a final ternary (return d != 0 ? d : 0.0f) gives the bc1t/b chain with mov.s from the zero reg.
- Consecutive loops: reusing one counter variable vs separate i/j changes saved-register assignment; try both along with declaration order.
- Conditional pointer bumps (`if (bit) p += N;`) get a pad nop on the skipped target; `p = bit ? p + N : p;` doesn't.
- Float args: putting the f32 first in the callee prototype moves its mov.s earlier (into the preceding branch delay slot); trailing f32 stays next to the jal.
- Values passed to u8/u16 params from int locals get andi masks; load them into s32 locals (not u8) to reproduce `lbu` + `andi 0xFF`.
- A for-loop walking `(&a0->arr)[i]` from the object base becomes an IV on a0 itself: write `((T **)a0)[i + OFF/4]` to get `lw X, OFF(s1)` with s1 = a0 + 4i.
- `if (a0 != 0 && ...) { body }` (single return path) avoids the bnez/b early-exit shape that `if (...) return;` gives.

## Struct candidates

Globals accessed at many offsets across unmatched code, worth a shared header in `include/` (like `actor.h`):

- `D_00201DC0`: pointer to a struct of about 0x7C1C bytes (67 fields seen); slot table at 0x5C00, 0x1C0-byte groups at 0x10E0 (func_001A95A0).
- `D_004AC630`, `D_004AC970`, `D_004AE370`: arrays of 0xD0-byte elements (local `Obj` typedefs in several files).
- `D_0022CBC0`: 63 elements of 0x80 bytes.
- `D_003407E0`: elements of 0xED0 bytes.
- `Actor->unk518`: sub-object; +0x180, +0x190 used.

## Compiler builds

3.0.1b44, b51 and b74 don't pad `bc1t` targets the way 3.0b52 does, but 3.0.1b44 fails 27 of 51 sampled
matched files, so they are not the game's compiler. Padding differences are fixed in the source instead
(ternaries, `= {0}`).
