#include "common.h"
s32 DIntr(void);
s32 EIntr(void);
s32 SignalSema(s32);
s32 WaitSema(s32);
typedef struct { u32 base; u32 tags; s32 n; s32 xC, x10, x14; s32 pad[10]; s32 sema; s32 x44; } S;
#define R(a) (*(volatile u32 *)(a))

s32 func_001EAC70(S *f) {
    u32 chcr, madr;
    s32 isNew = 0;
    u64 hi;
    u32 e;
    s32 id, consume, rs, rn, i, last;
    WaitSema(f->sema);
    if (f->x44 == 0) return 0;
    DIntr();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B400) = 5;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    EIntr();
    chcr = R(0x1000B400);
    madr = R(0x1000B410);
    if (madr == ((f->tags + (f->n + 1) * 16) & 0x0FFFFFFF)) {
        id = 0;
    } else {
        id = (madr - f->base) >> 11;
    }
    consume = (id + f->n - f->xC) % f->n;
    f->xC = (f->xC + consume) % f->n;
    f->x10 -= consume;
    rs = (f->xC + f->x10) % f->n;
    rn = f->x14 / 2048;
    f->x14 = f->x14 % 2048;
    if (rn > 0) {
        isNew = 1;
        last = (f->n + (f->xC + f->x10 - 1)) % f->n;
        ((u64 *)f->tags)[last * 2] = ((u64)(f->base + last * 0x800) << 32) | 0x30000080;
    }
    for (i = 0; i < rn; i++) {
        hi = (u64)(f->base + rs * 0x800) << 32;
        if (i == rn - 1) e = 0; else e = 3;
        ((u64 *)f->tags)[rs * 2] = hi | ((u64)e << 28) | 0x80;
        rs = (rs + 1) % f->n;
    }
    f->x10 += rn;
    if (f->x10 != 0) {
        if (isNew) chcr = (chcr & 0x0FFFFFFF) | 0x30000000;
        DIntr();
        R(0x1000F590) = R(0x1000F520) | 0x10000;
        R(0x1000B400) = chcr | 0x100;
        R(0x1000F590) = R(0x1000F520) & ~0x10000;
        EIntr();
    }
    SignalSema(f->sema);
    return 1;
}
