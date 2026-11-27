#include "common.h"

void SndDrv_CallArgs_2_001D8680(s32 a, s32 b, s32 c, ...);

void SndDrv_SetReverb_0_001D8F10(s32 a, s32 b, s32 c)
{
    SndDrv_CallArgs_2_001D8680(3, 1, 0x20D0000, a, b, c);
}
