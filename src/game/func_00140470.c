#include "common.h"
void sceVu0CopyVector(s32, s32);                 /* extern */

void func_00140470(void *arg0, s32 arg1) {
    sceVu0CopyVector(arg1, M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198));
}
