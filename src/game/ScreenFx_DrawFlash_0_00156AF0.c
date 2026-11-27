#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
extern s32 D_00201F2C;
extern f32 D_00201E90;
extern void GsPkt_BeginAD_3_001545D0(void);
extern void GsPkt_SetReg_3_001543E0(s32, u64);
extern void GsPkt_EndAD_3_00154420(void);
extern Q *GsPkt_Alloc_3_00154A80(s32);
extern void GsPkt_Commit_1_00154A70(void);
extern void Tex_FlushAll_1_00176AE0(void);
extern u64 __fixunssfdi(f32);
static inline s32 wd(void) { return D_00201F2C ? 0 : 0x1180; }

void ScreenFx_DrawFlash_0_00156AF0(void) {
    Q q;
    Q *p;
    f32 f;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (s64)(wd() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
    f = D_00201E90;
    GsPkt_SetReg_3_001543E0(0x40, 0x27F0000 | ((u64)__fixunssfdi(f) << 32) | ((u64)__fixunssfdi(448.0f - f - 1.0f) << 48));
    GsPkt_SetReg_3_001543E0(0x47, 0x31001);
    GsPkt_SetReg_3_001543E0(6, 0xA8016BC0 | ((u64)0xA << 32));
    GsPkt_SetReg_3_001543E0(0x14, 0x60);
    GsPkt_SetReg_3_001543E0(1, 5);
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(6);
    q.q = 0;
    q.w[0] = 0x10000005;
    q.w[3] = 0x50000005;
    p[0].q = q.q;
    q.d[0] = ((u64)0x408B4000 << 32) | 0x8001;
    q.d[1] = 0x5353;
    p[1].q = q.q;
    q.w[0] = 0;
    q.w[1] = 0;
    q.d[1] = 0;
    p[2].q = q.q;
    q.w[0] = 0x6BF0;
    q.w[1] = 0x71F0;
    q.w[2] = 0;
    q.w[3] = 0;
    p[3].q = q.q;
    q.w[0] = 0x1400;
    q.w[1] = 0xE00;
    q.d[1] = 0;
    p[4].q = q.q;
    q.w[0] = 0x9410;
    q.w[1] = 0x8E10;
    q.w[2] = 0;
    q.w[3] = 0;
    p[5].q = q.q;
    GsPkt_Commit_1_00154A70();
    Tex_FlushAll_1_00176AE0();
}
