#include "common.h"
#include "game/data.h"

u32 Bits_Read_2_00179720(u32 **pp, s32 n) {
    u32 r = 0;
    s32 total = n;
    u8 left;
    while (n != 0) {
        if (D_00202028 == 0) {
            D_00202028 = 32;
            D_0020202C = **pp;
            (*pp)++;
        }
        left = D_00202028;
        if (n < left) {
            r |= (D_0020202C & (0xFFFFFFFF >> (32 - n))) << (total - n);
            D_00202028 = left - (u8)n;
            D_0020202C >>= n;
            return r;
        }
        r |= (D_0020202C & (0xFFFFFFFF >> (32 - left))) << (total - n);
        D_00202028 = 0;
        n -= left;
    }
    return r;
}
