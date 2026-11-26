#include "common.h"
u32 func_001AA540(s32, s16);
void func_001AA5D0(s32, s16, u32);
void func_0013D5C0(s32 a, s32 b) {
    s32 bb = b & 0xFF;
    s32 hi = bb >> 5;
    s32 aa = a & 0xFF;
    u32 v = func_001AA540(aa, hi);
    v |= 1 << (bb & 0x1F);
    func_001AA5D0(aa, hi, v);
}

