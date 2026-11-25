#include "common.h"

typedef struct { s8 b0; char p1[0xD]; s8 bE; s8 bF; char p10[0x5D]; s8 b6D; char rest[0x12]; } E;
extern E D_0022CBC0[63];

void func_0012C2C0(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (D_0022CBC0[i].b0 && D_0022CBC0[i].bF && D_0022CBC0[i].bE != 1) {
            D_0022CBC0[i].b6D = D_0022CBC0[i].bE;
            D_0022CBC0[i].bE = 2;
        }
    }
}
