#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_Set5B2b0_1_0013E890(void *arg0, u8 arg1);

void EnemyCmd_Set5B2b0_1_00144D70(u8 *arg0)
{
    Enemy_Set5B2b0_1_0013E890(D_00201FA8->p, arg0[8]);
}
