#include "common.h"

extern u8 D_001FD830[];
extern u8 D_001FD840[];
extern u8 D_001FD850[];
extern u8 D_001FD860[];
s32 D_001F3280[0x8] = { (s32)D_001FD830, (s32)D_001FD840, (s32)D_001FD850, (s32)D_001FD860 };
s32 func_001A3560(s32 i)
{
    if (i < 0 || i > 4)
        return 0;
    return D_001F3280[i];
}
