#include "common.h"

/* bss_003139E0: the game's .bss from 0x003139E0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Noise_Eval_1_0015ED80, Noise_Fbm_1_0015F040, Noise_Init_2_0015F250, Vibe_StartA_0_0015FD90,
   Vibe_StartB_0_0015FE20, Vibe_Update_1_0015FEB0, Vibe_Enable_1_001601C0, Vibe_StopAll_1_00160300, Vibe_Clear_1_00160350,
   Fx_DrawSprites_0_00163FF0, Fx_BeginFrame_0_00164350, Lightning_InitAll_1_001643B0, Lightning_BuildStrip_0_00164440, Lightning_ResetPoints_0_00164940,
   Script_ResolveOperand_1_00165150, Script_LoadLocal_1_00165400, Script_LoadLocalB_1_00165770, Script_Exec_2_00166170, Sfx_Release_1_00167030,
   Sfx_ReleaseOwned_0_00167580, Sfx_OffsetAll_1_00167850, Sfx_DrawAll_1_00168A40, Sfx_UpdateTransforms_1_00169030, Sfx_Spawn_2_00169B50,
   Sfx_IsLoaded_2_00169BB0, Sfx_ClearAll_1_0016AB50, Sfx_LoadSystemStam_1_0016AE30, Event_CheckTalk_0_00179F10, MapCmd_GetPlayerStat_0_0017AA40,
   Pad_AnyButtonPressed_1_00180F10, Menu_WaitLoad_0_0018AAD0, Msg_Show_1_0018AEB0, MapObj_CheckActivate_0_001B1A20, Player_MapControls_0_001C4760,
   Player_DropItem_0_001CAC30, text_0015F540.s, text_0015FC60.s, text_00164440.s,
   text_00169F40.s, text_0016AE30.s */

u8 D_003407E0[0xec130];
u8 D_003406E0[0x100];
u8 D_003406D0[0x10];
s32 D_0033F6D0[0x400];
u8 D_0033F540[0x190];
u8 D_0033F500[0x40];
Vec D_0033E500[0x100];
u8 D_003174F0[0x27010];
u8 D_003174E0[0x10];
u8 D_003172E0[0x200];
u8 D_00317274[0x6c] __attribute__((aligned(4))); /* also D_00317278 */
f32 D_00317270[0x1];
f32 D_0031726C[0x1];
u8 D_00317254[0x18] __attribute__((aligned(4))); /* also D_00317258 */
f32 D_00317250[0x1];
f32 D_0031724C[0x1];
f32 D_00317248[0x1];
f32 D_00317244[0x1];
f32 D_00317240[0x1];
f32 D_0031723C[0x1];
u8 D_00317238[0x4]; /* also D_0031723A */
u16 D_00317230[0x4];
s32 D_00316A20[0x204];
u8 D_00315200[0x1820];
u8 D_003141F0[0x1010];
f32 D_003139E0[0x204];
