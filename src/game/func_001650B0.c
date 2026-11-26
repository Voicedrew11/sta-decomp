#include "common.h"
void func_001650B0(u8 *a0, u8 a1, u8 a2, s16 a3) {
    u8 *e = (u8 *)(a2 * 8 + (s32)(a0 + a1 * 0x258));
    *(s32 *)(e + 0x36C) = 2;
    *(s32 *)(e + 0x370) = a3;
}

