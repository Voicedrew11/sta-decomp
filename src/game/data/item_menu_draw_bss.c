#include "common.h"

/* bss_004A1A4C: the game's .bss from 0x004A1A4C, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Equip_Reset_0_00199170, Equip_Draw_0_00199190, Equip_DrawStatus_0_00199260, Equip_Open_0_001997A0,
   Equip_Update_0_00199AD0, Equip_BuildList_0_0019A1D0, EquipProc_Pos_0_0019A6A0, Hud_ClearTimers_0_0019A840, Hud_DrawStatus_1_0019A920,
   Hud_DrawShortcuts_0_0019BBE0, Hud_UpdateShortcuts_0_0019BFF0, Hud_UpdateWeaponSlots_0_0019C560, ItemMenu_Draw_0_0019C6D0, ItemMenu_DrawStats_0_0019C9B0,
   ItemMenuProc_DrawGauge_0_0019CB90, ItemMenu_Open_0_0019D290, ItemMenu_Update_0_0019D580, ItemMenu_UseItem_0_0019DA70, ItemMenuProc_Pos_0_0019DE90,
   text_0019BFF0.s, text_0019CEF0.s */

u8 D_004A32AC[0x4];
u8 D_004A32A8[0x4];
u8 D_004A32A4[0x4];
u8 D_004A32A0[0x4];
u8 D_004A329C[0x4];
f32 D_004A3298[0x1];
s32 D_004A3294[0x1];
s32 D_004A3290[0x1];
u8 D_004A328C[0x4];
u8 D_004A3280[0xc] __attribute__((aligned(4)));
u8 D_004A327C[0x4];
u8 D_004A3264[0x18] __attribute__((aligned(4))); /* also D_004A3268 */
u8 D_004A3250[0x14] __attribute__((aligned(4)));
s8 D_004A3150[0x100] __attribute__((aligned(4)));
u8 D_004A3140[0x10] __attribute__((aligned(4))); /* also D_004A3144 */
u8 D_004A3130[0x10] __attribute__((aligned(4))); /* also D_004A3134 */
u8 D_004A3120[0x10] __attribute__((aligned(4))); /* also D_004A3124 */
u8 D_004A3110[0x10] __attribute__((aligned(4)));
u8 D_004A3100[0x10] __attribute__((aligned(4)));
u8 D_004A30F0[0x10] __attribute__((aligned(4)));
u8 D_004A30E0[0x10] __attribute__((aligned(4)));
u8 D_004A30D0[0x10] __attribute__((aligned(4)));
u8 D_004A2CE0[0x3f0] __attribute__((aligned(4)));
u8 D_004A2CD0[0x10] __attribute__((aligned(4)));
u8 D_004A28E0[0x3f0] __attribute__((aligned(4)));
u8 D_004A28D0[0x10] __attribute__((aligned(4)));
f32 D_004A28CC[0x1];
s32 D_004A28C8[0x1];
s32 D_004A28C4[0x1];
s32 D_004A28C0[0x1];
u8 D_004A1A50[0xe70] __attribute__((aligned(4)));
u8 D_004A1A4C[0x4];
