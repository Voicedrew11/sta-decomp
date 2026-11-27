#include "common.h"
extern void *D_00201E60;

void GsText_SetFlagA_0_001E2AE8(s32 arg0) {
    M2C_FIELD(D_00201E60, s32 *, 0x50) = (s32) (arg0 != 0);
}
