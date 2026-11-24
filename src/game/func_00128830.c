#include "m2c.h"

s32 func_00128830(s8 *arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, u8 *, 0x18) & 1) {
        if ((M2C_FIELD(arg0, s32 *, 0x10) == 1) && (M2C_FIELD(arg0, s32 *, 0x14) == 0)) {
            return 0;
        }
        var_v0 = M2C_FIELD(arg0, s32 *, 8) - 0x3F;
        goto block_10;
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) == 1) {
        return 0;
    }
    var_v0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x28), s32 *, 8) - 0x3F;
block_10:
    if (var_v0 < 0) {
        var_v0 = 0;
    }
    return var_v0;
}
