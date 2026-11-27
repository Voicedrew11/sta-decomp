#include "common.h"

/* bss_004A32C8: the game's .bss from 0x004A32C8, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Hud_HandleInput_0_0019B590, ItemMenu_Reset_0_0019DF80, Status_Draw_0_0019DF90, Status_DrawStats_0_0019E090,
   PauseMenu_Open_0_0019E2F0, PauseMenu_Update_0_0019E400, Notify_DrawBackground_0_0019EF60, Notify_DrawItemGet_0_0019F050, Notify_DrawItemName_0_0019F310,
   Notify_DrawItemCount_0_0019F410, Notify_DrawItemCountB_0_0019F690, Notify_DrawGold_0_0019F890, Notify_DrawItemGold_0_0019FA00, Shop_SelectItem_0_001A03C0,
   Shop_Confirm_0_001A06B0, Shop_BuyQuantity_0_001A0850, Shop_SellQuantity_0_001A0B00, Shop_Repair_0_001A0DB0, Shop_Heal_0_001A1000,
   ShopProc_BackA_0_001A1380, ShopProc_BackB_0_001A13F0, Shop_Draw_0_001A1460, Shop_DrawStatus_0_001A1550, Shop_Open_1_001A1B40,
   Shop_Update_0_001A1C80, Shop_ResetPrices_0_001A2DE0, Shop_RecalcPrices_0_001A2EA0, ShopProc_Pos_0_001A2FF0, Storage_Draw_0_001A30E0,
   Storage_DrawStatus_0_001A31E0, Storage_Open_0_001A32A0, Storage_Update_0_001A3380, Title_LoadGame_0_001A35B0,
   text_0019FD00.s, text_001A1C80.s */

f32 D_004A4370[0x1];
s32 D_004A436C[0x1];
void *D_004A4368[0x1];
s32 D_004A4364[0x1];
s32 D_004A4360[0x1];
s32 D_004A4350[0x4] __attribute__((aligned(8)));
u8 D_004A4340[0x10] __attribute__((aligned(8)));
f32 D_004A433C[0x1];
u8 D_004A4330[0xc]; /* also D_004A4334 */
s32 D_004A3330[0x400] __attribute__((aligned(8)));
u8 D_004A332C[0x4];
u8 D_004A3328[0x4];
s32 D_004A3324[0x1];
s32 D_004A3320[0x1];
u8 D_004A331C[0x4];
s32 D_004A3318[0x1];
u8 D_004A3310[0x8]; /* also D_004A3312 */
s32 D_004A32F0[0x8] __attribute__((aligned(8)));
void *D_004A32EC[0x1];
s32 D_004A32E8[0x1];
s32 D_004A32E4[0x1];
s32 D_004A32E0[0x1];
u8 D_004A32C8[0x18] __attribute__((aligned(8))); /* also D_004A32CC */
