#include "common.h"
s32 func_00131600(s32, s32);                    /* extern */

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
