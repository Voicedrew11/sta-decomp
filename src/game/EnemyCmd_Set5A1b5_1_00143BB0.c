#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_Set5A1b5_1_0013EE90(void *arg0, u8 arg1);

void EnemyCmd_Set5A1b5_1_00143BB0(u8 *arg0)
{
    Enemy_Set5A1b5_1_0013EE90(D_00201FA8->p, arg0[8]);
}
