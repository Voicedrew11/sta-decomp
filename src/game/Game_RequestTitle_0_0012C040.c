#include "common.h"
void Vibe_StopAll_1_00160300();                            /* extern */
extern s32 D_00201C28;
extern s32 D_00201E98;
extern s32 D_00201E9C;
extern s32 D_00201EA4;
extern s32 D_00201EA8;

void Game_RequestTitle_0_0012C040(void) {
    D_00201EA4 = 0;
    D_00201C28 = 0x29;
    D_00201E9C = 0;
    D_00201EA8 = 2;
    D_00201E98 = 1;
    Vibe_StopAll_1_00160300();
}
