#include "common.h"
extern s32 D_003172E0[];

void func_0015FE20(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    u8 *var_4_2;
    s32 var_5;
    s32 *var_4;

    var_5 = 0;
    var_4 = (s32 *) (D_003172E0);
loop_1:
    if (M2C_FIELD(var_4, u8 *, 0x19) == 0) {
        var_4_2 = (u8 *) ((s32 *)((u8 *)D_003172E0 + (var_5 << 5)));
    } else {
        var_5 += 1;
        var_4 = (s32*)((u8 *)var_4 + 0x20);
        if (var_5 >= 0x10) {
            var_4_2 = (u8 *) (NULL);
        } else {
            goto loop_1;
        }
    }
    if (var_4_2 != NULL) {
        M2C_FIELD(var_4_2, f32 *, 0) = fparg0;
        M2C_FIELD(var_4_2, f32 *, 4) = fparg1;
        M2C_FIELD(var_4_2, f32 *, 8) = fparg2;
        M2C_FIELD(var_4_2, f32 *, 0xC) = fparg3;
        M2C_FIELD(var_4_2, f32 *, 0x10) = (f32) (16.0f * fparg4);
        M2C_FIELD(var_4_2, s32 *, 0x14) = 0;
        M2C_FIELD(var_4_2, s8 *, 0x18) = 0;
        M2C_FIELD(var_4_2, s8 *, 0x19) = 1;
    }
}
