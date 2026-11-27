#include "common.h"
u8 *MapObj_Find_1_001B19A0(s32);                             /* extern */
u8 *Map_GetFogEntry_0_001B40F0(u8 *, s32);                     /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x8, 0xc, 0x10, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44], gap at: 0x18. */
void MapCmd_RotateObject_0_0017B410(u8 *arg0) {
    u8 *temp_2;
    s32 temp_16;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;

    temp_f24 = M2C_FIELD(arg0, f32 *, 0x18);
    temp_16 = M2C_FIELD(arg0, s32 *, 8);
    temp_f23 = M2C_FIELD(arg0, f32 *, 0x20);
    temp_f22 = M2C_FIELD(arg0, f32 *, 0x28);
    temp_f21 = M2C_FIELD(arg0, f32 *, 0x30);
    temp_f20 = M2C_FIELD(arg0, f32 *, 0x38);
    temp_2 = (u8 *) (Map_GetFogEntry_0_001B40F0(MapObj_Find_1_001B19A0(temp_16), M2C_FIELD(arg0, s32 *, 0x10)));
    if (temp_2 != NULL) {
        M2C_FIELD(temp_2, f32 *, 0x40) = temp_f24;
        M2C_FIELD(temp_2, f32 *, 0x44) = temp_f23;
        M2C_FIELD(temp_2, f32 *, 0x48) = temp_f22;
        M2C_FIELD(temp_2, f32 *, 0x4C) = temp_f21;
        if (temp_f20 != -100.0f) {
            M2C_FIELD(temp_2, f32 *, 0x50) = temp_f20;
        }
        Map_UpdateFog_0_001B4100(MapObj_Find_1_001B19A0(temp_16));
    }
}
