#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:7; } F;
typedef struct { s32 pad[3]; F f; u8 p[3]; } S;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s8 data[1]; } H;
extern S D_0022F040[];
extern s32 D_00222BC0[];

s32 func_0012E810(H *arg0, s32 arg1) {
    s32 i;
    s32 n;
    s32 v;
    F *f;
    s32 *d;

    f = &D_0022F040[arg1].f;
    d = (s32 *)((s32)arg0->data + ((arg0->xC + 0xF) & ~0xF));
    if (!f->b0) {
        return 0;
    }
    if (arg0->x4 == 0) {
        return -1;
    }
    n = *d++;
    for (i = 0; i < n; i++, d += 2) {
        v = *d;
        if (v >= 0x2800) {
            return -1;
        }
        D_00222BC0[v] = -1;
    }
    f->b0 = 0;
    return 0;
}
