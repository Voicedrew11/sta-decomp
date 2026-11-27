#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_SetDeadFlag_0_0013EEB0(void *arg0, u8 arg1);

void EnemyCmd_SetDead_1_001450D0(u8 *arg0)
{
    Enemy_SetDeadFlag_0_0013EEB0(D_00201FA8->p, arg0[8]);
}
