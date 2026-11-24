#include "m2c.h"
extern M2C_UNK D_00201E80;
s32 func_00169B50(s32, s32, s32, s32);
void func_001029D0(s32, s32, s8 *);
void func_00173FD0(f32 *, s32, s32, f32 *);
void func_001677C0(s32, f32 *);

void func_001B0D60(s16 arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 mtx[16];
    f32 scale[4] __attribute__((aligned(16)));
    s32 var_v1;
    s32 var_v1_2;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *o;
    s32 h;

    o = NULL;
    if (M2C_FIELD(&D_00201E80, s8 ***, 8) != NULL) {
        var_v1 = (M2C_FIELD(*M2C_FIELD(&D_00201E80, s8 ***, 8), u8 *, 0x1D8) & 1) != 0;
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        temp_a1 = *M2C_FIELD(&D_00201E80, s8 ***, 8);
        if (M2C_FIELD(temp_a1, s32 *, 0) == arg0) {
            o = temp_a1;
        }
    }
    if (M2C_FIELD(&D_00201E80, s8 ***, 0xC) != NULL) {
        var_v1_2 = (M2C_FIELD(*M2C_FIELD(&D_00201E80, s8 ***, 0xC), u8 *, 0x1D8) & 1) != 0;
    } else {
        var_v1_2 = 0;
    }
    if (var_v1_2 != 0) {
        temp_a1_2 = *M2C_FIELD(&D_00201E80, s8 ***, 0xC);
        if (M2C_FIELD(temp_a1_2, s32 *, 0) == arg0) {
            o = temp_a1_2;
        }
    }
    if (arg1 <= 0 || arg1 > 0x3FF) {
        return;
    }
    h = func_00169B50(arg1, 0, 0, 0);
    if (h != 0) {
        if (o != NULL) {
            func_001029D0(arg2, arg2, o + 0x10);
        }
        scale[2] = 1.0f;
        scale[1] = 1.0f;
        scale[0] = 1.0f;
        func_00173FD0(mtx, arg2, arg3, scale);
        func_001677C0(h, mtx);
    }
}
