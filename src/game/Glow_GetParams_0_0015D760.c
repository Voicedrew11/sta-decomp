#include "common.h"
void sceVu0CopyVector(s32, u8 *);              /* extern */
extern s32 D_00201F2C;
extern s32 D_0030D9A0[];

void Glow_GetParams_0_0015D760(s32 arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4) {
    u8 *temp_16;

    temp_16 = (u8 *) ((s32 *)((u8 *)D_0030D9A0 + (arg0 * 0x60)));
    sceVu0CopyVector(arg1, temp_16 + 0x40);
    sceVu0CopyVector(arg2, temp_16 + (D_00201F2C << 5) + 0x10);
    if (arg3 != NULL) {
        *arg3 = M2C_FIELD(temp_16, f32 *, 0x54);
    }
    if (arg4 != NULL) {
        *arg4 = M2C_FIELD(temp_16, f32 *, 0x58);
    }
}
