#include "common.h"

extern u8 D_0022EC20[], D_0022EC21[], D_0022EC22[];
void Bgm_SetVolume_1_001D9650(u16 a, u16 b);
void Bgm_Resume_0_001D97A0(void);

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
