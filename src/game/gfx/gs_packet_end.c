#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/effect.h"
#include "game/gfx.h"
extern  s32 D_002F194C[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_002F1950[0x10];
extern s32 D_002F1994[];
extern  s32 D_002F19A8[];

/* GsPkt_EndLayer_1_00155900 */
void GsPkt_EndLayer_1_00155900(void) {
    s32 d; s32 q;
    if (D_002F1994[0] != 0) {
        GsPkt_CloseChain_1_001549D0();
    }
D_002F1948[0]--; D_002F194C[0] = D_002F1950[D_002F1948[0]];
    d = D_002F194C[0] - D_002F19A8[0]; q = d / 32; if ((u32)q < 0x660) { D_00201F28 = 1; } else { D_00201F28 = 0; }
    Fx_ResetSpriteCount_0_00164320();
}

/* GsPkt_EndLayerEx_0_001559C0 */
#define D_002F194C D_002F194C__as_GsPkt_EndLayerEx_0_001559C0
extern volatile s32 D_002F194C__as_GsPkt_EndLayerEx_0_001559C0[];
#define D_002F19A8 D_002F19A8__as_GsPkt_EndLayerEx_0_001559C0
extern volatile s32 D_002F19A8__as_GsPkt_EndLayerEx_0_001559C0[];
static inline s32 used(void) { return (D_002F194C[0] - D_002F19A8[0]) / 32; }

void GsPkt_EndLayerEx_0_001559C0(s32 a) {
    s32 d; s32 q; u32 u;
    if (D_002F1994[0] != 0) {
        GsPkt_CloseChain_1_001549D0();
    }
    d = a * 32; D_002F194C[0] = D_002F19A8[0] + d;
    D_002F1950[D_002F1948[0]] = D_002F194C[0];
    D_002F1948[0]++;
    d = D_002F194C[0] - D_002F19A8[0]; q = d / 32; if ((u32)q < 0x660) { D_00201F28 = 1; } else { D_00201F28 = 0; }
}
#undef D_002F194C
#undef D_002F19A8

/* GsPkt_GetLayerCount_0_00155A90 */
s32 GsPkt_GetLayerCount_0_00155A90(void)
{
    return (D_002F194C[0] - D_002F19A8[0]) / 32;
}
