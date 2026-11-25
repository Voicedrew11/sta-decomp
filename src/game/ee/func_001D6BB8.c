#include "common.h"

extern struct { char pad[0x80]; u32 a; u32 b; s32 state; s32 x8c; char p90[8]; s32 x98; } D_004B63B8;

s32 func_001D6BB8(u32 a, u32 b)
{
    if (D_004B63B8.state != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    D_004B63B8.a = a;
    D_004B63B8.b = b;
    D_004B63B8.x8c = 0;
    D_004B63B8.state = 9;
    D_004B63B8.x98 = 0x33;
    return 0;
}
