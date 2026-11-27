#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_Set5B3b6_1_0013E710(void *p, s32 v);
void Enemy_Set5B6b1_1_0013E6F0(void *p, s32 v);

void EnemyCmd_SetHiddenFlags_0_00144370(u8 *o)
{
    void *p = D_00201FA8->p;
    u8 a = o[8];
    u8 b = o[0x10];
    if (a)
        Enemy_Set5B3b6_1_0013E710(p, 1);
    if (b)
        Enemy_Set5B6b1_1_0013E6F0(p, 1);
}
