#include "m2c.h"
extern s32 D_001FD358[];

s32 *func_00196C50(s32 arg0, M2C_UNK arg1) {
    s32 *var_v0;

    if (arg0 < 0) {
        return D_001FD358;
    }
    if (func_001A9EC0(/* s32+0x0 */ ((s16) arg0), /* s32+0x4 */ arg1) != 0) {
        var_v0 = (int *)(func_00195970((s32) arg0));
    } else {
        var_v0 = D_001FD358;
    }
    return var_v0;
}
