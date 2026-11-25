#include "common.h"

extern u8 *D_00201DC8;

s32 func_001A9F60(s16 i)
{
    if (0 > i || i > 0x80)
        return 0;
    return D_00201DC8[i] & 1;
}
