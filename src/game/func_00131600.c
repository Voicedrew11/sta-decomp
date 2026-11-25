#include "common.h"
extern void *D_00201ED0;

void func_00131600(s32 arg0, s32 arg1) {
    M2C_FIELD(D_00201ED0, s32 *, 0x30) = arg0;
    M2C_FIELD(D_00201ED0, s8 *, 0xE) = 0;
    M2C_FIELD(D_00201ED0, s16 *, 0xA) = (s16) (arg1 & 0xFF);
    M2C_FIELD(D_00201ED0, s16 *, 8) = (s16) M2C_FIELD(D_00201ED0, s16 *, 0xA);
    M2C_FIELD(D_00201ED0, s32 *, 0x20) = 0;
    M2C_FIELD(D_00201ED0, s32 *, 0x34) = 0;
    func_00131640();
}
