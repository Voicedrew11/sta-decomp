#include "common.h"
s32 func_001B1CB0(s32 arg0, void *arg1, s32 *arg2) {
    s32 temp_2;

    temp_2 = M2C_FIELD(arg1, s32 *, 0x34);
    if (temp_2 == 0) {
        return 0;
    }
    if (M2C_FIELD(arg1, s32 *, 0x30) != arg0) {
        return 0;
    }
    if (arg2 != NULL) {
        *arg2 = M2C_FIELD(arg1, s32 *, 0x38);
    }
    return temp_2;
}
