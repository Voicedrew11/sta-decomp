#include "common.h"
extern void *D_00201FA8;

void EnemyCmd_ResetState_1_00144D50(void) {
    Enemy_SetStateResetTimer_1_0013E7E0(M2C_FIELD(D_00201FA8, void **, 0x154), 1);
}
