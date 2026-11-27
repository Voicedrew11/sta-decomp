#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
f32 *Script_GetArgPtr_2_00165130(void *o, s32 b);
void Enemy_CopyPosition_2_00140470(void *p, f32 *v);

void EnemyCmd_GetPosition_2_00144970(void *o)
{
    void *q = D_00201FA8->p;
    f32 *x = Script_GetArgPtr_2_00165130(o, 0);
    f32 *y = Script_GetArgPtr_2_00165130(o, 1);
    f32 *z = Script_GetArgPtr_2_00165130(o, 2);
    f32 v[4];
    Enemy_CopyPosition_2_00140470(q, v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}
