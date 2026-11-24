#include "m2c.h"
s32 func_00131600(M2C_UNK, M2C_UNK);                /* extern */

s32 func_001CA880(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return func_00131600(0x924, 0x7F);
    case 2:
        return func_00131600(0x927, 0x7F);
    case 3:
        return func_00131600(0x925, 0x7F);
    case 4:
        return func_00131600(0x926, 0x7F);
    default:
        return -1;
    }
}
