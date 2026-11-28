#include "common.h"
extern void *D_00201E5C;
extern f32 *D_00201E60;

void GsText_PrintIdAt_0_001E26F8(f32 *arg0, s32 arg1) {
    Sjis_ToWide_2_001E5C60(M2C_FIELD(D_00201E5C, s32 *, 0x134), 0x100, (u32) arg1, -1);
    *D_00201E60 = *arg0;
    GsText_DrawString_2_001E2748((u32) arg0, (u16 *) M2C_FIELD(D_00201E5C, s32 *, 0x134));
}
