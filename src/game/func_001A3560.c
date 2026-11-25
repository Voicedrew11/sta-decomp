#include "common.h"

extern s32 D_001F3280[];

s32 func_001A3560(s32 i)
{
    if (i < 0 || i > 4)
        return 0;
    return D_001F3280[i];
}
