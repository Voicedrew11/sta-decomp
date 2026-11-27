#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
s8 *Script_GetArgPtr_2_00165130(s32 a, s32 b);
s8 Enemy_Get5B0m1_1_0013EC50(void *p);

void EnemyCmd_Get5B0b0_1_001451A0(s32 a)
{
    void *p = D_00201FA8->p;
    s8 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Enemy_Get5B0m1_1_0013EC50(p);
}
