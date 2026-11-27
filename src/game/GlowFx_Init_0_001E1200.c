#include "common.h"

typedef struct { s32 v; char pad[0x3C]; } E;
extern E D_004BAC50[16];

void GlowFx_Init_0_001E1200(void)
{
    s32 i;
    for (i = 15; i >= 0; i--)
        D_004BAC50[i].v = -1;
}
