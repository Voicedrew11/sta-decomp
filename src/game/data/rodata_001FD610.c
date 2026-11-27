#include "common.h"

/* rodata_001FD610: the game's data at 0x001FD610..., one object per label. */
#pragma explicit_zero_data on

void func_0019FD00(void);

const u8 D_001FD610[0x5] __attribute__((aligned(16))) = "ITEM\000";
const u8 D_001FD618[0x10] __attribute__((aligned(8))) = "EQUIPMENT\000\000\000\000\000\000\000";
const u8 D_001FD628[0x10] __attribute__((aligned(8))) = "DATABOOK\000\000\000\000\000\000\000\000";
const u8 D_001FD638[0x10] __attribute__((aligned(8))) = "LOAD GAME\000\000\000\000\000\000\000";
const u8 D_001FD648[0x7] = "OPTION\000";
const char D_001FD650[0x10] = { -0x7e, 0x6f, -0x7e, 0x60, -0x7e, 0x74, -0x7e, 0x72, -0x7e, 0x64, 0, 0, 0, 0, 0, 0 };
const char D_001FD660[0x20] = { -0x7e, 0x66, -0x7e, 0x60, -0x7e, 0x6c, -0x7e, 0x64, -0x7f, 0x40, -0x7e, 0x6e, -0x7e, 0x75, -0x7e, 0x64, -0x7e, 0x71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const s8 D_001FD680[0x18] = "\\TARGET\\STA_GO.ADX\000\000\000\000\000\000";
const s8 D_001FD698[0x8] = "%d\000\000\000\000\000\000";
const s8 D_001FD6A0[0x8] = { -0x7f, 0x7e, 0x20, 0x25, 0x64, 0, 0, 0 };
const s8 D_001FD6A8[0x8] = { -0x7e, 0x62, 0x20, 0x25, 0x64, 0, 0, 0 };
const s32 jtbl_001FD6B0[0x8] = { (s32)((u8 *)func_0019FD00 + 0x698), (s32)((u8 *)func_0019FD00 + 0x48), (s32)((u8 *)func_0019FD00 + 0x1A0), (s32)((u8 *)func_0019FD00 + 0x2C0), (s32)((u8 *)func_0019FD00 + 0x370), (s32)((u8 *)func_0019FD00 + 0x428), (s32)((u8 *)func_0019FD00 + 0x500), 0 };
