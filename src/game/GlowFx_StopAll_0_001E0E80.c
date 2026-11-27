#include "common.h"

typedef struct { s32 h; char p[0x3C]; } E;
extern E D_004BAC50[16];
extern u8 D_002023AC;
void Glow_Enable_0_0015DB60(s32 h);

s32 GlowFx_StopAll_0_001E0E80(void)
{
    s32 i;
    E *e = D_004BAC50;
    for (i = 0; i < 16; i++, e++) {
        s32 ok;
        if (i < 0 || i >= 16)
            ok = 0;
        else if (e->h == -1)
            ok = 0;
        else
            ok = 1;
        if (ok) {
            Glow_Enable_0_0015DB60(e->h);
            e->h = -1;
            D_002023AC--;
        }
    }
    return 1;
}
