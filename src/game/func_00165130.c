#include "common.h"
extern s32 D_00201FA4;
extern void *D_00201FA8;

void func_00165130(s32 arg0, s32 arg1) {
    func_00165150(D_00201FA4, D_00201FA8, arg0 + ((arg1 & 0xFF) * 8) + 4);
}
