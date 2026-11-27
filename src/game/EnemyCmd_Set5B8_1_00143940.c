#include "common.h"
void Enemy_Set5B8_1_0013E480(s32, f32);                    /* extern */
extern void *D_00201FA8;

void EnemyCmd_Set5B8_1_00143940(void *arg0) {
    Enemy_Set5B8_1_0013E480(M2C_FIELD(D_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, f32 *, 8));
}
