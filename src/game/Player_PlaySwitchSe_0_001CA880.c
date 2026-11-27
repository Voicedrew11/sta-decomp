#include "common.h"
s32 Snd_PlaySe_3_00131600(s32, s32);                /* extern */

s32 Player_PlaySwitchSe_0_001CA880(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return Snd_PlaySe_3_00131600(0x924, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600(0x927, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600(0x925, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600(0x926, 0x7F);
    default:
        return -1;
    }
}
