#include "common.h"
void func_00194F60(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0x16) {
        M2C_FIELD(arg0, s8 *, 8) = 0xA;
        func_00189ED0(5);
        func_00193850(1);
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x1A;
    }
}
