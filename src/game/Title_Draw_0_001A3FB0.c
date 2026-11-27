#include "common.h"
extern s32 D_004A4394[];
extern u8 D_004A43A2[];

void Title_Draw_0_001A3FB0(void) {
    if ((*D_004A4394) == 2) {
        if ((*D_004A43A2) == 0xD) {
            goto block_3;
        }
    } else {
block_3:
        Menu_SetFlags_0_0018A310(4);
    }
    UiAnim_UpdateAll_1_0017F5C0();
    Menu_DrawBackground_0_00187B20(0);
}
