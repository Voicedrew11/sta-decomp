#include "common.h"

extern u8 D_0022EC15[];
void func_001DA8F0(s32 i, s16 v);

void func_0012C6C0(s32 v)
{
    s32 i;
    D_0022EC15[0] = 0;
    for (i = 0; i < 4; i++)
        func_001DA8F0(i, v);
}
