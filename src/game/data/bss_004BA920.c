#include "common.h"

/* bss_004BA920: the game's .bss from 0x004BA920, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Se_SetMode_0_001D9EA0, Se_StopVoice_0_001DA530, Se_SetVoiceParams_0_001DA620, Se_UnloadBank_0_001DACB0,
   Se_TransferBank_0_001DB020, Se_Stop_0_001DB780, Se_Start_0_001DB7F0, Se_DmaStep_1_001DB830, Se_DmaBegin_1_001DB9B0,
   Se_Init_1_001DBAC0, ShopProc_DrawItemInfo_0_001DDA20, ShopProc_DrawItemStats_0_001DE2D0, ShopProc_DrawCommand_2_001DED50, Task_RunAll_1_001DFCB0,
   Task_Run_1_001DFEE0, Task_Step_1_001E0020, Task_Add_0_001E0180, Task_Remove_0_001E01F0, Task_GetState_0_001E02A0,
   Task_Init_1_001E03C0, Task_SetCallback_1_001E0560, Task_Start_1_001E0590, Task_Schedule_1_001E0680, Task_Dispatch_0_001E0AB0,
   GlowFx_Update_0_001E0C10, GlowFx_Stop_0_001E0D30, GlowFx_StopAll_0_001E0E80, GlowFx_SetParams_0_001E0F30, GlowFx_Start_0_001E1050,
   GlowFx_Init_0_001E1200, MapSe_StreamUpdate_0_001E1250, ImageLoader_Request_1_001E1570, ImageLoader_Init_0_001E1770, MapSe_LoadTask_1_001E19A0,
   MapSe_Flush_0_001E1CC0, MapSe_GetState_0_001E1D20, MapSe_Request_0_001E1D30, MapSe_Init_0_001E1D70, Credits_Load_1_001E3B48,
   Credits_Step_0_001E3CA0, Credits_SetSpeed_0_001E3DB8, Credits_Setup_0_001E3DD8, Credits_Run_1_001E3EC0, Credits_Alloc_1_001E4030,
   CreditsCb_DrawImage_0_001E41A8, CreditsCb_DrawSprites_0_001E4318, CreditsCb_DrawText_0_001E4518, SaveSys_GetSlotCount_0_001E5E80, SaveSys_StartRead_0_001E5F30,
   SaveSys_GetSlotState_0_001E6040, SaveSys_GetCurSlotState_0_001E6060, SaveSys_GetResult_0_001E6080, SaveSys_GetCardKind_0_001E60C0, SaveSys_IsCardReady_0_001E6110,
   SaveSys_StartWrite_0_001E6170, SaveSys_StartLoad_0_001E62A0, SaveSys_StartFormat_0_001E6410, SaveSys_StepSave_2_001E64E0, SaveSys_StepLoad_2_001E72A0,
   SaveSys_StepScan_1_001E7880, SaveSys_StepCheckSpace_0_001E7C10, SaveSys_StepUnformat_1_001E7DF0, SaveSys_StepCheckCard_0_001E7FA0, SaveSys_SetPort_1_001E82A0,
   SaveSys_ClassifyEntry_2_001E8310, SaveSys_Init_1_001E85E0, Movie_BuildUploadPacket_0_001E9020, Movie_ReadLoop_1_001ECAB0, Movie_Start_2_001ED0C0,
   Movie_SetParams_0_001ED5D0, text_001DB020.s, text_001DDA20.s, text_001DE2D0.s,
   text_001E02C0.s, text_001E3B48.s, text_001E8C50.s */

u8 D_004BD320[0x60];
s32 D_004BD31C[0x1];
s32 D_004BD318[0x1];
s32 D_004BD314[0x1];
u8 D_004BD310[0x4]; /* also D_004BD311, D_004BD312, D_004BD313 */
u8 D_004BCF40[0x3d0];
u8 D_004BCBC0[0x380];
u8 D_004BCB80[0x40];
u8 D_004BC740[0x440]; /* also D_004BC744 */
s32 D_004BC3A0[0xe8];
s32 D_004BC39C[0x1];
u8 D_004BC398[0x4];
u8 D_004BC394[0x4];
s32 D_004BC390[0x1];
s32 D_004BC38C[0x1];
s32 D_004BC388[0x1];
u8 D_004BC384[0x4];
u8 D_004BC380[0x4];
u8 D_004BC360[0x20]; /* also D_004BC368 */
u8 D_004BC2F0[0x70];
u32 D_004BC2E8[0x2];
u32 D_004BC2E4[0x1];
s32 D_004BC2E0[0x1];
s32 D_004BC2DC[0x1];
s32 D_004BC2D8[0x1];
s32 D_004BC2D4[0x1];
s32 D_004BC2D0[0x1];
u8 D_004BB120[0x11b0]; /* also D_004BB128 */
u8 D_004BB110[0x10]; /* also D_004BB114 */
u8 D_004BB050[0xc0];
u8 D_004BB010[0x40];
u8 D_004BAC80[0x390]; /* also D_004BAC84 */
u8 D_004BAC54[0x2c] __attribute__((aligned(4))); /* also D_004BAC58 */
u8 D_004BAC50[0x4];
u8 D_004BAC4C[0x4]; /* also D_004BAC4D */
s32 D_004BAC48[0x1];
s32 D_004BAC44[0x1];
s32 D_004BAC40[0x1];
u8 D_004BAC3C[0x4];
u8 D_004BAC38[0x4];
s32 D_004BAC34[0x1];
u8 D_004BAC30[0x4];
u8 D_004BAC2C[0x4];
u8 D_004BAC28[0x4];
u8 D_004BAC24[0x4];
u8 D_004BAC20[0x4];
u32 D_004BAC1C[0x1];
f32 D_004BAC10[0x3];
f32 D_004BAC0C[0x1];
u8 D_004BABF4[0x18] __attribute__((aligned(4))); /* also D_004BABF8 */
s8 D_004BABE0[0x14];
u8 D_004BABB0[0x30]; /* also D_004BABC8 */
u32 D_004BABAC[0x1];
f32 D_004BABA0[0x3];
f32 D_004BAB9C[0x1];
u8 D_004BAB84[0x18] __attribute__((aligned(4))); /* also D_004BAB88 */
u8 D_004BAB70[0x14];
u8 D_004BAA70[0x100];
s32 D_004BAA6C[0x1];
u8 D_004BAA68[0x4];
s32 D_004BAA64[0x1];
u8 D_004BAA60[0x4];
s32 D_004BAA58[0x2];
s32 D_004BAA54[0x1];
u8 D_004BAA50[0x4];
u8 D_004BAA4C[0x4];
u8 D_004BAA48[0x4];
s32 D_004BAA44[0x1];
s32 D_004BAA40[0x1];
u8 D_004BAA34[0xc] __attribute__((aligned(4))); /* also D_004BAA36 */
s32 D_004BAA30[0x1];
s32 D_004BAA2C[0x1];
u8 D_004BAA28[0x4];
s32 D_004BAA24[0x1];
s32 D_004BAA20[0x1];
u8 D_004BA920[0x100];
