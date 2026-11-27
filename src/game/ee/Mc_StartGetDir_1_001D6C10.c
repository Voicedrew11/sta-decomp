#include "common.h"

extern struct { char pad[0x80]; u32 a; u32 b; s32 state; s32 x8c; char p90[0x10]; s32 c; s32 d; } D_004B63B8;

s32 Mc_StartGetDir_1_001D6C10(u32 a, u32 b, s32 c, s32 d)
{
    if (D_004B63B8.state != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    D_004B63B8.d = d;
    D_004B63B8.a = a;
    D_004B63B8.b = b;
    D_004B63B8.c = c;
    D_004B63B8.state = 10;
    D_004B63B8.x8c = 0;
    return 0;
}
