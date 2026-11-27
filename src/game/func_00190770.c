#include "common.h"
extern u8 D_001FCE08[];
extern u8 D_001FCE18[];
extern u8 D_001FCE30[];
extern u8 D_001FCE50[];
#pragma explicit_zero_data on
s32 D_001F2B40[0x4] = { (s32)D_001FCE08, (s32)D_001FCE18, (s32)D_001FCE30, (s32)D_001FCE50 };

s32 func_00190770(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
    case 3:
        return D_001F2B40[x];
    }
    return 0;
}
