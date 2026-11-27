#include "common.h"
s32 Pool_GetBlockUsable_1_00128830(void *arg0) {
    s32 var_2;

    if (M2C_FIELD(arg0, u8 *, 0x18) & 1) {
        if ((M2C_FIELD(arg0, s32 *, 0x10) == 1) && (M2C_FIELD(arg0, s32 *, 0x14) == 0)) {
            return 0;
        }
        var_2 = M2C_FIELD(arg0, s32 *, 8) - 0x3F;
        goto block_10;
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) == 1) {
        return 0;
    }
    var_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x28), s32 *, 8) - 0x3F;
block_10:
    if (var_2 < 0) {
        var_2 = 0;
    }
    return var_2;
}
