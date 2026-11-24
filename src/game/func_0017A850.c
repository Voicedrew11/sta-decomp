#include "m2c.h"

void func_0017A850(s8 *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_v1 < 0xC9) {
        func_001B0B30(temp_v1, M2C_FIELD(arg0, s16 *, 0x10));
    }
}
