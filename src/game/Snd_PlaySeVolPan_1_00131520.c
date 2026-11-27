#include "common.h"
extern void *D_00201ED0;

void Snd_PlaySeVolPan_1_00131520(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(D_00201ED0, s32 *, 0x30) = arg0;
    M2C_FIELD(D_00201ED0, s32 *, 0x20) = 0;
    M2C_FIELD(D_00201ED0, s32 *, 0x34) = arg2;
    M2C_FIELD(D_00201ED0, s32 *, 0x38) = arg3;
    M2C_FIELD(D_00201ED0, s8 *, 0xE) = 4;
    M2C_FIELD(D_00201ED0, s16 *, 0xA) = (s16) (arg1 & 0xFF);
    Snd_StartRequest_2_00131640();
}
