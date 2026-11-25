#include "common.h"

typedef struct { char pad[8]; s32 v; char rest[0x14]; } E;
extern E D_004BA500[16];

s32 func_001DAC70(s32 i, s32 v)
{
    E *e;

    if (i < 0 || i >= 16)
        return -1;
    e = &D_004BA500[i];
    e->v = v;
    return 0;
}
