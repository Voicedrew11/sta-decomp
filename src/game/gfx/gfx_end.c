#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
Q *GsPkt_Alloc_3_00154A80(s32);
void GsPkt_CloseChain_1_001549D0(void);
void GsPkt_EndLayerEx_0_001559C0(s32);
void GsPkt_EndLayer_1_00155900(void);
void Gfx_EndScene_0_001741D0(void) {
    Q q;
    Q *p;
    q.q = 0;
    GsPkt_EndLayerEx_0_001559C0(0);
    p = GsPkt_Alloc_3_00154A80(1);
    q.w[0] = 0x10000000;
    q.w[2] = 0x30000C0;
    q.w[3] = 0x2000144;
    p[0] = q;
    GsPkt_CloseChain_1_001549D0();
    GsPkt_EndLayer_1_00155900();
}

