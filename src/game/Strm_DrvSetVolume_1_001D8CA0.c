#include "common.h"

void SndDrv_CallArgs_2_001D8680(s32 a, s32 b, s32 c, ...);

void Strm_DrvSetVolume_1_001D8CA0(s32 a, u16 b, u16 c)
{
    SndDrv_CallArgs_2_001D8680(5, 1, 0x3090000, a, b, c);
}
