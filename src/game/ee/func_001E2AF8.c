#include "common.h"
extern void *D_00201E60;

void func_001E2AF8(s32 arg0) {
    M2C_FIELD(D_00201E60, s32 *, 0x54) = (s32) (arg0 != 0);
}
