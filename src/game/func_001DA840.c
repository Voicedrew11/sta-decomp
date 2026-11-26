#include "common.h"
typedef struct { s32 x0; s32 x4; s16 x8; s16 xA; s32 xC; s32 x10; s16 x14; s16 x16; u8 p[8]; } M;
extern M D_004BA880[];
void FlushCache(s32);
s32 func_001DA840(s32 a0, s16 a1, s16 a2, s16 a3, s16 t0, s32 t1) {
    M *m = D_004BA880;
    s32 i;
    s32 r;
    for (i = 0; i < 4; i++, m++) {
        if (m->x0 == -1) { r = i; break; }
    }
    if (i >= 4) return -2;
    m->x0 = t1;
    m->x4 = a0 | 0x100;
    m->x8 = a1;
    m->xA = a2;
    m->xC = a3;
    m->x10 = t0;
    m->x14 = a1;
    m->x16 = a2;
    FlushCache(0);
    return r;
}

