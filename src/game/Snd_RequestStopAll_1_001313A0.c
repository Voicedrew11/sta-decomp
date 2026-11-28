#include "common.h"
extern u8 D_0022EC20[];
extern s8 D_0022EC22[];
extern u8 D_0022EC21[];
void Snd_RequestStopAll_1_001313A0(void);
void Snd_SetMasterVolume_1_001313C0(s32 v);
void Bgm_SetVolume_1_001D9650(u16 a, u16 b);
void Bgm_Resume_0_001D97A0(void);

/* Snd_RequestStopAll_1_001313A0 */
void Snd_RequestStopAll_1_001313A0(void) {
    if ((*D_0022EC20) != 0) {
        (*D_0022EC22) = 1;
    }
}

/* Snd_SetMasterVolume_1_001313C0 */
#define D_0022EC22 D_0022EC22__as_Snd_SetMasterVolume_1_001313C0
extern u8 D_0022EC22__as_Snd_SetMasterVolume_1_001313C0[];

void Snd_SetMasterVolume_1_001313C0(s32 v)
{
    if (v > 0x7F)
        v = 0x7F;
    if (v < 0)
        v = 0;
    Bgm_SetVolume_1_001D9650(v * 129, v * 129);
    Bgm_Resume_0_001D97A0();
    D_0022EC21[0] = v;
    D_0022EC20[0] = 1;
    D_0022EC22[0] = 0;
}
#undef D_0022EC22
