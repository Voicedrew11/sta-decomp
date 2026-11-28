#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
extern u8 D_0030A2D0[];
extern s32 D_00201F2C;
void Fog_SetReg_0_0015B1C0(Q *src, f32 *c);
void Fog_ApplyDefault_0_0015B270(void);
Q* GsPkt_Alloc_3_00154A80(s32);
void GsPkt_Commit_1_00154A70(void);
void GsPkt_BeginAD_3_001545D0(void);
void GsPkt_EndAD_3_00154420(void);
void GsPkt_SetReg_3_001543E0(s32, u64);
u64 __fixunssfdi(f32);
void sceVu0CopyVector(void *, void *);

/* Fog_SetReg_0_0015B1C0 */
void Fog_SetReg_0_0015B1C0(Q *src, f32 *c) {
    Q q;
    Q *p;
    q.q = 0;
    p = GsPkt_Alloc_3_00154A80(2);
    q.w[0] = 0x10000001;
    q.w[3] = 0x6C010059;
    p[0].q = q.q;
    p[1].q = src->q;
    GsPkt_Commit_1_00154A70();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x3D, __fixunssfdi(c[0]) | __fixunssfdi(c[1]) << 8 | __fixunssfdi(c[2]) << 16);
    GsPkt_EndAD_3_00154420();
}

/* Fog_ApplyDefault_0_0015B270 */
void Fog_ApplyDefault_0_0015B270(void) {
    Vec c;
    Q q;
    Q *p;
    u64 r;
    u64 g;
    u64 b;
    q.q = 0;
    p = GsPkt_Alloc_3_00154A80(1);
    q.w[0] = 0x30000001;
    q.w[1] = (u32)(D_0030A2D0 + D_00201F2C * 32);
    q.w[3] = 0x6C010059;
    p->q = q.q;
    GsPkt_Commit_1_00154A70();
    sceVu0CopyVector(&c, D_0030A2D0 + D_00201F2C * 32 + 0x10);
    GsPkt_BeginAD_3_001545D0();
    r = __fixunssfdi(255.0f * c.x);
    g = __fixunssfdi(255.0f * c.y);
    r |= g << 8;
    b = __fixunssfdi(255.0f * c.z);
    GsPkt_SetReg_3_001543E0(0x3D, (b << 16) | r);
    GsPkt_EndAD_3_00154420();
}
