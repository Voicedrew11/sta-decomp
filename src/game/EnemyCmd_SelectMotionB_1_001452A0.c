#include "common.h"
extern void *D_00201FA8;

void EnemyCmd_SelectMotionB_1_001452A0(void *arg0) {
    Enemy_SelectMotion_0_0013C420(M2C_FIELD(D_00201FA8, void **, 0x154), (s32) M2C_FIELD(arg0, u8 *, 8), (s64) M2C_FIELD(arg0, s16 *, 0x10), 1);
}
