#include "common.h"
void Enemy_Set60B_1_0013E250(s32, u8);                     /* extern */
extern void *D_00201FA8;

void EnemyCmd_Set60B_1_00143950(void *arg0) {
    Enemy_Set60B_1_0013E250(M2C_FIELD(D_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, u8 *, 8));
}
