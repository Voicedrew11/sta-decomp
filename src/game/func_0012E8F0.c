#include "m2c.h"
#include "common.h"
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H;
typedef struct { s32 st; s32 p4; s32 p8; Flags8 fC; u8 pD[3]; } S;
extern S D_0022F040[];
extern s32 D_00222BC0[];
void FlushCache(s32);

s32 func_0012E8F0(H *a0, s32 idx) {
    s32 i;
    s32 *p;
    s32 *end;
    s32 n;
    s32 k;

    p = (s32 *)((u8 *)((s32)a0 + 0x10) + ((a0->c + 15) & ~15));
    end = (s32 *)((u8 *)p + a0->b);
    if (a0->b == 0) return -1;
    n = *p++;
    for (i = 0; i < n; i++) {
        if (!(p < end)) return -1;
        k = p[0];
        if (!(p + 1 < end)) return -1;
        if (k >= 0x2800) return -1;
        D_00222BC0[k] = p[1];
        p += 2;
    }
    FlushCache(0);
    D_0022F040[idx].fC.f.b0 = 1;
    return 0;
}
