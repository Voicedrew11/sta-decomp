#include "common.h"
u32 func_001AA540(s32, s16);
u16 func_0013D560(s32 a, u8 b) {
    u16 r;
    if (b & 0x10) r = func_001AA540((u8)a, b >> 5) >> 16;
    else r = func_001AA540((u8)a, b >> 5);
    return r;
}
