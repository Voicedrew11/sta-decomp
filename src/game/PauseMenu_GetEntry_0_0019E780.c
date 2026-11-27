#include "common.h"

extern u8 D_001FD610[];
#pragma explicit_zero_data on
const u8 D_001FD618[0x10] __attribute__((aligned(8))) = "EQUIPMENT\000\000\000\000\000\000\000";
const u8 D_001FD628[0x10] __attribute__((aligned(8))) = "DATABOOK\000\000\000\000\000\000\000\000";
const u8 D_001FD638[0xa] = "LOAD GAME\000";
extern u8 D_001FD648[];
s32 D_001F3140[0x8] = { (s32)D_001FD610, (s32)D_001FD618, (s32)D_001FD628, (s32)D_001FD638, (s32)D_001FD648 };
s32 PauseMenu_GetEntry_0_0019E780(s32 i)
{
    if (i < 0 || i > 5)
        return 0;
    return D_001F3140[i];
}
