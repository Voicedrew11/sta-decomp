#include "common.h"
void sceVu0CopyVector(u8 *, u8 *);               /* extern */
extern s32 D_0030D9A0[];

void Glow_SetParams_0_0015D800(s32 arg0, u8 *arg1, u8 *arg2, f32 fparg0, f32 fparg1) {
    f32 var_f21;
    s32 var_20;
    u8 *temp_16;
    u8 *var_19;

    temp_16 = (u8 *) ((s32 *)((u8 *)D_0030D9A0 + (arg0 * 0x60)));
    var_f21 = fparg1;
    if (!(M2C_FIELD(temp_16, u8 *, 0x50) & 1)) {
        var_f21 = -1.0f;
    }
    var_20 = 0;
    var_19 = (u8 *) (temp_16);
    do {
        sceVu0CopyVector(var_19, arg1);
        sceVu0CopyVector(var_19 + 0x10, arg2);
        M2C_FIELD(var_19, f32 *, 0xC) = (f32) (-1.0f / (fparg0 * fparg0));
        var_20 += 1;
        M2C_FIELD(var_19, f32 *, 0x1C) = var_f21;
        var_19 += 0x20;
    } while (var_20 < 2);
    sceVu0CopyVector(temp_16 + 0x40, temp_16);
    M2C_FIELD(temp_16, f32 *, 0x54) = fparg0;
    M2C_FIELD(temp_16, f32 *, 0x58) = var_f21;
}
