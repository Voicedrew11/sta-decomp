#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_Kill_1_0013EF80(void *arg0, u8 arg1);

void EnemyCmd_Kill_1_00144360(u8 *arg0)
{
    Enemy_Kill_1_0013EF80(D_00201FA8->p, arg0[8]);
}
