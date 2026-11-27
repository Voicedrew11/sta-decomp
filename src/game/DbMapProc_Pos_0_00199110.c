#include "common.h"
void DbMapProc_Pos_0_00199110(s32 arg0, void *arg1, void *arg2) {
    void *sp4C;

    UiAnim_Get_1_0017F840(0, &sp4C);
    M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg2, f32 *, 8) - (f32) arg0);
}
