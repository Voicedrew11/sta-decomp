#include "common.h"
void func_0017A850(void *arg0) {
    s32 temp_3;

    temp_3 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_3 < 0xC9) {
        func_001B0B30(temp_3, M2C_FIELD(arg0, s16 *, 0x10));
    }
}
