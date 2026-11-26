#include "m2c.h"
extern s32 D_002F1994[];
extern volatile s32 D_002F1998[];
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;

void func_00154420(void) {
    Q a;
    Q b;
    s32 n;
    s32 p;

    p = D_002F1998[0];
    n = (D_002F1994[0] - p) / 16 - 2;
    a.q = 0;
    a.w[1] = 0;
    a.w[0] = (n + 1) | 0x10000000;
    a.w[3] = (n + 1) | 0x51000000;
    *(Q *)p = a;
    b.q = 0;
    b.d[0] = (u64)(u32)n | (0x8000 | ((u64)0x10000000 << 32));
    b.d[1] = 0xE;
    *(Q *)(D_002F1998[0] + 0x10) = b;
}
