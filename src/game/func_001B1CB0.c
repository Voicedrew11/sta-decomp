#include "m2c.h"

s32 func_001B1CB0(s32 arg0, s8 *arg1, s32 *arg2) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x34);
    if (temp_v0 == 0) {
        return 0;
    }
    if (M2C_FIELD(arg1, s32 *, 0x30) != arg0) {
        return 0;
    }
    if (arg2 != NULL) {
        *arg2 = M2C_FIELD(arg1, s32 *, 0x38);
    }
    return temp_v0;
}
