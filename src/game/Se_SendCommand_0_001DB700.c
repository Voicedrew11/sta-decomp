#include "common.h"

void SndDrv_CallArgs_2_001D8680(s32 a, s32 b, s32 c, ...);

void Se_SendCommand_0_001DB700(u32 a, u32 b)
{
    u32 t[2] = { 0 };
    t[a & 1] = 1 << (b % 24);
    SndDrv_CallArgs_2_001D8680(4, 1, 0x10700, t[0], t[1]);
}
