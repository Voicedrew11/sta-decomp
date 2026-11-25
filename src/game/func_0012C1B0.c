#include "common.h"

s32 func_001DA4F0(s32 i);

s32 func_0012C1B0(void)
{
    s32 i;
    s32 n = 0;
    for (i = 0; i < 64; i++) {
        if (func_001DA4F0(i) == 1)
            n++;
    }
    return n;
}
