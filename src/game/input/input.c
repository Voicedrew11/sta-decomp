#include "common.h"
void Input_Poll_2_0015FC10(void) {
    s32 var_16;

    Pad_UpdateAll_3_001D7350();
    var_16 = 0;
    do {
        Pad_SetEnabled_0_001D7D90(var_16, 0, 1);
        Input_Update_2_0015F540(var_16);
        var_16 += 1;
    } while ((u32) var_16 < 2U);
}
