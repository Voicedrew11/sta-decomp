#include "common.h"

extern struct { char pad[0x80]; u32 a; u32 b; s32 state; s32 x8c; char p90[0x10]; s32 c; s32 pa4; s32 d; s32 e; s32 f; } D_004B63B8;

s32 Mc_StartRead_2_001D6958(u32 a, u32 b, s32 c, s32 d, s32 e, s32 f)
{
    if (D_004B63B8.state != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    D_004B63B8.f = f;
    D_004B63B8.a = a;
    D_004B63B8.b = b;
    D_004B63B8.c = c;
    D_004B63B8.d = d;
    D_004B63B8.state = 4;
    D_004B63B8.e = e;
    D_004B63B8.x8c = 0;
    return 0;
}
