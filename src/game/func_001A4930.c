#include "m2c.h"
extern s32 D_00202270;

void func_001A4930(s8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0xC) = 0;
    if (M2C_FIELD(arg0, s32 *, 0) == 0x19) {
        D_00202270 = 1;
    }
    if ((M2C_FIELD(arg0, s32 *, 0) == 0x16) && (D_00202270 == 0)) {
        M2C_FIELD(arg0, s8 *, 8) = 0x12;
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x1F;
        func_0012C0C0();
    }
}
