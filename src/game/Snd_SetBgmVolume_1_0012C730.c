#include "common.h"
extern u8 D_0022EBD9[];
extern u8 D_0022EC20[];

void Snd_SetBgmVolume_1_0012C730(s32 arg0) {
    u16 temp_16;

    (*D_0022EBD9) = arg0 & 0x7F;
    temp_16 = ((*D_0022EBD9) * 0x81) & 0xFFFF;
    Strm_SetVolume_2_001303D0(temp_16);
    if ((*D_0022EC20) != 0) {
        Bgm_SetVolume_1_001D9650(temp_16, temp_16);
    }
}
