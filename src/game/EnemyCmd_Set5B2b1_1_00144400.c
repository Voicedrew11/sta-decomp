#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_Set5B2b1_1_0013E860(void *arg0, u8 arg1);

void EnemyCmd_Set5B2b1_1_00144400(u8 *arg0)
{
    Enemy_Set5B2b1_1_0013E860(D_00201FA8->p, arg0[8]);
}
