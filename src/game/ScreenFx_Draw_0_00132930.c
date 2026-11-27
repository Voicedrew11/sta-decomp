#include "common.h"
void GsPkt_BeginAD_3_001545D0();                            /* extern */
void Tex_FlushAll_1_00176AE0();                            /* extern */
extern u16 D_00201F04;
extern u16 D_00201F08;
extern u8 D_00201F0C;

void ScreenFx_Draw_0_00132930(s32 arg0) {
    if (D_00201F0C != 0) {
        ScreenFx_DrawBlurPasses_0_00131970((s32) D_00201F04, (s32) D_00201F08, (void *) arg0);
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x1A, 1);
        GsPkt_SetReg_3_001543E0(0x42, 0xAA);
        GsPkt_SetReg_3_001543E0(0x43, 0x48);
        GsPkt_SetReg_3_001543E0(0x47, 0x50000);
        GsPkt_SetReg_3_001543E0(0x48, 0x50000);
        GsPkt_SetReg_3_001543E0(1, 0x80000);
        GsPkt_EndAD_3_00154420();
        Tex_FlushAll_1_00176AE0();
        D_00201F0C = 0;
    }
}
