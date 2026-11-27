#include "common.h"

/* bss_004A10B0: the game's .bss from 0x004A10B0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Hud_Draw_0_0018E480, Option_Update_2_0018EAE0, Option_QuitGame_0_0018EC40, Option_ScreenSetting_1_0018EDA0,
   Option_ControllerSetting_1_0018F0D0, Option_SoundSetting_1_0018F490, Option_MainMenu_0_0018F940, Option_Open_0_0018FFE0, OptionProc_DrawSound_0_00190A50,
   OptionProc_DrawScreen_0_00190DC0, OptionProc_DrawController_0_00191110, OptionProc_DrawMain_0_00191420, Option_LerpLayout_0_00191820, OptionProc_Back_0_00191C40,
   LoadMenu_DrawList_0_00191CB0, LoadMenu_HandleEvent_0_00192900, LoadMenu_SelectSlot_0_001929C0, LoadMenu_CheckCard_1_00192E90, LoadMenu_ConfirmLoad_0_00192F70,
   LoadMenu_Load_0_00193070, LoadMenu_Retry_0_001937E0, LoadMenu_SetFromTitle_0_00193850, LoadMenu_DrawFrame_0_00193880, LoadMenu_Open_0_001939B0,
   LoadMenu_DrawSlot_1_00193AF0, LoadMenu_SelectDevice_0_00193E80, LoadMenu_SelectSlotB_0_00194150, LoadMenu_Format_0_001942E0, LoadMenu_WaitCard_0_00194440,
   LoadMenu_LoadB_0_001945B0, LoadMenu_BackB_0_00194B90, LoadMenu_CheckCardB_0_00194C20, LoadMenu_RetryB_0_00194D20, DbChar_Draw_0_00195E30,
   DbChar_DrawStats_1_00195F70, DbChar_Update_0_00196940, DbItem_Draw_0_00196E20, DbItem_DrawStats_0_00196F90, DbItem_Open_0_001979C0,
   DbItem_Update_0_00197B80, DbItem_ResetLayout_0_00197DD0, DbMap_Draw_0_00198160, DbMapProc_DrawInfo_1_00198570, DbMap_Update_0_00198BE0,
   DbMap_ResetLayout_0_00198D80, DbMap_GetListName_1_00198F30, DbMap_BuildList_1_00199000, text_00196330.s,
   text_001973F0.s */

f32 D_004A18B8[0x2];
s32 D_004A18B0[0x2];
u32 D_004A18AC[0x1];
f32 D_004A18A0[0x3];
f32 D_004A189C[0x1];
u8 D_004A1884[0x18] __attribute__((aligned(4))); /* also D_004A1888 */
s8 D_004A1870[0x14];
s8 D_004A1770[0x100];
s32 D_004A1450[0xc8];
u8 D_004A1440[0x10]; /* also D_004A1444 */
f32 D_004A143C[0x1];
s32 D_004A1438[0x1];
s32 D_004A1434[0x1];
s32 D_004A1430[0x1];
u8 D_004A142C[0x4];
u8 D_004A1420[0xc];
u8 D_004A141C[0x4];
u8 D_004A1404[0x18] __attribute__((aligned(4))); /* also D_004A1408 */
u8 D_004A13F0[0x14];
s32 D_004A13E0[0x4];
u8 D_004A13DC[0x4];
u8 D_004A13D0[0xc];
u8 D_004A13CC[0x4];
u8 D_004A13B4[0x18] __attribute__((aligned(4))); /* also D_004A13B8 */
u8 D_004A13A0[0x14];
s32 D_004A11A0[0x80];
s32 D_004A119C[0x1];
s32 D_004A1198[0x1];
u8 D_004A1194[0x4];
f32 D_004A1190[0x1];
u8 D_004A118C[0x4];
s32 D_004A1188[0x1];
s32 D_004A1184[0x1];
u8 D_004A1180[0x4];
u8 D_004A1150[0x30]; /* also D_004A1168 */
u8 D_004A1140[0x10];
f32 D_004A113C[0x1];
f32 D_004A1138[0x1];
s32 D_004A1130[0x2];
s32 D_004A112C[0x1];
s32 D_004A1128[0x1];
s32 D_004A1124[0x1];
s32 D_004A1120[0x1];
s32 D_004A10F0[0xc];
s32 D_004A10E8[0x2];
s32 D_004A10E4[0x1];
s32 D_004A10E0[0x1];
u8 D_004A10DC[0x4];
f32 D_004A10D8[0x1];
s32 D_004A10D4[0x1];
s32 D_004A10D0[0x1];
u8 D_004A10C8[0x8];
u8 D_004A10C4[0x4];
s32 D_004A10C0[0x1];
f32 D_004A10B0[0x4];
