#include "common.h"
extern s32 D_00201FF8;
extern s32 D_00201FFC;
extern s32 D_00202000;

void Mdl_FlushLayer_0_0016B280(void) {
    if (D_00201FF8 != 0) {
        GsPkt_CloseChain_1_001549D0();
        GsPkt_EndLayer_1_00155900();
        GsPkt_SetLayerTop_0_001548F0(0);
        D_00201FF8 = 0;
    }
    D_00201FFC = 0;
    D_00202000 = 0;
}
