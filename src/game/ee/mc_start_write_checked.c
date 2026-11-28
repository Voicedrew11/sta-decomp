#include "common.h"

extern struct { char pad[0x80]; u32 a; u32 b; s32 state; s32 x8c; s32 x90; char p94[4]; s32 x98; char p9c[4]; s32 c; s32 pa4; s32 e; char pac[8]; s32 xb4; s32 xb8; } D_004B63B8;

s32 Mc_StartWriteChecked_1_001D69B0(u32 a, u32 b, s32 c, s32 d, s32 e)
{
    if (D_004B63B8.state != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    D_004B63B8.state = 5;
    D_004B63B8.x8c = 0;
    D_004B63B8.x90 = 0;
    D_004B63B8.a = a;
    D_004B63B8.b = b;
    D_004B63B8.c = c;
    D_004B63B8.xb8 = d;
    D_004B63B8.e = e;
    D_004B63B8.x98 = 0x3C;
    return 0;
}
