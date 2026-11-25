#include "common.h"

extern s32 D_002020E0;
extern s32 D_00497B60[];

void func_00189ED0(s32 v)
{
    D_00497B60[D_002020E0] = v;
    D_002020E0++;
}
