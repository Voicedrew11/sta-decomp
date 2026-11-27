#include "common.h"

extern u8 D_001FD270[];
extern u8 D_001FD278[];
extern u8 D_001FD288[];
s32 D_001F2E70[0x4] = { (s32)D_001FD270, (s32)D_001FD278, (s32)D_001FD288 };
s32 func_00195420(s32 i)
{
    if (i < 0 || i > 3)
        return 0;
    return D_001F2E70[i];
}
