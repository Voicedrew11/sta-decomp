#include "m2c.h"
void func_00165770(u32 *, s32, s32);
void func_001655C0(void *, u32 *, void *, s32, s32);
void func_001656B0(void *, u32 *, s32, s32);

void func_00165940(void *a0, void *a1, u32 *a2, u32 *a3) {
    u32 w;
    u32 hi;
    u32 w1;
    u32 mid;
    w = a2[0];
    w1 = a2[1];
    hi = (w & 0xFFFF0000) >> 16;
    mid = (w & 0xFFFFFF00) >> 8;
    switch (w & 0xFF) {
    case 1:
        func_00165770(a3, mid, w1);
        break;
    case 2:
        func_001655C0(a0, a3, a1, mid, w1);
        break;
    case 3:
        func_001656B0(a0, a3, mid, w1);
        break;
    case 0:
        a3[0] = hi;
        a3[1] = w1;
        break;
    case 0x11:
    case 0x12:
    case 0x13:
        a3[0] = w;
        a3[1] = w1;
        break;
    }
}

