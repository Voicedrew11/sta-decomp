#include "common.h"
extern s32 D_004A1068[];
extern s32 D_004A106C[];

void SaveMenu_Retry_0_0018E0B0(void *arg0) {
    SaveMenu_UpdateCardFlags_1_0018E120(NULL, (s32) D_004A1068);
    SaveMenu_UpdateCardFlags_1_0018E120((u8 *)1, (s32) D_004A106C);
    if (M2C_FIELD(arg0, s32 *, 4) & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0xA) = 2;
        Snd_PlaySe_3_00131600(0x67, (s32) M2C_FIELD(arg0, u8 *, 0xE));
    }
}
