#include "common.h"
void memcpy(s32, s32, s32);           /* extern */
extern s32 D_00201E10;

void func_001A94B0(s32 arg0) {
    if (arg0 != 0) {
        memcpy(D_00201E10, arg0, 0x10);
    }
}
