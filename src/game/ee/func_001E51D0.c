#include "common.h"
typedef struct { u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4; u64 REGS; } G;
static inline G *set(G *p, u64 nloop, u64 eop, u64 pre, u64 prim, u64 flg, u64 nreg, u64 regs) {
    p->NLOOP = nloop;
    p->EOP = eop;
    p->pad16 = 0;
    p->PRE = pre;
    p->PRIM = prim;
    p->FLG = flg;
    p->NREG = nreg;
    p->REGS = regs;
    return p + 1;
}
G *func_001E51D0(G *p, s32 nloop, s32 eop, s32 prim, s32 flg, s32 nreg, u64 regs) {
    return set(p, nloop, eop, prim != 0, prim, flg, nreg, regs);
}

