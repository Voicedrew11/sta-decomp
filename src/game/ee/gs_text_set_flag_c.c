#include "common.h"
extern void *D_00201E60;

void GsText_SetFlagC_0_001E2B08(s32 arg0) {
    M2C_FIELD(D_00201E60, s32 *, 0x58) = (s32) (arg0 != 0);
}
