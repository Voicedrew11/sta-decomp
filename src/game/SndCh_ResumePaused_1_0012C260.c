#include "common.h"

typedef struct { s8 b0; char p1[2]; s8 b3; char p4[0xA]; s8 bE; s8 bF; char p10[0x5E]; s8 b6E; char rest[0x11]; } E;
extern E D_0022CBC0[63];

void SndCh_ResumePaused_1_0012C260(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (D_0022CBC0[i].b0 && D_0022CBC0[i].bF && D_0022CBC0[i].bE == 2) {
            D_0022CBC0[i].b3 = 1;
            D_0022CBC0[i].bE = 3;
            D_0022CBC0[i].b6E = 0;
        }
    }
}
