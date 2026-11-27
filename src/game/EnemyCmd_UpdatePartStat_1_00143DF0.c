#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_UpdatePartStat_0_0013F0C0(void *arg0, u8 arg1);

void EnemyCmd_UpdatePartStat_1_00143DF0(u8 *arg0)
{
    Enemy_UpdatePartStat_0_0013F0C0(D_00201FA8->p, arg0[8]);
}
