#include "m2c.h"
#include "actor.h"
void func_0014DAD0(s32);
extern s32 D_004B4BB0[];
extern s32 D_004B4BB4[];
extern s32 D_004B4BB8[];
extern s16 D_004B4BBC[];
extern s16 D_004B4BBE[];
extern s32 D_004B4BC0[];
extern s32 D_004B4BC4[];

void func_001B03E0(void) {
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
}
