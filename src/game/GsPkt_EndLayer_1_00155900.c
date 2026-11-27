#include "common.h"
extern s32 D_00201F28;
extern  s32 D_002F1948[];
extern  s32 D_002F194C[];
extern s32 D_002F1950[];
extern s32 D_002F1994[];
extern  s32 D_002F19A8[];
void GsPkt_CloseChain_1_001549D0(void);
void Fx_ResetSpriteCount_0_00164320(void);
void GsPkt_EndLayer_1_00155900(void) {
    s32 d; s32 q;
    if (D_002F1994[0] != 0) {
        GsPkt_CloseChain_1_001549D0();
    }
D_002F1948[0]--; D_002F194C[0] = D_002F1950[D_002F1948[0]];
    d = D_002F194C[0] - D_002F19A8[0]; q = d / 32; if ((u32)q < 0x660) { D_00201F28 = 1; } else { D_00201F28 = 0; }
    Fx_ResetSpriteCount_0_00164320();
}
