#include "m2c.h"
extern M2C_UNK D_001FD388[];

M2C_UNK *func_00197F30(s32 arg0, M2C_UNK arg1) {
    s32 var_v0;

    if (arg0 < 0) {
        return D_001FD388;
    }
    if (func_001A9B40(/* s32+0x0 */ ((s16) arg0), /* s32+0x4 */ arg1) != 0) {
        var_v0 = func_0019D510((s32) arg0);
    } else {
        var_v0 = (s32) D_001FD388;
    }
    return (M2C_UNK *) var_v0;
}
