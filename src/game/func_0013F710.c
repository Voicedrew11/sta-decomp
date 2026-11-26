#include "common.h"
u16 func_0013F710(s8 *a0, s32 v) {
    u16 *p;
    s32 n;
    s32 m;
    p = (u16 *)(*(s8 **)(a0 + 0x518) + 0x16C);
    n = *p + v;
    m = **(u16 **)(a0 + 0x4B0);
    if (n < 0) n = 0;
    if (m < n) n = m;
    *(u32 *)p = (u16)n;
    *(s16 *)(a0 + 0x6BA) = v;
    return n;
}

