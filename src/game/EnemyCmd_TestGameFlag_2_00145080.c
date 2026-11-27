#include "common.h"

s8 *Script_GetArgPtr_2_00165130(u8 *o, s32 b);
s8 GameFlag_TestBit_2_0013D630(u8 a, u8 b);

void EnemyCmd_TestGameFlag_2_00145080(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    s8 *p = Script_GetArgPtr_2_00165130(o, 2);
    *p = GameFlag_TestBit_2_0013D630(a, b);
}
