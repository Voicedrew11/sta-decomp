#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_BreakPart_0_0013F210(void *arg0, u8 arg1, s32 arg2);

void EnemyCmd_BreakPart_1_00144E10(u8 *arg0)
{
    Enemy_BreakPart_0_0013F210(D_00201FA8->p, arg0[8], 1);
}
