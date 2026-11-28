#include "common.h"
typedef struct { s32 p0, p4; s32 x8; s32 pC; u32 x10; u32 x14; } S;
extern S *D_00201E5C;
s32 AlignUp_3_001E1E50(s32, s32);

void GsText_SetVram_0_001E1F28(s32 arg0, u32 arg1) {
    D_00201E5C->x8 = AlignUp_3_001E1E50(arg0, 0x10);
    D_00201E5C->x10 = arg1;
    D_00201E5C->x10 -= D_00201E5C->x8 - arg0;
    D_00201E5C->x14 = D_00201E5C->x10 >> 4;
    D_00201E5C->x14 -= 6;
    D_00201E5C->x14 /= 13;
}

