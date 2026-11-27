#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_UpdateParamFlags_0_0013F760(void *arg0, u8 arg1);

void EnemyCmd_UpdateParamFlags_1_00144FB0(u8 *arg0)
{
    Enemy_UpdateParamFlags_0_0013F760(D_00201FA8->p, arg0[8]);
}
