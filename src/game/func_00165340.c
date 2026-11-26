#include "common.h"
void func_00165340(s32 a0, u8 *a1, s32 a2, s32 a3) {
    u8 *d = (u8 *)(a3 + a0) + 0x14;
    switch ((u16)((a2 & 0xFFFF00) >> 8)) {
    case 0: *(s8 *)d = *(s8 *)(a1 + 4); break;
    case 1: *(u8 *)d = *(u8 *)(a1 + 4); break;
    case 2: *(s16 *)d = *(s16 *)(a1 + 4); break;
    case 3: *(u16 *)d = *(u16 *)(a1 + 4); break;
    case 4: *(s32 *)d = *(s32 *)(a1 + 4); break;
    case 5: *(u32 *)d = *(u32 *)(a1 + 4); break;
    case 6: *(f32 *)d = *(f32 *)(a1 + 4); break;
    }
}

