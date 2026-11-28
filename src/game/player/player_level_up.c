#include "m2c.h"
M2C_UNK Snd_PlaySe_3_00131600(M2C_UNK, M2C_UNK);            /* extern */

void Player_PlayLevelUpSe_0_001C9FB0(s32 arg0) {
    if (arg0 != 0) {
        Snd_PlaySe_3_00131600(0x140, 0x7F);
        return;
    }
    Snd_PlaySe_3_00131600(0x13C, 0x7F);
}
