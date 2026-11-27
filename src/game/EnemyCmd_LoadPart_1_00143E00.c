#include "common.h"
void Enemy_LoadPartWrap_0_0013F0B0(s32, u8);                     /* extern */
extern void *D_00201FA8;

void EnemyCmd_LoadPart_1_00143E00(void *arg0) {
    Enemy_LoadPartWrap_0_0013F0B0(M2C_FIELD(D_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, u8 *, 8));
}
