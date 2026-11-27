#include "common.h"
typedef struct { u8 lo : 2; u8 rest : 6; u8 pad[3]; } P;
extern s32 D_00201FF8;
extern s32 D_00201FFC;
extern s32 D_00202000;
extern s32 D_00202004;
void GsPkt_CloseChain_1_001549D0(void);
void GsPkt_EndLayer_1_00155900(void);
void GsPkt_SetLayer_1_00154700(s32, s32);
void Mdl_SetLayerTex_0_0016B2D0(s32 a, P p, s32 base, s32 n) {
    s32 v = p.lo + base;
    if (D_00201FFC != v || D_00202004 != n + 8 || D_00202000 != 0) {
        D_00201FFC = v;
        GsPkt_CloseChain_1_001549D0();
        GsPkt_EndLayer_1_00155900();
        GsPkt_SetLayer_1_00154700(D_00201FFC, n);
        D_00201FF8 = 1;
    }
    D_00202004 = n + 8;
    D_00202000 = 0;
}
