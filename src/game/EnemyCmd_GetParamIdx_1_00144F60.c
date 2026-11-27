#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
s16 *Script_GetArgPtr_2_00165130(s32 a, s32 b);
s16 Enemy_GetCurrentParamIdx_0_0013E110(void *p);

void EnemyCmd_GetParamIdx_1_00144F60(s32 a)
{
    void *p = D_00201FA8->p;
    s16 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Enemy_GetCurrentParamIdx_0_0013E110(p);
}
