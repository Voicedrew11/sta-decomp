#include "common.h"
s32 func_0012E8F0(u8 *, s32);
s32 func_0012ED60(u8 *, u32);
extern s32 D_0022F040[];
typedef struct { u8 pad[0xC]; u16 xC; u8 pad2[2]; s32 x10; } H;
s32 func_0012E6B0(H *a) {
    u8 *p = (u8 *)&a->x10;
    if (a->xC != 4) return -1;
    func_0012E8F0(p, 0);
    p += *(s32 *)p;
    D_0022F040[0] = 0;
    while (func_0012ED60(p, 0) == 0) {}
    return 0;
}

