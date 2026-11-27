#include "common.h"
extern void *D_00201FA8;

void EnemyCmd_Set609_1_001452C0(void *arg0) {
    M2C_FIELD(M2C_FIELD(D_00201FA8, void **, 0x154), s8 *, 0x609) = (s8) M2C_FIELD(arg0, s8 *, 8);
}
