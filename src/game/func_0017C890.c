#include "m2c.h"
M2C_UNK func_0012C110(M2C_UNK);                     /* extern */

void func_0017C890(s8 *arg0) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_s0 == 1) {
        func_0012C110(0xA);
    }
    if (temp_s0 == 2) {
        func_0012C110(0x1F);
    }
    if (temp_s0 == 3) {
        func_0012C110(0x80);
    }
    if (temp_s0 == 4) {
        func_0012C110(0x81);
    }
    if (temp_s0 == 0xF) {
        func_0012C110(0x25);
    }
}
