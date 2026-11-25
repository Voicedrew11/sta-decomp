#include "common.h"
u8 func_00143810(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_2;
    s32 temp_3;

    temp_2 = arg1 & 0xFF;
    temp_3 = arg2 & 0xFF;
    if (temp_2 == temp_3) {
        return 0xFFU;
    }
    return M2C_FIELD((temp_3 + ((temp_2 << 8) + arg0)), u8 *, 0x10);
}
