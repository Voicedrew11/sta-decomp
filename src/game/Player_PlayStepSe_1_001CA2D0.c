#include "common.h"
s32 Snd_PlaySe_3_00131600(s32, s32);                /* extern */

s32 Player_PlayStepSe_1_001CA2D0(u32 arg0) {
    switch (arg0) {
    case 0:
        return Snd_PlaySe_3_00131600(0x8EA, 0x7F);
    case 1:
        return Snd_PlaySe_3_00131600(0x8EB, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600(0x8EC, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600(0x8EE, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600(0x8ED, 0x7F);
    case 5:
        return Snd_PlaySe_3_00131600(0x8F0, 0x7F);
    case 6:
        return Snd_PlaySe_3_00131600(0x8F1, 0x7F);
    case 7:
        return Snd_PlaySe_3_00131600(0x8F3, 0x7F);
    case 8:
        return Snd_PlaySe_3_00131600(0x8EF, 0x7F);
    case 9:
        return Snd_PlaySe_3_00131600(0x8F5, 0x7F);
    case 10:
        return Snd_PlaySe_3_00131600(0x8F6, 0x7F);
    case 11:
        return Snd_PlaySe_3_00131600(0x8F4, 0x7F);
    case 12:
        return Snd_PlaySe_3_00131600(0x8EA, 0x7F);
    case 13:
        return Snd_PlaySe_3_00131600(0x8EC, 0x7F);
    case 14:
        return Snd_PlaySe_3_00131600(0x8F2, 0x7F);
    case 16:
        return Snd_PlaySe_3_00131600(0x127, 0x7F);
    default:
        return -1;
    }
}
