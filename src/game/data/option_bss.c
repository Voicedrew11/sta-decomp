#include "common.h"

/* bss_004A0B0C: the game's .bss from 0x004A0B0C, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Menu_ResetTimers_0_00188F80, Camera_SetShake_0_00189F00, Menu_Draw_1_00189F40, Menu_Update_1_0018A200,
   Menu_GetMode_1_0018A320, Menu_SetSubMode_0_0018A330, Menu_Open_1_0018A350, Menu_SetParam_0_0018A410, Pause_Update_0_0018A650,
   Msg_Draw_0_0018ACA0, Msg_Show_1_0018AEB0, Msg_Close_1_0018B0C0, Msg_GetAlpha_0_0018B110, MenuProc_DrawList_0_0018B180,
   MenuProc_CheckReady_0_0018B2E0, MenuProc_Run_1_0018B320, MenuProc_DrawItemList_0_0018B860, SaveMenu_HandleEvent_0_0018C4C0, SaveMenu_SelectSlot_0_0018C590,
   SaveMenu_ConfirmOverwrite_0_0018C8B0, SaveMenu_Save_0_0018CA20, SaveMenu_ConfirmLoad_0_0018D060, SaveMenu_Exit_0_0018D140, SaveMenu_DrawFrame_0_0018D1F0,
   SaveMenu_Open_1_0018D360, SaveMenu_DrawSlot_1_0018D420, SaveMenu_SelectDevice_0_0018D7B0, SaveMenu_Load_0_0018DA20, SaveMenu_CheckCard_0_0018DFB0,
   SaveMenu_Retry_0_0018E0B0, Menu_RestoreOptions_1_0018E450, Menu_SaveOptions_1_0018E460, Option_QuitGame_0_0018EC40, Option_ScreenSetting_1_0018EDA0,
   Option_ControllerSetting_1_0018F0D0, Option_SoundSetting_1_0018F490, Option_MainMenu_0_0018F940, Option_Open_0_0018FFE0, OptionProc_DrawKeyAssign_1_001907D0,
   OptionProc_DrawSound_0_00190A50, OptionProc_DrawScreen_0_00190DC0, OptionProc_DrawController_0_00191110, text_0018B860.s */

s32 D_004A108C[0x1];
s32 D_004A1088[0x1];
s32 D_004A1084[0x1];
s32 D_004A1080[0x1];
u8 D_004A1078[0x8] __attribute__((aligned(4)));
u8 D_004A1074[0x4]; /* also D_004A1075, D_004A1077 */
u8 D_004A1070[0x4]; /* also D_004A1071, D_004A1072, D_004A1073 */
s32 D_004A106C[0x1];
s32 D_004A1068[0x1];
f32 D_004A1060[0x2] __attribute__((aligned(4)));
u8 D_004A105C[0x4];
s32 D_004A1058[0x1];
s32 D_004A1054[0x1];
u8 D_004A1050[0x4];
s32 D_004A1020[0xc] __attribute__((aligned(4)));
u8 D_004A1010[0x10] __attribute__((aligned(4)));
f32 D_004A100C[0x1];
u8 D_004A1008[0x4];
s32 D_004A1000[0x2] __attribute__((aligned(4)));
s32 D_004A0FFC[0x1];
s32 D_004A0FF8[0x1];
s32 D_004A0FF4[0x1];
s32 D_004A0FF0[0x1];
s32 D_004A0FC0[0xc] __attribute__((aligned(4)));
u8 D_004A0F98[0x28] __attribute__((aligned(4))); /* also D_004A0F9C, D_004A0FAC */
u8 D_004A0F90[0x8] __attribute__((aligned(4)));
u8 D_004A0F80[0x10] __attribute__((aligned(4))); /* also D_004A0F84 */
u8 D_004A0F68[0x18] __attribute__((aligned(4))); /* also D_004A0F6C, D_004A0F74 */
s32 D_004A0F64[0x1];
u8 D_004A0F60[0x4];
u8 D_004A0F5C[0x4];
u8 D_004A0F58[0x4];
s32 D_004A0F54[0x1];
u8 D_004A0B50[0x404] __attribute__((aligned(4)));
u8 D_004A0B30[0x20] __attribute__((aligned(4))); /* also D_004A0B34 */
u8 D_004A0B2C[0x4]; /* also D_004A0B2E, D_004A0B2F */
u8 D_004A0B28[0x4]; /* also D_004A0B29, D_004A0B2A, D_004A0B2B */
s32 D_004A0B24[0x1];
u8 D_004A0B20[0x4];
u8 D_004A0B1C[0x4];
u8 D_004A0B18[0x4];
u8 D_004A0B14[0x4];
u8 D_004A0B10[0x4];
u32 D_004A0B0C[0x1];
