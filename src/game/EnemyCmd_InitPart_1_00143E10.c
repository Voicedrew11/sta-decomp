#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void Enemy_InitPart_1_0013F1B0(void *arg0, u8 arg1);

void EnemyCmd_InitPart_1_00143E10(u8 *arg0)
{
    Enemy_InitPart_1_0013F1B0(D_00201FA8->p, arg0[8]);
}
