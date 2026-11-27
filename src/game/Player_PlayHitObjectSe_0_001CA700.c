#include "common.h"
s32 Snd_PlaySe_3_00131600(s32, s32);                    /* extern */

s32 Player_PlayHitObjectSe_0_001CA700(s32 arg0, s32 arg1) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return Snd_PlaySe_3_00131600(arg1 + 0x952, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600(arg1 + 0x952, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600(arg1 + 0x952, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600(arg1 + 0x952, 0x7F);
    default:
        return -1;
    }
}
