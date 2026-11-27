#include "common.h"

void MapState_GetWord_1_001AA540(s32 a, s16 b);

void GameFlag_GetWordWrap_0_0013D540(u8 a, u8 b)
{
    MapState_GetWord_1_001AA540(a, (u8)b >> 5);
}
