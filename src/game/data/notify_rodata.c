#include "common.h"

/* rodata_001FD698: the game's data at 0x001FD698..., one object per label. */
/* used by: Notify_DrawItemGet_0_0019F050, Notify_DrawItemCount_0_0019F410, Notify_DrawItemCountB_0_0019F690, Notify_DrawGold_0_0019F890,
   Notify_DrawItemGold_0_0019FA00 */
#pragma explicit_zero_data on

void Inventory_Sort_0_0019FD00(void);

const s8 D_001FD698[0x8] = "%d\000\000\000\000\000\000";
const s8 D_001FD6A0[0x8] = { -0x7f, 0x7e, 0x20, 0x25, 0x64, 0, 0, 0 };
const s8 D_001FD6A8[0x8] = { -0x7e, 0x62, 0x20, 0x25, 0x64, 0, 0, 0 };
const s32 jtbl_001FD6B0[0x8] __attribute__((aligned(8))) = { (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x698), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x48), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x1A0), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x2C0), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x370), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x428), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x500), 0 };
