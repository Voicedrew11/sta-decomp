#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
extern Q *GsPkt_Alloc_3_00154A80(s32);
extern void GsPkt_Commit_1_00154A70(void);
extern void GsPkt_BeginAD_3_001545D0(void);
extern void GsPkt_EndAD_3_00154420(void);
extern void GsPkt_SetReg_3_001543E0(s32, u64);
extern u64 __fixunssfdi(f32);
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

