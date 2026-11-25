#include "common.h"

s32 func_001E5E40(u8 c)
{
    s32 r = 0;
    if ((u8)(c + 0x7F) < 0x1F || (u8)(c + 0x20) < 0xB)
        r = 1;
    return r;
}
