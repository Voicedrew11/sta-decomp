#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_ResetVectors_0_0013D1F0(void *arg0, u8 arg1);

void EnemyCmd_ResetVectors_1_00145610(u8 *arg0)
{
    Enemy_ResetVectors_0_0013D1F0(D_00201FA8->p, arg0[8]);
}
