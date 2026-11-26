#include "m2c.h"
s32 func_001B19A0(s32);                             /* extern */
s8 *func_001B40F0(s32, s32);                      /* extern */
M2C_UNK func_001B4100(s32);                         /* extern */

void func_0017B4D0(s8 *arg0) {
    s32 temp_s0;
    s8 *temp_v0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 8);
    temp_v0 = func_001B40F0(func_001B19A0(temp_s0), M2C_FIELD(arg0, s32 *, 0x10));
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x18);
        M2C_FIELD(temp_v0, f32 *, 0x14) = (f32) M2C_FIELD(arg0, f32 *, 0x20);
        M2C_FIELD(temp_v0, f32 *, 0x18) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
        M2C_FIELD(temp_v0, f32 *, 0x1C) = (f32) M2C_FIELD(arg0, f32 *, 0x30);
        M2C_FIELD(temp_v0, f32 *, 0x30) = (f32) M2C_FIELD(arg0, f32 *, 0x38);
        M2C_FIELD(temp_v0, f32 *, 0x34) = (f32) M2C_FIELD(arg0, f32 *, 0x40);
        M2C_FIELD(temp_v0, f32 *, 0x38) = (f32) M2C_FIELD(arg0, f32 *, 0x48);
        M2C_FIELD(temp_v0, f32 *, 0x3C) = (f32) M2C_FIELD(arg0, f32 *, 0x50);
        M2C_FIELD(temp_v0, f32 *, 0x40) = (f32) M2C_FIELD(arg0, f32 *, 0x58);
        M2C_FIELD(temp_v0, f32 *, 0x44) = (f32) M2C_FIELD(arg0, f32 *, 0x60);
        M2C_FIELD(temp_v0, f32 *, 0x48) = (f32) M2C_FIELD(arg0, f32 *, 0x68);
        M2C_FIELD(temp_v0, f32 *, 0x4C) = (f32) M2C_FIELD(arg0, f32 *, 0x70);
        M2C_FIELD(temp_v0, f32 *, 0x50) = (f32) M2C_FIELD(arg0, f32 *, 0x78);
        M2C_FIELD(temp_v0, f32 *, 0x54) = (f32) M2C_FIELD(arg0, f32 *, 0x80);
        func_001B4100(func_001B19A0(temp_s0));
    }
}
