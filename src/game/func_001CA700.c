#include "m2c.h"
s32 func_00131600(s32, M2C_UNK);                    /* extern */

s32 func_001CA700(s32 arg0, s32 arg1) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return func_00131600(arg1 + 0x952, 0x7F);
    case 2:
        return func_00131600(arg1 + 0x952, 0x7F);
    case 3:
        return func_00131600(arg1 + 0x952, 0x7F);
    case 4:
        return func_00131600(arg1 + 0x952, 0x7F);
    default:
        return -1;
    }
}

s32 func_001CA7B0(s32 arg0, s32 arg1) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return func_00131600((arg1 * 4) + 0x928, 0x7F);
    case 2:
        return func_00131600((arg1 * 4) + 0x92B, 0x7F);
    case 3:
        return func_00131600((arg1 * 4) + 0x929, 0x7F);
    case 4:
        return func_00131600((arg1 * 4) + 0x92A, 0x7F);
    default:
        return -1;
    }
}
