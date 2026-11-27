#include "common.h"

/* sdata_00201B80: the game's data at 0x00201B80..., one object per label. */
/* used by: Mem_Init_2_00128F10, Camera_UpdateView_1_001296C0, Frame_RenderGame_1_0012A070, Frame_UpdateGame_1_0012A520,
   Loading_Loop_0_0012AC00, Game_StartSession_0_0012B120, Game_RunSubLoop_0_0012B8E0, main_3_0012BF40, Game_RequestTitle_0_0012C040,
   Game_RequestExit_0_0012C070, Game_RequestMode12A_0_0012C0A0, Game_RequestMode12B_0_0012C0C0, SndEmit_SetEnabled_0_0012F6E0, SndEmit_Update_1_0012F6F0,
   Enemy_CalcAimOffset_1_00134620, Enemy_SelectAttack_1_00135490, EnemyCmd_PlaySe_1_001453A0, GsPkt_DrawClearRect_0_00153D80, Gfx_SphereInFrustum_1_00153FA0,
   Gfx_SetFogScale_0_001541E0, Gfx_KickFrame_1_00154B70, Gfx_WaitDraw_1_001552A0, Gfx_FlipBuffers_2_00155370, Arc_FindByHash_2_0015ABD0,
   Arc_Mount_2_0015AD00, Frame_IncCounter_1_0015C9E0, Rand_Next_3_0015ED20, Noise_Fbm_1_0015F040, Sfx_DrawAll_1_00168A40,
   Sfx_UpdateTransforms_1_00169030, Sfx_UpdateAll_1_00169400, Sfx_CullFinished_0_00169630, Sfx_SpawnFromStam_2_00169BD0, Sfx_LoadStam_1_00169D70,
   Sfx_BuildNodeTree_0_0016A9D0, Sfx_ClearAll_1_0016AB50, Sfx_LoadSystemStam_1_0016AE30, Sfx_ListInsert_0_0016AF40, Sfx_ListAlloc_0_0016B0F0,
   Mdl_SetBlendMode_1_0016F280, Tex_Lookup_1_00177BB0, Tex_RegisterTtix_0_00178080, Timer_Init_3_001787F0, Ui_SetOffset_0_001803D0,
   UiProc_DrawText_0_00180CA0, Ui_SetScrollSpeed_0_00180F50, Ui_BeginSprites_1_00181420, Ui_DrawSprite_2_00181680, Ui_SetAlphaClamped_0_00182050,
   Ui_DrawSpriteRotated_1_00182080, Ui_LoadMapSheet_3_00183750, Ui_LoadAreaImage_3_00183970, Ui_LoadCharImage_3_00183B90, Ui_LoadItemImage_3_00183DC0,
   Ui_IsImageLoading_0_00183FF0, Font_FindGlyph_2_00188910, Menu_Draw_1_00189F40, Menu_Update_1_0018A200, Menu_SetSubMode_0_0018A330,
   Menu_HandleEvent_0_0018A420, Menu_WaitLoad_0_0018AAD0, Hud_Draw_0_0018E480, Option_ResetLayoutA_0_00190340, Option_ResetLayoutB_0_00190490,
   Option_MapKeyTypeC_0_00190680, OptionProc_DrawSound_0_00190A50, OptionProc_DrawScreen_0_00190DC0, Databook_Draw_0_001952B0, Databook_Update_0_00195460,
   DbTable_FindA_0_001957E0, DbTable_FindB_0_00195840, DbChar_FindEntry_0_00195900, DbChar_GetName_0_00195970, DbMap_GetName_0_00195A30,
   DbMap_GetLocationName_1_00195AA0, DbCharProc_Layout_0_00195D80, DbChar_Draw_0_00195E30, DbItem_Draw_0_00196E20, DbItem_DrawStats_0_00196F90,
   DbItem_Open_0_001979C0, DbItem_Update_0_00197B80, DbItem_ResetLayout_0_00197DD0, DbItem_LoadEntry_0_00197F90, DbMap_Draw_0_00198160,
   Equip_Reset_0_00199170, Equip_Draw_0_00199190, Equip_DrawStatus_0_00199260, Equip_Open_0_001997A0, Equip_Update_0_00199AD0,
   Equip_BuildList_0_0019A1D0, EquipProc_Pos_0_0019A6A0, Hud_DrawShortcuts_0_0019BBE0, ItemMenu_Draw_0_0019C6D0, ItemMenu_Open_0_0019D290,
   ItemMenu_Update_0_0019D580, ItemMenu_UseItem_0_0019DA70, ItemMenu_BuildList_1_0019DCF0, ItemMenuProc_Pos_0_0019DE90, Status_Draw_0_0019DF90,
   Shop_Draw_0_001A1460, Shop_DrawStatus_0_001A1550, Shop_Open_1_001A1B40, Shop_Update_0_001A1C80, Shop_BuildList_0_001A2C00,
   ShopProc_Pos_0_001A2FF0, Storage_Draw_0_001A30E0, Title_LoadGame_0_001A35B0, TitleMenu_Open_1_001A4420, EnemyMgr_FreeSlot_0_001A5070,
   EnemyMgr_Init_0_001A5340, Enemy_Draw_1_001A5DE0, Save_ParseOptions_1_001A8B90, Save_WriteOptions_1_001A8CA0, Save_ApplyLoaded_0_001A8E30,
   Save_ParseOptionsB_0_001A8F00, Save_ParseGame_1_001A9080, Save_GetData_1_001A9400, Option_GetSoundMode_0_001A9430, Option_GetMoveEffect_2_001A9440,
   Option_GetControlType_1_001A9450, Option_GetOutputMode_0_001A9460, Option_GetBgmVolume_1_001A9470, Option_GetSeVolume_1_001A9480, Option_GetByte3_0_001A9490,
   Option_GetByte2_0_001A94A0, Option_Load_1_001A94B0, Option_Store_1_001A94E0, Item_ClearNewFlag_0_001A9510, Inventory_AddItem_1_001A95A0,
   Inventory_GetSlot_1_001A97D0, MapState_OffsetObjects_0_001A9810, MapState_GetObjectPos_0_001A9900, MapState_SetObjectPos_0_001A9A20, Save_TestItemBit_1_001A9B40,
   Save_SetItemBit_1_001A9B90, MapState_TestBit_0_001A9BE0, MapState_SetBit_0_001A9CA0, MapState_GetField_0_001A9D50, MapState_SetField_0_001A9E10,
   Bestiary_IsSeen_2_001A9EC0, Bestiary_SetSeen_1_001A9F10, Bestiary_IsKilled_1_001A9F60, Bestiary_SetKilled_1_001A9FA0, MapState_GetKillCount_0_001A9FF0,
   MapState_GetBestKillRate_0_001AA090, MapState_IncVisits_0_001AA130, MapState_GetCounter_0_001AA1E0, MapState_IncCounter_0_001AA2A0, MapState_IsVisited_1_001AA440,
   MapState_SetVisited_0_001AA4C0, MapState_GetWord_1_001AA540, MapState_SetWord_1_001AA5D0, Inventory_FindItem_0_001AA650, Inventory_GetSlotFlag_0_001AA6B0,
   Inventory_GetSlotCount_0_001AA6D0, Player_SetStatByte_0_001AA700, Save_GetByte2E_0_001AA740, Save_GetByte2F_0_001AA750, Save_InitNewGame_1_001AA760,
   Save_InitOptions_1_001AB280, Save_StartNewGame_0_001AB290, Hud_DrawOverlay_0_001BCB60, Player_UpdateArea_0_001BD4E0, Player_AddStatus_1_001C88E0,
   Player_UpdateFrame_0_001C9830, PlayerData_Get_2_001C9BA0, PlayerData_Load_1_001C9BB0, Player_CopyLightPos_0_001C9C00, Player_LoadModel_1_001C9CD0,
   PlayerData_InitNew_0_001C9EA0, Player_UpdateStatusEffects_0_001C9FF0, SndDrv_StartThread_1_001D8210, SndDrv_Shutdown_1_001D8820, Se_FlushQueue_0_001D9E30,
   Se_QueueCommand_1_001DBDB0, Credits_DrawFrame_0_001DC900, Credits_Update_0_001DCC30, Credits_DrawBg_0_001DCE70, CreditsProc_DrawText_0_001DCF80,
   TitleProc_DrawPushStart_0_001DD510, Credits_HandleEvent_0_001DD650, Menu_DrawHelpText_1_001DD700, MapSe_StreamUpdate_0_001E1250, GsText_Alloc_0_001E1E08,
   GsText_SetBuffer_0_001E1E70, GsText_SetQword_0_001E1E80, GsText_SetFlag_0_001E1EA8, GsText_SetVram_0_001E1F28, GsText_SetRange_0_001E1FF0,
   GsText_GetCount_0_001E2008, GsText_Init_1_001E2018, GsText_ResetState_0_001E2148, GsText_FlushPacket_0_001E21E0, GsText_Begin_1_001E23C8,
   GsText_End_1_001E2430, GsText_Kick_1_001E24A0, GsText_Printf_1_001E2578, GsText_PrintId_0_001E2610, GsText_PrintfAt_1_001E2650,
   GsText_PrintIdAt_0_001E26F8, GsText_SetPriority_0_001E2A08, GsText_SetSpacing_0_001E2A18, GsText_SetScale_1_001E2A28, GsText_SetScaleVec_0_001E2A48,
   GsText_SetScaleUniform_0_001E2A68, GsText_SetColorIdx_0_001E2AB0, GsText_SetLineHeight_0_001E2AC8, GsText_SetAlign_0_001E2AD8, GsText_SetFlagA_0_001E2AE8,
   GsText_SetFlagB_0_001E2AF8, GsText_SetFlagC_0_001E2B08, GsText_SetPos_1_001E2B18, GsText_GetPos_1_001E2B40, GsText_SetColor_0_001E2B60,
   GsText_Measure_2_001E2B88, GsText_GetColor_1_001E2D08, GsText_SetColorQ_0_001E2D38, GsText_ParseEscape_1_001E2D70, GsText_FindGlyph_1_001E3058,
   GsText_WaitDma_1_001E3688, GsText_EmitQuad_1_001E3790, GsText_EmitTag_0_001E39F8, Credits_Load_1_001E3B48, CreditsCb_DrawText_0_001E4518,
   MovieVideo_PutData_0_001EA0D0, Movie_Init_1_001EC5E0, Movie_ReadLoop_1_001ECAB0, MapSheet_Open_0_001ED620, MapSheet_Update_0_001ED740,
   text_001679E0.s, text_00169F40.s, text_0016AE30.s, text_0016BD00.s,
   text_00177BB0.s, text_00181420.s, text_00188010.s, text_001889E0.s,
   text_001A1C80.s, text_001A4420.s, text_001A4990.s, text_001A5DE0.s,
   text_001E2430.s, text_001E2748.s, text_001E3058.s, text_001E3178.s,
   text_001E3758.s, text_001E3B48.s */
