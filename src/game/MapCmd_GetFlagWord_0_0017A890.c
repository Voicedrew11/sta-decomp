#include "common.h"

u8 *Script_GetArgPtr_2_00165130(u8 *o, s32 b);
u32 MapState_GetWord_1_001AA540(u8 a, s16 b);

void MapCmd_GetFlagWord_0_0017A890(u8 *o)
{
    u8 *p = Script_GetArgPtr_2_00165130(o, 2);
    u8 a = o[8];
    s32 b;
    if (a <= 200) {
        b = o[0x10];
        if (b <= 32)
            *p = MapState_GetWord_1_001AA540(a, (u32)b >> 2) >> ((b % 4) * 8);
    }
}
