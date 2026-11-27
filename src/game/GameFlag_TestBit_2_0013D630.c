#include "common.h"

s32 MapState_GetWord_1_001AA540(s32 a, s16 b);

s32 GameFlag_TestBit_2_0013D630(u8 a, u8 b)
{
    return (MapState_GetWord_1_001AA540(a, b >> 5) & (1 << (b & 0x1F))) != 0;
}
