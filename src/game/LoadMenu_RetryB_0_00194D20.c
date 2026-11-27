#include "common.h"
extern s32 D_004A1198[];
extern s32 D_004A119C[];

void LoadMenu_RetryB_0_00194D20(void *arg0) {
    LoadMenu_UpdateCardFlags_1_00194D90(NULL, (s32) D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90((u8 *)1, (s32) D_004A119C);
    if (M2C_FIELD(arg0, s32 *, 4) & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0xA) = 2;
        Snd_PlaySe_3_00131600(0x67, (s32) M2C_FIELD(arg0, u8 *, 0xE));
    }
}
