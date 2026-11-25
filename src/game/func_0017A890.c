#include "common.h"

u8 *func_00165130(u8 *o, s32 b);
u32 func_001AA540(u8 a, s16 b);

void func_0017A890(u8 *o)
{
    u8 *p = func_00165130(o, 2);
    u8 a = o[8];
    s32 b;
    if (a <= 200) {
        b = o[0x10];
        if (b <= 32)
            *p = func_001AA540(a, (u32)b >> 2) >> ((b % 4) * 8);
    }
}
