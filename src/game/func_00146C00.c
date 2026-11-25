#include "common.h"

extern f32 D_00270560[629];
f32 func_0011D778(f32 x);

void func_00146C00(void)
{
    s32 i;
    for (i = 0; i < 629; i++)
        D_00270560[i] = func_0011D778(0.0099891657f * i);
}
