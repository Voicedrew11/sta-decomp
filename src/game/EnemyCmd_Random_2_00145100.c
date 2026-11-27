#include "common.h"

s8 *Script_GetArgPtr_2_00165130(void *a, s32 b);
s8 Rand_Range_3_0013D500(u8 v);

void EnemyCmd_Random_2_00145100(u8 *a)
{
    s8 *p = Script_GetArgPtr_2_00165130(a, 0);
    *p = Rand_Range_3_0013D500(a[0x10]);
}
