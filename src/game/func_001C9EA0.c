#include "m2c.h"
void func_00123C40(s8 *, s32, s32);
void func_001CBCD0(s32);
void func_001CBED0(s32, s32, s32);
void func_001CCF00(s32, s32);
extern s8 *D_00201E20;

void func_001C9EA0(void) {
    s32 i;
    func_00123C40(D_00201E20, 0, 0x10A0);
    M2C_FIELD(D_00201E20, s16 *, 0x20) = 0xF;
    M2C_FIELD(D_00201E20, s16 *, 0x22) = 0xC;
    M2C_FIELD(D_00201E20, s16 *, 0x24) = 0xC;
    M2C_FIELD(D_00201E20, s16 *, 0x26) = 0xA;
    M2C_FIELD(D_00201E20, s16 *, 0x28) = 0xC;
    M2C_FIELD(D_00201E20, s16 *, 0x2A) = 8;
    M2C_FIELD(D_00201E20, s16 *, 0x2C) = 8;
    M2C_FIELD(D_00201E20, s16 *, 0x2E) = 8;
    M2C_FIELD(D_00201E20, s16 *, 4) = 0x270F;
    M2C_FIELD(D_00201E20, s16 *, 6) = 0x270F;
    for (i = 0; i < 10; i++) {
        M2C_FIELD(D_00201E20 + i * 2, s16 *, 0x80) = -1;
    }
    func_001CBED0(0x14, 4, 0);
    func_001CBCD0(0x3B6);
    func_001CCF00(0, 0x3B6);
}
