#include "common.h"

extern s32 D_001F2E70[];

s32 func_00195420(s32 i)
{
    if (i < 0 || i > 3)
        return 0;
    return D_001F2E70[i];
}
