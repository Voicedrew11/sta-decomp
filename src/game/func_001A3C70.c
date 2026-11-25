#include "common.h"
void func_001A3C70(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0x16) {
        func_001A3F80();
        M2C_FIELD(arg0, s8 *, 8) = 5;
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x1F;
    }
}
