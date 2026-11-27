#include "m2c.h"
extern s32 D_00201F2C;
extern f32 D_00201E90;
extern void GsPkt_BeginAD_3_001545D0(void);
extern void GsPkt_SetReg_3_001543E0(s32, u64);
extern void GsPkt_EndAD_3_00154420(void);
extern void Tex_FlushAll_1_00176AE0(void);
extern u64 __fixunssfdi(f32);
static inline s32 wd(void) { return D_00201F2C ? 0 : 0x1180; }

void ScreenFx_DrawLetterbox_0_001325F0(void) {
    f32 f;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (s64)(wd() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4D, (s64)(wd() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
    GsPkt_SetReg_3_001543E0(0x4F, 0x3A000118);
    f = D_00201E90;
    GsPkt_SetReg_3_001543E0(0x40, 0x27F0000 | ((u64)__fixunssfdi(f) << 32) | ((u64)__fixunssfdi(448.0f - f - 1.0f) << 48));
    f = D_00201E90;
    GsPkt_SetReg_3_001543E0(0x41, 0x27F0000 | ((u64)__fixunssfdi(f) << 32) | ((u64)__fixunssfdi(448.0f - f - 1.0f) << 48));
    GsPkt_EndAD_3_00154420();
    Tex_FlushAll_1_00176AE0();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x1A, 1);
    GsPkt_SetReg_3_001543E0(0x42, 0xAA);
    GsPkt_SetReg_3_001543E0(0x43, 0x48);
    GsPkt_SetReg_3_001543E0(0x47, 0x50000);
    GsPkt_SetReg_3_001543E0(0x48, 0x50000);
    GsPkt_SetReg_3_001543E0(1, 0x80000);
    GsPkt_EndAD_3_00154420();
    Tex_FlushAll_1_00176AE0();
}
