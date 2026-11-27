#include "common.h"
extern void *D_00201FA8;

void EnemyCmd_KillNow_1_001450F0(void) {
    Enemy_Kill_1_0013EF80(M2C_FIELD(D_00201FA8, void **, 0x154), 0xFF);
}
