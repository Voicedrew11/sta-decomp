#include "common.h"

s8 *Script_GetArgPtr_2_00165130(s32 a, s32 b);
s8 Save_GetByte2E_0_001AA740(void);

void EnemyCmd_GetGlobal_0_001438F0(s32 a)
{
    s8 *p = Script_GetArgPtr_2_00165130(a, 0);
    *p = Save_GetByte2E_0_001AA740();
}
