#include "common.h"

typedef struct { s8 b0; char p1[0xD]; s8 bE; s8 bF; char rest[0x70]; } E;
extern E D_0022CBC0[];

void SndCh_StopAllUnlooped_1_0012C210(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (D_0022CBC0[i].b0 && !D_0022CBC0[i].bF)
            D_0022CBC0[i].bE = 1;
    }
}
