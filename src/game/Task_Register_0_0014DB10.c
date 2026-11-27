#include "common.h"
void Task_SetCallback_1_001E0560(s32 *, s32);              /* extern */
extern s32 D_00201F20;
extern s32 D_002F0F40[];

void Task_Register_0_0014DB10(s32 arg0) {
    if (arg0 != 0) {
        D_002F0F40[D_00201F20] = arg0;
        D_00201F20 += 1;
        Task_SetCallback_1_001E0560(D_002F0F40, D_00201F20);
    }
}
