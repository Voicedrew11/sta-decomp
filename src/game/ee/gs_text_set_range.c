#include "common.h"
extern void *D_00201E5C;

void GsText_SetRange_0_001E1FF0(s32 arg0, s32 arg1) {
    M2C_FIELD(D_00201E5C, s32 *, 0x18) = arg0;
    M2C_FIELD(D_00201E5C, s32 *, 0x20) = arg1;
}
