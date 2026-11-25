#include "common.h"
extern void *D_00201FA8;

void func_00143D10(void *arg0) {
    func_0013E3F0(M2C_FIELD(D_00201FA8, s32 *, 0x154), (s32) M2C_FIELD(arg0, u8 *, 8), (M2C_FIELD(arg0, u8 *, 0x10) | ((M2C_FIELD(arg0, u8 *, 0x18) * 8) | ((M2C_FIELD(arg0, u8 *, 0x20) << 6) | ((M2C_FIELD(arg0, u8 *, 0x30) << 0xA) | (M2C_FIELD(arg0, u8 *, 0x28) << 9))))) & 0xFFFF);
}
