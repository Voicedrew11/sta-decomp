#include "common.h"
s32 DIntr(void);
s32 EIntr(void);
typedef struct { u32 base; u32 tags; s32 n; s32 xC, x10, x14, x18, x1C, x20, x24, x28; s32 pad[6]; s32 x44; u64 x48; } S;
s32 func_001EB060(S *p) {
    s32 i;
    p->xC = 0;
    p->x10 = 0;
    p->x14 = 0;
    p->x44 = 1;
    p->x48 = 0;
    p->x1C = 0;
    p->x20 = 0;
    p->x24 = 0;
    p->x28 = 0;
    for (i = 0; i < p->n; i++) {
        ((u64 *)p->tags)[i * 2] = ((u64)(p->base + i * 0x800) << 32) | 0x30000080;
    }
    ((u64 *)p->tags)[i * 2] = ((u64)(p->tags & 0x0FFFFFFF) << 32) | 0x20000000;
    *(volatile s32 *)0x1000B420 = 0;
    *(volatile s32 *)0x1000B410 = p->base & 0x0FFFFFFF;
    *(volatile s32 *)0x1000B430 = p->tags & 0x0FFFFFFF;
    DIntr();
    *(volatile s32 *)0x1000F590 = *(volatile s32 *)0x1000F520 | 0x10000;
    *(volatile s32 *)0x1000B400 = 5;
    *(volatile s32 *)0x1000F590 = *(volatile s32 *)0x1000F520 & ~0x10000;
    EIntr();
    return 1;
}
