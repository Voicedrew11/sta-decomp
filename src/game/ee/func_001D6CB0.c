#include "common.h"

extern struct { char pad[0x80]; u32 a; u32 b; s32 state; s32 x8c; char p90[0x10]; s32 c; } D_004B63B8;

s32 func_001D6CB0(u32 a, u32 b, s32 c)
{
    if (D_004B63B8.state != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    D_004B63B8.c = c;
    D_004B63B8.b = b;
    D_004B63B8.a = a;
    D_004B63B8.x8c = 0;
    D_004B63B8.state = 0xD;
    return 0;
}
