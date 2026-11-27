#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_Set5B0b0_1_0013EC30(void *arg0, u8 arg1);

void EnemyCmd_Set5B0b0_1_00144E30(u8 *arg0)
{
    Enemy_Set5B0b0_1_0013EC30(D_00201FA8->p, arg0[8]);
}
