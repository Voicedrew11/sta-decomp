#include "common.h"

extern u8 D_001FD610[];
extern u8 D_001FD618[];
extern u8 D_001FD628[];
extern u8 D_001FD638[];
extern u8 D_001FD648[];
s32 D_001F3140[0x8] = { (s32)D_001FD610, (s32)D_001FD618, (s32)D_001FD628, (s32)D_001FD638, (s32)D_001FD648 };
s32 func_0019E780(s32 i)
{
    if (i < 0 || i > 5)
        return 0;
    return D_001F3140[i];
}