#pragma explicit_zero_data on

extern u8 D_001FCEF0[];
extern u8 D_001FD090[];
extern u8 D_001FD268[];
extern u8 D_001FE714[];
extern u8 D_00222A80[];
extern u8 D_00495B60[];
extern u8 D_00496B60[];
extern u8 D_004A4880[];
extern u8 D_004A48A0[];
extern u8 D_004A4980[];
extern u8 D_004A5A60[];
extern u8 D_004AA440[];
extern u8 D_004B4D10[];

f32 D_00201B80 __attribute__((aligned(16))) = 0.3333333f;
s32 D_00201B84[0x1] = { 0x3d7fffff };
f32 D_00201B88 = 16.666666f;
f32 D_00201B8C = 33.333332f;
f32 D_00201B90[0x1c] = { 0.79999995f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s32 D_00201C00[0x4] = { 0x1900000, 0, 0, 0 };
s32 D_00201C10 = (s32)D_00222A80;
f32 D_00201C14 = 450.0f;
f32 D_00201C18 = 1.0f;
f32 D_00201C1C = 655500.0f;
u32 D_00201C20 = 1;
u32 D_00201C24 = 0xffff0;
s32 D_00201C28[0x1] = { 1 };
f32 D_00201C2C = 1.5707964f;
s32 D_00201C30 = 0xa;
s32 D_00201C34 = 0x270f;
s32 D_00201C38[0x2] = { 1, 0 };
s32 D_00201C40[0x2] = { 0x64006400, 0x64006400 };
s32 D_00201C48[0x2] = { 1, 0 };
f32 D_00201C50[0x2] = { 5000.0f, 0.0f };
s32 D_00201C58 = -1;
s32 D_00201C5C[0x1] = { -0x80000000 };
f32 D_00201C60 = 3000.0f;
f32 D_00201C64[0x1] = { 3.141592f };
f32 D_00201C68[0x1] = { 3.0f };
f32 D_00201C6C[0x1] = { 0.03125f };
f32 D_00201C70[0x1] = { 3.141592f };
f32 D_00201C74[0x1] = { 3.0f };
f32 D_00201C78[0x1] = { 0.03125f };
s32 D_00201C7C = 3;
s32 D_00201C80 = 0x532525;
s32 D_00201C84 = 0x74915435;
s32 D_00201C88 = -0x17cacaac;
f32 D_00201C8C = -1000.0f;
f32 D_00201C90 = 1.0f;
s32 D_00201C94 = 1;
s32 D_00201C98 = 1;
u16 D_00201C9C[0x2] = { 0xffff, 0 };
u16 D_00201CA0[0x2] = { 0xffff, 0 };
u16 D_00201CA4[0x2] = { 0xffff, 0 };
s32 D_00201CA8 = 0x49535453;
s32 D_00201CAC = 0x61545452;
s32 D_00201CB0 = 0x61495450;
s32 D_00201CB4 = 0x43494454;
s32 D_00201CB8 = 0x4d584653;
u8 D_00201CBC[0x4] = { 0, 0x10, 0x20, 0x40 };
s32 D_00201CC0[0x2] = { -1, 0 };
s32 D_00201CC8 = -2;
s32 D_00201CCC = -2;
f32 D_00201CD0 = 16.0f;
s32 D_00201CD4 = -1;
s32 D_00201CD8 = 0x80;
s32 D_00201CDC = -1;
s32 D_00201CE0 = -1;
s32 D_00201CE4 = -1;
s32 D_00201CE8 = -1;
f32 D_00201CEC = 22.0f;
s32 D_00201CF0 = -1;
s32 D_00201CF4 = -1;
s32 D_00201CF8[0x2] = { (s32)((u8 *)D_001FCEF0 + 0x10), (s32)((u8 *)D_001FCEF0 + 0x20) };
s32 D_00201D00[0x2] = { (s32)((u8 *)D_001FD090 + 0x8), (s32)((u8 *)D_001FD090 + 0x10) };
s32 D_00201D08[0x2] = { 2, 0 };
s32 D_00201D10[0x2] = { 0, 1 };
s32 D_00201D18 = 1;
f32 D_00201D1C = -1.0f;
u8 D_00201D20[0x4] = { 0x19, 0x1a, 0x1b, 0 };
f32 *D_00201D24 = (f32 *)D_00496B60;
s8 *D_00201D28 = (s8 *)D_001FD268;
s8 *D_00201D2C = (s8 *)D_001FD268;
f32 D_00201D30 = -2.99f;
f32 D_00201D34 = -2.99f;
s32 D_00201D38 = 6;
s32 D_00201D3C[0x1] = { (s32)D_00495B60 };
f32 D_00201D40 = -2.99f;
f32 D_00201D44 = -2.99f;
s32 D_00201D48 = 6;
s32 *D_00201D4C = (s32 *)D_00495B60;
f32 *D_00201D50 = (f32 *)D_00496B60;
f32 D_00201D54 = -2.99f;
f32 D_00201D58 = -2.99f;
f32 D_00201D5C = -2.99f;
s32 D_00201D60 = -1;
s32 D_00201D64 = -1;
s32 *D_00201D68 = (s32 *)D_00495B60;
f32 *D_00201D6C = (f32 *)D_00496B60;
f32 D_00201D70 = -2.99f;
f32 D_00201D74 = -300.0f;
f32 D_00201D78 = -2.99f;
s32 *D_00201D7C = (s32 *)D_00495B60;
f32 *D_00201D80 = (f32 *)D_00496B60;
f32 D_00201D84 = -2.99f;
f32 D_00201D88 = -2.99f;
f32 D_00201D8C = -2.99f;
f32 D_00201D90 = -2.99f;
s32 D_00201D94 = -1;
f32 D_00201D98 = -20.0f;
f32 D_00201D9C = 30.0f;
s32 D_00201DA0[0x2] = { 0, 1 };
s32 D_00201DA8 = -1;
f32 D_00201DAC[0x5] __attribute__((aligned(4))) = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s32 D_00201DC0[0x1] = { (s32)D_004A4980 };
s32 D_00201DC4[0x1] = { (s32)D_004A5A60 };
s32 D_00201DC8[0xe] __attribute__((aligned(8))) = { (s32)D_004AA440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
s32 D_00201E00[0x4] = { (s32)D_004A4880, 0, 0, 0 };
s32 D_00201E10[0x4] = { (s32)D_004A48A0, 0, 0, 0 };
s32 D_00201E20[0x1] = { (s32)D_004B4D10 };
s32 D_00201E24[0x1] = { 0x80 };
u16 D_00201E28[0x4] = { 0x6040, 0, 0, 0 };
s32 D_00201E30[0x2] = { 0x5a, 0x2d };
s32 D_00201E38 = -1;
s32 D_00201E3C = 1;
u16 D_00201E40[0x2] = { 2, 0 };
f32 D_00201E44[0x1] = { -128.0f };
f32 D_00201E48[0x1] = { -128.0f };
s32 D_00201E4C = (s32)((u8 *)D_001FE714 + 0x4);
s32 D_00201E50 = -1;
s32 D_00201E54 = -1;
s32 D_00201E58 = 0;
s32 D_00201E5C[0x1] = { 0 };
s32 D_00201E60[0x2] = { 0, 0 };
u16 D_00201E68[0x4] = { 0, 0, 0, 0 };
s32 D_00201E70 = 1;
s32 D_00201E74[0x1] = { -0x48ff0000 };
s32 D_00201E78[0x2] = { -1, 0 };
