#include "m2c.h"
#include "actor.h"
void func_0014DAD0(s32);
M2C_UNK func_00123C40(s32 *, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_001B0020();                            /* static */
extern s32 D_004B4B90[];
extern s32 D_004B4B94[];
extern s32 D_004B4B98[];
extern s32 D_004B4B9C[];
extern s32 D_004B4BB0[];
extern s32 D_004B4BB4[];
extern s32 D_004B4BB8[];
extern s16 D_004B4BBC[];
extern s16 D_004B4BBE[];
extern s32 D_004B4BC0[];
extern s32 D_004B4BC4[];

void func_001B07B0(void) {
    if (D_004B4BC0[0] != 0) {
        func_0014DAD0(D_004B4BC0[0]);
        D_004B4BC0[0] = 0;
    }
    D_004B4BB8[0] = 0;
    D_004B4BC0[0] = 0;
    D_004B4BB4[0] = -1;
    D_004B4BB0[0] = -1;
    D_004B4BBC[0] = 0;
    D_004B4BC4[0] = 0;
    D_004B4BBE[0] = 0;
    D_004B4B90[0] = 0;
    D_004B4B94[0] = 0;
    D_004B4B98[0] = 0;
    D_004B4B9C[0] = 0;
    func_0014DB10((s32) func_001B0020);
    func_00123C40(D_004B4B90, 0, 0x40);
    D_004B4BB4[0] = -1;
    D_004B4BB0[0] = -1;
}
