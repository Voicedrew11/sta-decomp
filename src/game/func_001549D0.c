#include "m2c.h"
typedef union Q { u128 q; struct { u32 a; u32 b; union Q *p; u32 d; } s; } Q;
typedef struct { s32 pad0[3]; s8 *c; s32 pad10[16]; u32 x50; Q *x54; } G;
extern G D_002F1940[];
extern s32 D_002F1994[];

void func_001549D0(void) {
    s8 *c;
    Q tag;
    Q save;
    G *g = D_002F1940;
    Q *n;

    if (D_002F1994[0] != 0) {
        c = g->c;
        save.q = *(u128 *)(c + 0x10);
        tag.q = 0;
        tag.s.a = 0x20000000;
        tag.s.b = save.s.d;
        *g->x54 = tag;
        tag = *save.s.p;
        tag.s.b = g->x50 & 0x0FFFFFFF;
        *save.s.p = tag;
        save.s.p = g->x54;
        *(u128 *)(c + 0x10) = save.q;
        n = g->x54 + 1;
        g->x54 = n;
        g->x50 = (u32)n;
        g->x54 = 0;
    }
}
