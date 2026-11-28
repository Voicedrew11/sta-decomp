#include "common.h"
void GameFlag_GetWordWrap_0_0013D540(u8 a, u8 b);
u16 GameFlag_GetHalf_0_0013D560(s32 a, u8 b);
void GameFlag_SetBit_2_0013D5C0(s32 a, s32 b);
s32 GameFlag_TestBit_2_0013D630(u8 a, u8 b);
void MapState_GetWord_1_001AA540(s32 a, s16 b);
void MapState_SetWord_1_001AA5D0(s32, s16, u32);

/* GameFlag_GetWordWrap_0_0013D540 */
void GameFlag_GetWordWrap_0_0013D540(u8 a, u8 b)
{
    MapState_GetWord_1_001AA540(a, (u8)b >> 5);
}

/* GameFlag_GetHalf_0_0013D560 */
#define MapState_GetWord_1_001AA540 MapState_GetWord_1_001AA540__as_GameFlag_GetHalf_0_0013D560
u32 MapState_GetWord_1_001AA540__as_GameFlag_GetHalf_0_0013D560(s32, s16);
u16 GameFlag_GetHalf_0_0013D560(s32 a, u8 b) {
    u16 r;
    if (b & 0x10) r = MapState_GetWord_1_001AA540((u8)a, b >> 5) >> 16;
    else r = MapState_GetWord_1_001AA540((u8)a, b >> 5);
    return r;
}
#undef MapState_GetWord_1_001AA540

/* GameFlag_SetBit_2_0013D5C0 */
#define MapState_GetWord_1_001AA540 MapState_GetWord_1_001AA540__as_GameFlag_SetBit_2_0013D5C0
u32 MapState_GetWord_1_001AA540__as_GameFlag_SetBit_2_0013D5C0(s32, s16);
void GameFlag_SetBit_2_0013D5C0(s32 a, s32 b) {
    s32 bb = b & 0xFF;
    s32 hi = bb >> 5;
    s32 aa = a & 0xFF;
    u32 v = MapState_GetWord_1_001AA540(aa, hi);
    v |= 1 << (bb & 0x1F);
    MapState_SetWord_1_001AA5D0(aa, hi, v);
}
#undef MapState_GetWord_1_001AA540

/* GameFlag_TestBit_2_0013D630 */
#define MapState_GetWord_1_001AA540 MapState_GetWord_1_001AA540__as_GameFlag_TestBit_2_0013D630
s32 MapState_GetWord_1_001AA540__as_GameFlag_TestBit_2_0013D630(s32 a, s16 b);

s32 GameFlag_TestBit_2_0013D630(u8 a, u8 b)
{
    return (MapState_GetWord_1_001AA540(a, b >> 5) & (1 << (b & 0x1F))) != 0;
}
#undef MapState_GetWord_1_001AA540
