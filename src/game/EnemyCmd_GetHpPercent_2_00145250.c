#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
s8 *Script_GetArgPtr_2_00165130(s32 a, s32 b);
s8 Enemy_GetHpPercent_2_0013F620(void *p);

void EnemyCmd_GetHpPercent_2_00145250(s32 a)
{
    void *p = D_00201FA8->p;
    s8 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Enemy_GetHpPercent_2_0013F620(p);
}
