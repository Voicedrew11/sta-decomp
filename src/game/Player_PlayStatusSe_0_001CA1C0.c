#include "common.h"
s32 Snd_PlaySe_3_00131600(s32, s32);                /* extern */

s32 Player_PlayStatusSe_0_001CA1C0(u32 arg0) {
    switch (arg0) {
    case 0:
        return Snd_PlaySe_3_00131600(0x131, 0x7F);
    case 1:
        return Snd_PlaySe_3_00131600(0x12F, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600(0x12D, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600(0x137, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600(0x133, 0x7F);
    case 5:
        return Snd_PlaySe_3_00131600(0x135, 0x7F);
    case 7:
        return Snd_PlaySe_3_00131600(0x139, 0x7F);
    default:
        return -1;
    }
}
