#include "common.h"
extern void *D_00201FA4;

void ScrCmd_SendEvent_1_00164EE0(void *arg0) {
    Script_SendEventImpl_1_00166DA0(D_00201FA4, M2C_FIELD(arg0, s32 *, 8), 0);
}
