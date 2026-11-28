#include "common.h"
s32 Credits_InitText_0_001E3AF8(void *arg0) {
    s32 temp_16;

    temp_16 = GsText_GetVramOffset_0_001E1FC8(0);
    return temp_16 + GsText_PackColor_0_001E1EE0(1, 0x100) + (M2C_FIELD(arg0, u16 *, 8) << 7);
}
