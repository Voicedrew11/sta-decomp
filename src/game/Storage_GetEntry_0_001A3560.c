#include "common.h"
#pragma explicit_zero_data on
const u8 D_001FD830[0x10] = "BUY ITEM\000\000\000\000\000\000\000\000";
const u8 D_001FD840[0x10] = "SELL ITEM\000\000\000\000\000\000\000";
const u8 D_001FD850[0x10] = "PUT ITEM\000\000\000\000\000\000\000\000";
const u8 D_001FD860[0xa] = "DRAW ITEM\000";
s32 D_001F3280[0x8] = { (s32)D_001FD830, (s32)D_001FD840, (s32)D_001FD850, (s32)D_001FD860 };
s32 Storage_GetEntry_0_001A3560(s32 i)
{
    if (i < 0 || i > 4)
        return 0;
    return D_001F3280[i];
}
