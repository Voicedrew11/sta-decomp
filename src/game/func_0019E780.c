#include "common.h"

extern s32 D_001F3140[];

s32 func_0019E780(s32 i)
{
    if (i < 0 || i > 5)
        return 0;
    return D_001F3140[i];
}
