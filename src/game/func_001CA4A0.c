#include "m2c.h"
s32 func_00131600(s32, s32);
u32 func_0015ED20(void);

s32 func_001CA4A0(u32 a0, s32 a1) {
    s32 vol;
    vol = a1 ? 0x7F : 0x35;
    switch (a0) {
    case 0:
        return func_00131600((func_0015ED20() & 3) + 0xC8, vol);
    case 1:
        return func_00131600((func_0015ED20() & 3) + 0xCD, vol);
    case 2:
        return func_00131600((func_0015ED20() & 3) + 0x8A2, vol);
    case 3:
        return func_00131600((func_0015ED20() & 3) + 0x8AC, vol);
    case 4:
        return func_00131600((func_0015ED20() & 3) + 0x8A7, vol);
    case 5:
        return func_00131600((func_0015ED20() & 3) + 0x8B6, vol);
    case 6:
        return func_00131600((func_0015ED20() & 3) + 0x8BB, vol);
    case 7:
        return func_00131600((func_0015ED20() & 3) + 0x8C5, vol);
    case 8:
        return func_00131600((func_0015ED20() & 3) + 0x8B1, vol);
    case 9:
        return func_00131600((func_0015ED20() & 3) + 0x8CF, vol);
    case 10:
        return func_00131600((func_0015ED20() & 3) + 0x8D4, vol);
    case 11:
        return func_00131600((func_0015ED20() & 3) + 0x8CA, vol);
    case 12:
        return func_00131600(0x8DE, vol);
    case 13:
        return func_00131600(0x8E3, vol);
    case 14:
        return func_00131600((func_0015ED20() & 3) + 0x8C0, vol);
    case 16:
        return func_00131600((func_0015ED20() & 3) + 0x8D9, vol);
    case 15:
    default:
        return -1;
    }
}
