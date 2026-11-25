#include "common.h"

s32 func_001D8680(s32 a, s32 b, s32 c, ...);

s32 func_001D8CE0(s32 x, s32 y, s32 z)
{
    return func_001D8680(5, 1, 0x3020000, x, y, z) != 0;
}
