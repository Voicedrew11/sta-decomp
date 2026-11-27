#include "common.h"

void SndDrv_CallArgs_2_001D8680(s32 a, s32 b, s32 c, u16 d, u16 e);

void Strm_DrvSetMode_1_001D8CC0(u16 d, u16 e)
{
    SndDrv_CallArgs_2_001D8680(5, 1, 0x3060000, d, e);
}
