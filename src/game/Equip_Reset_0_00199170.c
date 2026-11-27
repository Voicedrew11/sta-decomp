#include "common.h"
extern s32 D_00201D48;
extern s32 D_002021B0;
extern s32 D_004A28C0[];

void Equip_Reset_0_00199170(void) {
    (*D_004A28C0) = 0;
    D_002021B0 = 0;
    D_00201D48 = 6;
}
