#include "common.h"

typedef struct { char p[8]; s32 v; char q[4]; } E;
extern E D_004A28E0[64];
extern E D_004A2CE0[64];

void func_0019A840(void)
{
    s32 i;
    for (i = 63; i >= 0; i--) {
        D_004A2CE0[i].v = 0;
        D_004A28E0[i].v = 0;
    }
}
