#include "m2c.h"
M2C_UNK func_001A3F80(s32);                         /* extern */

void func_001A3C70(s8 *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_a0 == 0x16) {
        func_001A3F80(temp_a0);
        M2C_FIELD(arg0, s8 *, 8) = 5;
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x1F;
    }
}
