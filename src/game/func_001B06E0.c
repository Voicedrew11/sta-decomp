#include "m2c.h"
void func_001B5640(s32);
extern f32 D_004B4B90[];
extern f32 D_004B4B94[];
extern f32 D_004B4B98[];
extern s32 D_004B4B9C[];
extern s32 D_004B4BB0[];
extern s32 D_004B4BB4[];
extern s32 D_004B4BB8[];
extern s16 D_004B4BBC[];
extern s32 D_004B4BC4[];

void func_001B06E0(s32 arg0, f32 *arg1, s32 arg2) {
    if (D_004B4BB4[0] != arg0 && (D_004B4BB8[0] == 0 || arg2 != 0)) {
        if (D_004B4BBC[0] == 0 && D_004B4BB4[0] != -1) {
            func_001B5640(D_004B4BC4[0]);
        }
        D_004B4BB0[0] = arg0;
        D_004B4B90[0] = -arg1[0];
        D_004B4B94[0] = -arg1[1];
        D_004B4B98[0] = -arg1[2];
        D_004B4BB8[0] = arg2;
        D_004B4B9C[0] = 0;
    }
}
