#include "common.h"
s32 func_00131600(s32, s32);                    /* extern */
s32 func_0015ED20();                                /* extern */

s32 func_001CA4A0(u32 arg0, s32 arg1) {
    s32 temp_16;

    temp_16 = (arg1 != 0) ? 0x7F : 0x35;
    switch (arg0) {
    case 0:
        return func_00131600((func_0015ED20() & 3) + 0xC8, temp_16);
    case 1:
        return func_00131600((func_0015ED20() & 3) + 0xCD, temp_16);
    case 2:
        return func_00131600((func_0015ED20() & 3) + 0x8A2, temp_16);
    case 3:
        return func_00131600((func_0015ED20() & 3) + 0x8AC, temp_16);
    case 4:
        return func_00131600((func_0015ED20() & 3) + 0x8A7, temp_16);
    case 5:
        return func_00131600((func_0015ED20() & 3) + 0x8B6, temp_16);
    case 6:
        return func_00131600((func_0015ED20() & 3) + 0x8BB, temp_16);
    case 7:
        return func_00131600((func_0015ED20() & 3) + 0x8C5, temp_16);
    case 8:
        return func_00131600((func_0015ED20() & 3) + 0x8B1, temp_16);
    case 9:
        return func_00131600((func_0015ED20() & 3) + 0x8CF, temp_16);
    case 10:
        return func_00131600((func_0015ED20() & 3) + 0x8D4, temp_16);
    case 11:
        return func_00131600((func_0015ED20() & 3) + 0x8CA, temp_16);
    case 12:
        return func_00131600(0x8DE, temp_16);
    case 13:
        return func_00131600(0x8E3, temp_16);
    case 14:
        return func_00131600((func_0015ED20() & 3) + 0x8C0, temp_16);
    case 16:
        return func_00131600((func_0015ED20() & 3) + 0x8D9, temp_16);
    default:
        return -1;
    }
}
