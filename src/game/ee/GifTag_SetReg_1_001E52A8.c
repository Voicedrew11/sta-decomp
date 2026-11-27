#include "common.h"
void *GifTag_SetReg_1_001E52A8(void *arg0, s64 arg1, s64 arg2) {
    M2C_FIELD(arg0, s64 *, 0) = arg2;
    M2C_FIELD(arg0, s64 *, 8) = arg1;
    return arg0 + 0x10;
}
