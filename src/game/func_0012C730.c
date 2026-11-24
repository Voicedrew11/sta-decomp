#include "m2c.h"
M2C_UNK func_001D9650(u16, u16);                    /* extern */
extern u8 D_0022EBD9[];
extern u8 D_0022EC20[];

void func_0012C730(s32 arg0) {
    u16 temp_s0;

    D_0022EBD9[0] = arg0 & 0x7F;
    temp_s0 = (D_0022EBD9[0] * 0x81) & 0xFFFF;
    func_001303D0(temp_s0);
    if (D_0022EC20[0] != 0) {
        func_001D9650(temp_s0, temp_s0);
    }
}
