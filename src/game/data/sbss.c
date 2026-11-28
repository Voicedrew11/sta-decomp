#include "common.h"

/* sbss_00201E80: the game's .sbss from 0x00201E80, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Mem_LayoutRegions_1_00128E80, Mem_Init_2_00128F10, Gfx_InitDisplay_2_00129040, Camera_UpdateView_1_001296C0,
   Frame_RenderGame_1_0012A070, Frame_UpdateGame_1_0012A520, Game_Shutdown_0_0012AA30, Loading_Loop_0_0012AC00, Game_StartSession_0_0012B120,
   Game_MainLoop_2_0012B350, Frame_RenderLoading_0_0012B600, Game_RunSubLoop_0_0012B8E0, main_3_0012BF40, Game_GetBusy_0_0012C020,
   Game_SetBusy_1_0012C030, Game_RequestTitle_0_0012C040, Game_RequestExit_0_0012C070, Game_RequestMode12A_0_0012C0A0, Game_RequestMode12B_0_0012C0C0,
   Game_TryRequestEvent_0_0012C110, Snd_GetStreamFlag_0_0012C400, Snd_UpdateStreams_0_0012C4D0, Snd_UpdateBgm_0_0012C7C0, Snd_BindMapSe_0_0012DA90,
   Snd_StartStream1_0_0012DD10, Snd_StartStream2_0_0012DE00, Snd_LoadSystemBank_1_0012DEE0, Snd_Init_2_0012DF90, Snd_StopStream_1_0012F550,
   SndEmit_Update_1_0012F6F0, SndEmit_OffsetPositions_1_0012F7E0, Strm_GetParam_0_001303C0, Strm_SetVolume_2_001303D0, Strm_Stop_2_00130440,
   Strm_SetFadeStep_1_001304B0, Strm_Update_1_001304C0, Strm_PlayFile_2_00130590, Snd_PlaySeVolPan_1_00131520, Snd_PlaySeAttached_1_00131560,
   Snd_PlaySeAt_2_001315A0, Snd_PlaySe_3_00131600, Snd_StartRequest_2_00131640, ScreenFx_DrawBlurPasses_0_00131970, ScreenFx_DrawCopy_0_00132190,
   ScreenFx_DrawLetterbox_0_001325F0, ScreenFx_DrawRestore_0_001327B0, ScreenFx_Draw_0_00132930, ScreenFx_DrawModelOverlay_0_00132A70, Enemy_EvalAttackRange_1_00135990,
   Enemy_InitState_1_00136700, Actor_UpdateBones_0_001370A0, Actor_OffsetColliders_1_00137730, Actor_CollideSegment_0_00138920, Combat_UpdateAttack_0_00139330,
   Actor_ProcessHitEvents_0_00139F30, Actor_ResolveWallCollision_0_0013A450, Actor_ResolveGround_0_0013A720, Actor_UpdateCollision_0_0013B220, Actors_UpdateAll_1_0013BBC0,
   Enemy_SetGlobalFlagF1C_0_0013D680, Enemy_GetGlobalFlagF1C_0_0013D690, Enemy_SetAiDisabled_0_0013D6A0, Enemy_IsAiDisabled_0_0013D6B0, Enemy_GetBoneMatrix_0_0013F030,
   Enemy_BreakPart_0_0013F210, EnemyCmd_Set5B5b7_1_001438A0, EnemyCmd_Set5B4b6_1_00143920, EnemyCmd_Set5B4b5_1_00143930, EnemyCmd_Set5B8_1_00143940,
   EnemyCmd_Set60B_1_00143950, EnemyCmd_GetRelativePos_0_00143960, EnemyCmd_Get608_1_00143B20, EnemyCmd_SelectMotion_1_00143B90, EnemyCmd_Set5A1b5_1_00143BB0,
   EnemyCmd_Set5B4b4_1_00143BC0, EnemyCmd_StartTimer_0_00143BD0, EnemyCmd_GetMotionFrame_1_00143C30, EnemyCmd_ResolveHit_0_00143C70, EnemyCmd_SetPartValue_1_00143D10,
   EnemyCmd_GetVec660_0_00143D60, EnemyCmd_UpdatePartStat_1_00143DF0, EnemyCmd_LoadPart_1_00143E00, EnemyCmd_InitPart_1_00143E10, EnemyCmd_FindTargetInCone_0_00143E20,
   EnemyCmd_GetTargetPos_0_001441B0, EnemyCmd_BroadcastMotion_1_001442F0, EnemyCmd_Kill_1_00144360, EnemyCmd_SetHiddenFlags_0_00144370, EnemyCmd_Set5B2b6w2_1_001443E0,
   EnemyCmd_Set5B2b2_1_001443F0, EnemyCmd_Set5B2b1_1_00144400, EnemyCmd_Set5B0b2_1_00144410, EnemyCmd_ClampHpFromFlag_1_00144420, EnemyCmd_StoreHpToFlag_1_00144490,
   EnemyCmd_Set5B1b4_1_001444E0, EnemyCmd_FindSpawnPoint_0_001444F0, EnemyCmd_Set5B2b4_1_00144960, EnemyCmd_GetPosition_2_00144970, EnemyCmd_SpawnEffect_0_00144A00,
   EnemyCmd_SpawnEffectB_0_00144BE0, EnemyCmd_ResetState_1_00144D50, EnemyCmd_Set5B3b3_1_00144D60, EnemyCmd_Set5B2b0_1_00144D70, EnemyCmd_BroadcastFrame_1_00144D80,
   EnemyCmd_Set5B1b7_1_00144DF0, EnemyCmd_Set5B1b6_1_00144E00, EnemyCmd_BreakPart_1_00144E10, EnemyCmd_Set5B0b0_1_00144E30, EnemyCmd_HealPercent_1_00144E40,
   EnemyCmd_Set5B1b5_1_00144EE0, EnemyCmd_Set5B1b3_1_00144EF0, EnemyCmd_Set5B1b2Notify_0_00144F00, EnemyCmd_GetParamIdx_1_00144F60, EnemyCmd_Set5B1b1_1_00144FA0,
   EnemyCmd_UpdateParamFlags_1_00144FB0, EnemyCmd_RegisterKill_0_00144FC0, EnemyCmd_RegisterSeen_0_00145010, EnemyCmd_Set5B1b0_1_00145060, EnemyCmd_SetDead_1_001450D0,
   EnemyCmd_Set5B0b7_1_001450E0, EnemyCmd_KillNow_1_001450F0, EnemyCmd_GetType_1_00145140, EnemyCmd_Set5B0b1_1_00145180, EnemyCmd_AddHp_2_00145190,
   EnemyCmd_Get5B0b0_1_001451A0, EnemyCmd_AddPartValue_0_001451E0, EnemyCmd_GetHpPercent_2_00145250, EnemyCmd_SetMode_1_00145290, EnemyCmd_SelectMotionB_1_001452A0,
   EnemyCmd_Set609_1_001452C0, EnemyCmd_PlaySe_1_001453A0, EnemyCmd_GetModelPos_0_00145410, EnemyCmd_ResetVectors_1_00145610, Player_GetFlag521b5_1_00145620,
   Player_GetRightVector_1_00145640, Player_GetForwardVector_2_001456B0, Player_GetRotationPtr_1_00145710, Player_CopyRotation_1_00145720, Player_GetBody_1_00145770,
   Player_CopyVec_0_00145780, Map_RaycastNearest_0_00145840, Map_RaycastCapsule_0_00145D10, Actor_GetBoneWorldMatrix_0_001464A0, Actor_GetBone_0_001468F0,
   Proj_UpdateHoming_0_00147710, FxProc_AreaDamage_0_00149810, FxProc_ScatterAround_0_0014A210, FxProc_FollowPlayer_0_0014AAF0, FxProc_SeekNearestEnemy_0_0014AB80,
   FxProc_AimAlongGround_0_0014AF10, FxProc_HomingProjectile_0_0014B1B0, FxProc_InitHoming_0_0014B9E0, FxProc_PullTowardEnemy_0_0014BA10, FxProc_AttachRotated_0_0014C060,
   FxProc_AttachRotatedB_0_0014C0E0, FxProc_ScaleByDistance_0_0014C6F0, FxProc_AimAtEnemyCone_0_0014CAC0, FxProc_AimAtBestTarget_0_0014D020, FxProc_MoveToward_0_0014D310,
   FxProc_InitTowardEnemy_0_0014D410, FxProc_InitSeekCone_0_0014D700, Task_Register_0_0014DB10, Task_InitAll_1_0014DB60, Res_Open_0_0014DC70,
   Coll_SweepRecursive_0_00150730, Coll_QueryMapCells_0_001520E0, Coll_TestCellTriangles_1_00152700, Coll_TestTriangle_1_00152D90, GsPkt_ResetFrame_1_00153770,
   GsPkt_DrawFadeRect_0_00153B50, GsPkt_DrawClearRect_0_00153D80, Gfx_SphereInFrustum_1_00153FA0, GsPkt_SetLayerB_0_00154610, GsPkt_SetLayer_1_00154700,
   GsPkt_SetLayerRange_0_001547F0, GsPkt_SetLayerTop_0_001548F0, Gfx_KickFrame_1_00154B70, Gfx_FlipBuffers_2_00155370, Gfx_UploadVu1Program_0_00155460,
   GsPkt_EndLayer_1_00155900, GsPkt_EndLayerEx_0_001559C0, Draw_Prim_1_00155DB0, ScreenFx_DrawFlash_0_00156AF0, ScreenFx_DrawDistort_0_00156CE0,
   ScreenFx_DrawFade_0_00156F60, ScreenFx_DrawBars_0_00157110, ScreenFx_DrawTint_0_00157320, ScreenFx_DrawRadialBlur_0_001580E0, ScreenFx_DrawMotionBlur_0_00158900,
   ScreenFx_DrawShift_0_00158BF0, ScreenFx_Init_1_00159A60, File_WaitRead_1_0015A3A0, File_Read_2_0015A470, Arc_FindByHash_2_0015ABD0,
   Arc_Mount_2_0015AD00, Cd_Init_2_0015B040, Fog_ApplyDefault_0_0015B270, Light_UpdateModel_0_0015B360, Iop_Reboot_3_0015CB50,
   Glow_Reset_0_0015D650, Glow_GetParams_0_0015D760, Glow_DrawList_0_0015D900, Glow_FindNear_0_0015DA00, Fx_SpawnParticle_1_00161060,
   Fx_SpawnBurst_1_00162F30, Fx_EvalCurveVec_1_001631E0, Fx_EvalCurve_1_00163700, Fx_GetParentIdx_0_00163C40, Fx_GetWorldMatrix_1_00163C80,
   Fx_GetWorldPos_1_00163D90, Fx_DrawSprites_0_00163FF0, Fx_ResetSpriteCount_0_00164320, Fx_FreeSpriteBuffer_0_00164330, Fx_BeginFrame_0_00164350,
   ScrCmd_GetVar_1_00164CE0, ScrCmd_SetVar_1_00164DC0, ScrCmd_ResetAllSlots_0_00164E80, ScrCmd_SendEvent_1_00164EE0, Script_GetArgPtr_2_00165130,
   Script_LoadLocal_1_00165400, Script_LoadLocalB_1_00165770, Script_RunEvent_2_00166C10, Script_RunAll_1_00166CC0, Sfx_AimMatrix_0_00167310,
   Sfx_OffsetAll_1_00167850, Sfx_DrawMesh_0_00167C90, Sfx_DrawAll_1_00168A40, Sfx_UpdateInstance_0_00168D70, Sfx_UpdateTransforms_1_00169030,
   Sfx_UpdateAll_1_00169400, Sfx_CullFinished_0_00169630, Sfx_Spawn_2_00169B50, Sfx_ClearAll_1_0016AB50, Sfx_InitSystem_1_0016AD10,
   Sfx_LoadSystemStam_1_0016AE30, Sfx_ListInsert_0_0016AF40, Sfx_ListAlloc_0_0016B0F0, Mdl_FlushLayer_0_0016B280, Mdl_SetLayerTex_0_0016B2D0,
   Mdl_SetLayerForMesh_0_0016B360, Mdl_SetLayerSimple_0_0016B480, Mdl_SetLayerForBounds_0_0016B500, Mdl_DecodeVertsScaled_0_0016B730, Mdl_DrawLit_0_0016B970,
   Mdl_DrawMeshesB_1_0016CD80, Mdl_DrawMeshesC_1_0016D380, Mdl_DrawMeshesD_1_0016D830, Mdl_EmitStrip_1_0016DED0, Mdl_EmitMeshVu1_1_0016E760,
   Mdl_EmitMeshVu1B_1_0016EB70, Mdl_EmitPolys_1_0016EF70, Mdl_BindTexture_0_0016F440, Mdl_SetBoneRotation_0_001710D0, Mdl_UpdateBoneMatricesCur_0_00171540,
   Mdl_GetFrameData_0_001715B0, Mdl_ResetBones_0_00171610, Mdl_BlendMotion_0_00171980, Mdl_AnimateCur_0_00171AF0, Mdl_AnimateWrap_0_00171B70,
   TexAnim_InitTables_0_001746A0, Tex_FlushLayer_0_00176440, Tex_BeginFrame_0_00176A60, Tex_Bind_1_00176B10, Timer_Update_3_00178760,
   Timer_GetTicks_3_001787A0, Timer_Init_3_001787F0, Lz_Decompress_2_00179040, Bits_Read_2_00179720, MapObj_FindById_0_00179DB0,
   Event_CheckTrigger_0_00179F80, MapCmd_SetFlag2034_0_0017A640, MapCmd_GetValue_0_0017B7A0, MapCmd_PlaySeOnObject_0_0017BAC0, MapCmd_PlaySeOnObjectB_0_0017BC50,
   MapCmd_GetTimer_0_0017C270, MapCmd_WaitEvent_0_0017C2A0, MapCmd_GetPlayerPos_1_0017CE80, MapCmd_SetPlayerPos_1_0017CF40, MapCmd_GetDistToObject_0_0017D000,
   MapCmd_GetPlayerRot_1_0017D240, MapCmd_SetSfxParamA_0_0017E5B0, MapCmd_GetSfxParamA_0_0017E760, MapCmd_SetSfxParamB_0_0017E940, MapCmd_GetSfxParamB_0_0017EAF0,
   Ui_DrawItemIconEx_0_0017EDC0, Ui_DrawItemIcon_0_0017F0D0, Movie_Update_0_001801F0, Ui_SetOffsetA_0_001803B0, Ui_SetOffsetB_0_001803C0,
   UiProc_DrawIcon_0_001803E0, Ui_DrawCursor_1_001805D0, UiProc_DrawText_0_00180CA0, Font_DrawDebugText_0_00180F80, Ui_BeginSprites_1_00181420,
   Ui_DrawSprite_2_00181680, Ui_DrawSpriteRotated_1_00182080, Ui_SetGlobalFlag_0_00182990, Ui_DrawGauge_0_00182EF0, Ui_DrawCursorB_0_00183090,
   Ui_DrawWindow_0_00183650, Ui_LoadMapSheet_3_00183750, Ui_LoadAreaImage_3_00183970, Ui_LoadCharImage_3_00183B90, Ui_LoadItemImage_3_00183DC0,
   Ui_IsImageLoading_0_00183FF0, Menu_DrawRingB_0_00184960, MenuProc_DrawGauge_0_00185030, MenuProc_DrawHpMp_1_00185740, Menu_SetOffset_0_00185B30,
   Menu_DrawBackground_0_00187B20, Font_Load_3_00188830, Font_FindGlyph_2_00188910, Menu_ResetTimers_0_00188F80, Save_GetSlotInfo_0_00188FF0,
   Menu_FreeSystemRes_0_00189080, Menu_LoadSystemRes_0_001891C0, Menu_FreeRes_0_00189270, Menu_LoadTitleRes_0_00189580, Menu_LoadLayout_0_00189740,
   Menu_LoadGameRes_0_00189AD0, MenuStack_Clear_1_00189E90, MenuStack_Pop_1_00189EA0, MenuStack_Push_1_00189ED0, Menu_Draw_1_00189F40,
   Menu_SetFlags_0_0018A310, Menu_HandleEvent_0_0018A420, Pause_Update_0_0018A650, Menu_UpdateFades_1_0018A910, Menu_WaitLoad_0_0018AAD0,
   Msg_SetParam_0_0018AEA0, Menu_GetCursor_1_0018B820, Menu_SetCursor_1_0018B840, MenuProc_DrawItemList_0_0018B860, SaveMenu_HandleEvent_0_0018C4C0,
   SaveMenu_Exit_0_0018D140, Loading_DrawText_2_0018E320, Loading_SetVisible_0_0018E470, Hud_Draw_0_0018E480, Option_DrawFrame_0_0018E980,
   Option_Update_2_0018EAE0, Option_QuitGame_0_0018EC40, Option_ScreenSetting_1_0018EDA0, Option_ControllerSetting_1_0018F0D0, Option_SoundSetting_1_0018F490,
   Option_MainMenu_0_0018F940, Option_Open_0_0018FFE0, Option_LerpLayout_0_00191820, LoadMenu_DrawList_0_00191CB0, LoadMenu_HandleEvent_0_00192900,
   LoadMenu_SetFromTitle_0_00193850, LoadMenu_Open_0_001939B0, LoadMenu_SelectDevice_0_00193E80, Ending_StaffRoll_2_00194FC0, Databook_Draw_0_001952B0,
   Databook_Update_0_00195460, DbChar_Find_0_00195770, DbItem_GetCount_1_001958A0, DbChar_GetCount_0_001958C0, DbMap_GetCount_1_001958E0,
   DbChar_FindEntry_0_00195900, DbChar_GetName_0_00195970, DbMap_GetKillRate_0_001959E0, DbMap_GetName_0_00195A30, DbMap_GetLocationName_1_00195AA0,
   Msg_GetText_2_00195B10, ItemSort_GetEntry_0_00195B80, ItemSort_GetCount_0_00195BE0, Databook_LoadRes_3_00195C00, DbCharProc_Layout_0_00195D80,
   DbChar_DrawStats_1_00195F70, DbChar_Update_0_00196940, DbItem_DrawStats_0_00196F90, DbItem_Open_0_001979C0, DbItem_Update_0_00197B80,
   DbItem_ResetLayout_0_00197DD0, DbItem_LoadEntry_0_00197F90, DbMap_Draw_0_00198160, DbMapProc_DrawInfo_1_00198570, DbMap_Update_0_00198BE0,
   DbMap_ResetLayout_0_00198D80, DbMap_BuildList_1_00199000, Equip_Reset_0_00199170, Equip_DrawStatus_0_00199260, Equip_Open_0_001997A0,
   Equip_Update_0_00199AD0, Equip_BuildList_0_0019A1D0, EquipProc_Pos_0_0019A6A0, Hud_IsHidden_0_0019A790, Hud_Reset_0_0019A7E0,
   Hud_DrawStatus_1_0019A920, Hud_HandleInput_0_0019B590, Hud_UpdateGauges_0_0019B8D0, Hud_DrawShortcuts_0_0019BBE0, ItemMenu_Draw_0_0019C6D0,
   ItemMenuProc_DrawGauge_0_0019CB90, ItemMenu_Open_0_0019D290, ItemMenu_Update_0_0019D580, ItemMenu_UseItem_0_0019DA70, ItemMenu_BuildList_1_0019DCF0,
   ItemMenuProc_Pos_0_0019DE90, PauseMenu_Open_0_0019E2F0, PauseMenu_Update_0_0019E400, GameOver_Reset_0_0019E8A0, GameOver_DrawFrame_0_0019E8B0,
   GameOverProc_DrawText_0_0019EA60, GameOver_Update_2_0019EDC0, Shop_DrawStatus_0_001A1550, Shop_Open_1_001A1B40, Shop_Update_0_001A1C80,
   Shop_BuildList_0_001A2C00, ShopProc_Pos_0_001A2FF0, Title_LoadGame_0_001A35B0, TitleProc_Back_0_001A3B60, Title_DrawLogo_0_001A3CC0,
   Title_HandleEvent_0_001A3EC0, Title_CheckSaveData_1_001A4570, Title_PlayPrologue_2_001A4890, Title_StartNewGame_0_001A4930, EnemyMgr_FreeSlot_0_001A5070,
   ActorList_AllocSlot_0_001A5530, ActorList_FindFree_0_001A55E0, ActorList_NextTargetable_0_001A5660, ActorList_NextB_0_001A5710, Enemy_Draw_1_001A5DE0,
   Enemy_Destroy_0_001A6A10, Enemy_Spawn_0_001A7420, EnemyData_Parse_0_001A7810, EnemyData_LoadTextures_0_001A7C70, ActorList_Init_1_001A82B0,
   EnemyType_Get_0_001A8360, EnemyType_LoadTable_0_001A83A0, Enemy_UpdateSfxTransform_0_001A83E0, Enemy_ScatterPart_0_001A8700, ItemMdl_Update_0_001AB690,
   ItemMdl_Spawn_0_001ABCC0, ItemMdl_SetTransform_0_001ABF70, ItemObj_UpdateTransforms_0_001AC4A0, ItemObj_TestVisible_0_001ACD90, ItemObj_SpawnProjectile_0_001AD2C0,
   ItemObj_Animate_0_001AD4E0, ItemObj_GetScale_0_001ADBA0, ItemObj_GetMatrix_0_001ADC60, ItemObj_DropToGround_0_001AE0E0, ItemObj_FindGround_0_001AE250,
   ItemObj_AllocSlot_1_001AE360, ItemObj_SpawnAt_0_001AE620, ItemObj_Spawn_0_001AE7C0, ItemObj_Drop_0_001AE900, ItemObj_SpawnThrown_0_001AEC00,
   ItemObj_SpawnFromMap_0_001AEE80, ItemObj_SpawnFromSource_0_001AF150, ItemObj_Free_1_001AF4A0, ItemObj_FreeOwned_0_001AF740, ItemObj_FreeAll_0_001AF840,
   ItemObj_SetPools_0_001AF970, ItemObj_Init_0_001AF980, Item_GetData_1_001AFC40, Item_GetTable_1_001AFC90, Item_LoadTables_0_001AFCA0,
   Item_LoadTableB_0_001AFFA0, Map_StreamUpdate_0_001B0020, MapObj_DropItem_0_001B0880, MapObj_SpawnItem_0_001B0990, Map_FindLoaded_0_001B0AE0,
   Map_SetVar_0_001B0B30, Map_GetLightIndex_0_001B0BC0, Map_GetGlowIndex_0_001B0C70, MapObj_SpawnSfx_0_001B0D60, MapObj_GetSfxMatrix_0_001B1050,
   MapObj_SetSfxFlag_0_001B11F0, MapObj_SetCamera_0_001B13B0, MapObj_GetCamera_0_001B1560, MapObj_SetNodeFlag_0_001B16E0, MapObj_GetCount_0_001B17E0,
   MapObj_GetCountB_0_001B18D0, MapObj_Find_1_001B19A0, MapObj_CheckActivate_0_001B1A20, Map_DrawArea_0_001B37F0, Map_UpdateSfxVisibility_0_001B41C0,
   Map_UpdateEnemySpawns_0_001B43A0, Map_RecenterWorld_1_001B4CB0, Map_FreeArea_1_001B5640, Map_FreeAll_1_001B5940, Map_OnAreaLoaded_0_001B6800,
   Map_LoadTextures_0_001B6FC0, Map_AllocAreaBuf_1_001B70E0, Map_SetPools_0_001B7470, Door_CheckOpen_0_001B8F70, Door_UpdateLocked_0_001B90F0,
   Chest_CheckOpen_0_001B9360, Trap_Attack_0_001BAA10, MapObj_UpdateAll_0_001BAB70, MapObj_InitAnim_1_001BB320, MapObj_SpawnContainedItem_0_001BB760,
   MapObj_Create_0_001BB8A0, Hud_AddMarker_0_001BC320, Hud_DrawWarning_0_001BC7A0, Hud_DrawOverlay_0_001BCB60, Player_GetEquipSlot_0_001BD350,
   Player_UpdateArea_0_001BD4E0, Player_CheckLadder_0_001BE050, Player_CheckCeiling_0_001BE390, Player_SpawnStepSfx_0_001BE510, PlayerProc_Update_0_001BEFA0,
   Player_UpdateHeldItem_0_001BFB70, Player_UpdatePickup_0_001C0A10, Player_HandleAction_0_001C0E60, Player_CheckFrontWall_0_001C1140, Player_CheckLedge_0_001C13B0,
   Player_HandleAttackInput_0_001C1A00, Player_HandleMagicInput_1_001C2190, Player_HandleWeaponSwitch_1_001C23E0, Player_UpdateSlide_0_001C3EF0, PlayerProc_Collide_0_001C5150,
   PlayerProc_Attack_0_001C55A0, Player_UpdateAttackState_0_001C5FB0, Player_UpdateMagicState_0_001C6250, Player_UpdateSwitchState_0_001C6470, Player_StartAttackMotion_1_001C6590,
   Player_StartMagicMotion_0_001C69A0, Player_StartSwitchMotion_1_001C6D40, Player_SetArmMotion_1_001C7020, Player_IsHitTarget_0_001C7320, Player_OnHitEnemy_0_001C73C0,
   Player_OnHitObject_0_001C7730, Player_TraceAttack_0_001C7850, Player_InitAttack_0_001C79B0, Player_GetWeaponSegment_0_001C7A70, Player_ClampPitch_0_001C7CA0,
   Player_TakeHit_1_001C7DC0, Player_TakeHitB_1_001C8070, Player_ApplyDamage_2_001C8320, Player_RollStatusEffect_1_001C8570, Camera_LookAt_0_001C89E0,
   Camera_SetPosition_0_001C8EA0, Camera_SetParams_0_001C8F30, Camera_Update_1_001C8F90, Player_Warp_0_001C92C0, Player_SetPosition_0_001C9320,
   Player_GetHeadPos_0_001C93A0, Player_GetPos_1_001C9410, Player_GetPosB_0_001C9490, Player_SetPosAndGround_0_001C94F0, Player_SetStartPos_0_001C9630,
   Player_LoadStartPos_0_001C96F0, Player_UpdateFrame_0_001C9830, Player_GetHpS16_0_001C99C0, Player_IsCrouching_0_001C9A20, Player_IsMoving_0_001C9A80,
   Player_IsActionLocked_0_001C9AE0, Player_GetCameraMode_0_001C9B50, Player_GetBodyState_1_001C9B60, Player_Exists_3_001C9BF0, Player_Destroy_1_001C9C30,
   Player_LoadModel_1_001C9CD0, Player_Respawn_1_001C9E30, Player_UpdateStatusEffects_0_001C9FF0, Player_ThrowItem_0_001CA960, Player_HoldItem_0_001CAB20,
   Player_DropItem_0_001CAC30, Player_PlaceItem_0_001CADF0, Player_ReleaseHeldItem_0_001CAE90, Player_UpdateRegen_1_001CD6C0, Player_UpdateMp_1_001CDF80,
   Attack_PlaySe_0_001D1E80, Attack_SpawnSfx_0_001D1F20, SndDrv_StartThread_1_001D8210, SndDrv_IsInitialized_1_001D8810, SndDrv_Shutdown_1_001D8820,
   SndDrv_Bind_2_001D8890, Strm_DrvClose_1_001D8DF0, Strm_DrvInit_0_001D8E30, SndDrv_FlushEffects_0_001D8E70, SndDrv_AllocBuffer_1_001D8F30,
   Bgm_ApplyVolume_0_001D9820, Bgm_Init_0_001D99A0, Bgm_DmaChunk_0_001D9BC0, Bgm_RpcCallback_0_001D9DC0, Se_FlushQueue_0_001D9E30,
   Se_SendVoiceParams_0_001DA1D0, Se_PollTransfer_0_001DAA50, Se_UploadBank_1_001DAA90, Se_PollTransferB_0_001DB4D0, Se_UploadBankB_1_001DB510,
   Se_Init_1_001DBAC0, Se_QueueCommand_1_001DBDB0, Credits_DrawFrame_0_001DC900, Credits_Update_0_001DCC30, CreditsProc_DrawText_0_001DCF80,
   TitleProc_DrawPushStart_0_001DD510, Credits_HandleEvent_0_001DD650, Menu_DrawHelpText_1_001DD700, ShopMenu_DrawRingA_0_001DD7F0, ShopProc_DrawItemInfo_0_001DDA20,
   ShopProc_DrawItemStats_0_001DE2D0, ShopMenu_DrawRingC_0_001DEB00, ShopProc_DrawCommand_2_001DED50, Menu_DrawItemDesc_1_001DF360, Menu_ResetDescScroll_0_001DF460,
   PlayTime_Update_1_001DF670, PlayTime_DiffNow_2_001DF910, PlayTime_CopyClock_1_001DF930, PlayTime_Resume_1_001DF960, PlayTime_Pause_1_001DF990,
   PlayTime_Tick_1_001DF9A0, PlayTime_Load_1_001DFAA0, PlayTime_Reset_1_001DFBB0, Task_RunAll_1_001DFCB0, Task_Start_1_001E0590,
   GlowFx_Update_0_001E0C10, GlowFx_Stop_0_001E0D30, GlowFx_StopAll_0_001E0E80, GlowFx_Start_0_001E1050, MapSe_StreamUpdate_0_001E1250,
   ImageLoader_Request_1_001E1570, ImageLoader_SetFlag_0_001E1760, MapSe_LoadTask_1_001E19A0, SaveSys_GetSlotCount_0_001E5E80, SaveSys_StartRead_0_001E5F30,
   SaveSys_GetCurSlotState_0_001E6060, SaveSys_GetResult_0_001E6080, SaveSys_IsCardReady_0_001E6110, SaveSys_StartWrite_0_001E6170, SaveSys_StartLoad_0_001E62A0,
   SaveSys_StartFormat_0_001E6410, SaveSys_StepSave_2_001E64E0, SaveSys_StepLoad_2_001E72A0, SaveSys_StepScan_1_001E7880, SaveSys_StepCheckSpace_0_001E7C10,
   SaveSys_StepUnformat_1_001E7DF0, SaveSys_StepCheckCard_0_001E7FA0, SaveSys_GetPort_1_001E8290, SaveSys_SetPort_1_001E82A0, SaveSys_Update_2_001E8500,
   SaveSys_Init_1_001E85E0, Movie_InitDisplay_1_001E9AA0, Movie_ReadLoop_1_001ECAB0, MapSheet_Draw_0_001ED630, MapSheet_Update_0_001ED740,
   Ending_DrawText_0_001ED850, Ending_Update_0_001ED9A0, Ending_Draw_0_001EDAD0, Ending_HandleEvent_0_001EDCC0,
   text_00100000.s, text_001303D0.s, text_001329D0.s, text_0013A720.s,
   text_0013F210.s, text_00145A80.s, text_00148D00.s, text_0014FA30.s,
   text_00151E50.s, text_00153770.s, text_00155090.s, text_00157630.s,
   text_00160370.s, text_00167310.s, text_001679E0.s, text_00168480.s,
   text_0016AE30.s, text_0016B360.s, text_0016BD00.s, text_0016DC70.s,
   text_0016EF70.s, text_001777C0.s, text_001787C0.s, text_00179720.s,
   text_001797E0.s, text_0017BAC0.s, text_0017E5B0.s, text_0017EAF0.s,
   text_00181420.s, text_00185740.s, text_00185D70.s, text_00188010.s,
   text_001889E0.s, text_00189740.s, text_0018B860.s, text_00196330.s,
   text_001973F0.s, text_001A1C80.s, text_001A4990.s, text_001A5DE0.s,
   text_001A7D90.s, text_001A8510.s, text_001A8700.s, text_001ACD90.s,
   text_001AD2C0.s, text_001AE510.s, text_001AF4A0.s, text_001AFFA0.s,
   text_001B0EB0.s, text_001B17E0.s, text_001B43A0.s, text_001B51F0.s,
   text_001B9F10.s, text_001BAB70.s, text_001BBCC0.s, text_001C55A0.s,
   text_001C6590.s, text_001D8F30.s, text_001DDA20.s, text_001DE2D0.s,
   text_001E8C50.s */

u8 D_00202420[0x60];
f32 D_0020241C;
f32 D_00202418;
f32 D_00202414;
s32 D_00202410;
f32 D_0020240C;
f32 D_00202408;
f32 D_00202404;
s32 D_00202400;
s32 D_002023FC;
s32 D_002023F8;
s32 D_002023F4;
s32 D_002023F0;
s32 D_002023EC;
s32 D_002023E8;
u8 D_002023E4[0x4];
s32 D_002023E0;
u8 D_002023DC[0x4];
s32 D_002023D8;
s32 D_002023D4;
s32 D_002023D0;
s32 D_002023CC;
s32 D_002023C8;
s32 D_002023C4;
s32 D_002023C0;
s32 D_002023BC;
s32 D_002023B8;
s32 D_002023B4;
u8 D_002023B0[0x4];
u8 D_002023AC[0x4];
s32 D_002023A8;
u8 D_002023A0[0x8]; /* also D_002023A5, D_002023A6, D_002023A7 */
u8 D_00202398[0x8]; /* also D_00202399, D_0020239A, D_0020239B, D_0020239D */
u8 D_00202390[0x8];
u8 D_00202388[0x8];
u8 D_00202380[0x8]; /* also D_00202385, D_00202386, D_00202387 */
s32 D_0020237C;
u8 D_00202378[0x4];
u8 D_00202370[0x8];
f32 D_0020236C;
f32 D_00202368;
f32 D_00202364;
f32 D_00202360;
f32 D_0020235C;
s32 D_00202358;
u8 D_00202354[0x4]; /* also D_00202356 */
u8 D_00202350[0x4]; /* also D_00202352 */
u8 D_00202348[0x8];
f32 D_00202344;
s32 D_00202340;
u8 D_0020233C[0x4];
f32 D_00202338;
u8 D_00202334[0x4];
s32 D_00202330;
s32 D_0020232C;
u8 D_00202328[0x4];
s32 D_00202324;
s32 D_00202320;
s32 D_0020231C;
s32 D_00202318;
u8 D_00202314[0x4];
u8 D_00202310[0x4];
u8 D_0020230C[0x4];
s32 D_00202308;
u8 D_00202300[0x8];
s32 D_002022FC;
s32 D_002022F8;
s32 D_002022F4;
u8 D_002022F0[0x4];
s32 D_002022EC;
f32 D_002022E8;
u8 D_002022E4[0x4];
s32 D_002022E0;
f32 D_002022DC;
s32 D_002022D8;
u8 D_002022D4[0x4];
u8 D_002022D0[0x4];
u8 D_002022C0[0x10]; /* also D_002022C4 */
u8 D_002022BC[0x4];
u8 D_002022B8[0x4];
s32 D_002022B4;
u8 D_002022B0[0x4];
u8 D_002022A0[0x10]; /* also D_002022A4 */
u8 D_00202290[0x10];
s32 D_0020228C;
u8 D_00202288[0x4];
u8 D_00202284[0x4];
u8 D_00202280[0x4];
u8 D_00202278[0x8];
s32 D_00202274;
s32 D_00202270;
s32 D_0020226C;
s32 D_00202268;
f32 D_00202264;
s32 D_00202260;
s32 D_0020225C;
s32 D_00202258;
s32 D_00202254;
s32 D_00202250;
s32 D_0020224C;
s32 D_00202248;
s32 D_00202244;
s32 D_00202240;
s32 D_0020223C;
s32 D_00202238;
s32 D_00202234;
s32 D_00202230;
f32 D_0020222C;
f32 D_00202228;
s32 D_00202224;
s32 D_00202220;
u8 D_0020221C[0x4];
s32 D_00202218;
s32 D_00202214;
s32 D_00202210;
s32 D_0020220C;
s32 D_00202208;
s32 D_00202204;
s32 D_00202200;
s32 D_002021FC;
s32 D_002021F8;
s32 D_002021F4;
s32 D_002021F0;
s32 D_002021EC;
s32 D_002021E8;
s32 D_002021E4;
s32 D_002021E0;
s32 D_002021DC;
s32 D_002021D8;
u8 D_002021D0[0x8];
s32 D_002021CC;
f32 D_002021C8;
f32 D_002021C4;
s32 D_002021C0;
f32 D_002021BC;
f32 D_002021B8;
s32 D_002021B4;
s32 D_002021B0;
s32 D_002021AC;
s32 D_002021A8;
u32 D_002021A4;
f32 D_002021A0;
f32 D_0020219C;
s32 D_00202198;
s32 D_00202194;
u32 D_00202190;
s32 D_0020218C;
s32 D_00202188;
u32 D_00202184;
s8 *D_00202180;
u8 D_0020217C[0x4];
s32 *D_00202178;
u8 D_00202174[0x4];
s32 *D_00202170;
s8 *D_0020216C;
s8 *D_00202168;
u8 D_00202164[0x4];
u8 D_00202160[0x4];
u8 D_0020215C[0x4];
u8 D_00202158[0x4];
s32 D_00202154;
s32 *D_00202150;
s32 *D_0020214C;
s32 D_00202148;
s32 D_00202144;
s32 D_00202140;
f32 D_0020213C;
s32 D_00202138;
s32 D_00202134;
s32 D_00202130;
u8 D_0020212C[0x4]; /* also D_0020212F */
s32 D_00202128;
s32 D_00202120[0x2];
f32 D_0020211C;
s32 D_00202118;
f32 D_00202114;
f32 D_00202110;
f32 D_0020210C;
f32 D_00202108;
f32 D_00202104;
s32 D_00202100;
u8 D_002020F8[0x8];
u8 D_002020F0[0x8];
u8 D_002020E8[0x8];
u8 D_002020E0[0x8];
u8 D_002020DC[0x4];
f32 D_002020D8;
f32 D_002020D4;
s32 D_002020D0;
u8 D_002020CC[0x4];
u8 D_002020C8[0x4];
s32 D_002020C4;
s32 D_002020C0;
f32 D_002020BC;
f32 D_002020B8;
f32 D_002020B4;
f32 D_002020B0;
u8 D_002020AC[0x4];
u8 D_002020A8[0x4];
f32 D_002020A4;
f32 D_002020A0;
u8 D_0020209C[0x4];
u8 D_00202098[0x4];
u8 D_00202094[0x4];
u8 D_00202090[0x4];
u8 D_0020208C[0x4];
u8 D_00202088[0x4];
f32 D_00202084;
s32 D_00202080;
s32 D_0020207C;
u8 D_00202078[0x4];
u8 D_00202074[0x4];
s32 D_00202070;
s32 D_0020206C;
void *D_00202068;
s32 D_00202064;
s32 D_00202060;
f32 D_0020205C;
f32 D_00202058;
f32 D_00202054;
f32 D_00202050;
s32 D_0020204C;
u8 D_00202048[0x4];
s32 D_00202044;
u8 D_00202040[0x4];
s32 D_0020203C;
s32 D_00202038;
u8 D_00202034[0x4];
u8 D_00202030[0x4];
u32 D_0020202C;
u8 D_00202028[0x4];
u8 D_00202024[0x4];
s32 D_00202020;
u8 D_0020201C[0x4];
u8 D_00202018[0x4];
u8 D_00202010[0x8];
s32 D_0020200C;
u8 D_00202008[0x4];
s32 D_00202004;
s32 D_00202000;
s32 D_00201FFC;
s32 D_00201FF8;
s32 D_00201FF4;
s32 D_00201FF0;
s32 D_00201FEC;
u8 D_00201FE8[0x4];
s32 D_00201FE4;
u8 D_00201FE0[0x4];
u8 D_00201FDC[0x4];
u8 D_00201FD8[0x4];
u8 D_00201FD4[0x4];
u8 D_00201FD0[0x4];
u8 D_00201FC0[0x10];
u8 D_00201FB0[0x10];
u32 D_00201FAC;
u8 D_00201FA8[0x4];
u8 D_00201FA4[0x4];
u8 D_00201FA0[0x4];
s32 D_00201F9C;
s32 D_00201F98;
u8 D_00201F94[0x4];
s32 D_00201F90;
s32 D_00201F8C;
s32 D_00201F88;
s32 D_00201F84;
u8 D_00201F80[0x4];
u8 D_00201F78[0x8];
u8 D_00201F74[0x4];
u8 D_00201F70[0x4];
u8 D_00201F6C[0x4];
u8 D_00201F68[0x4];
u8 D_00201F64[0x4];
u8 D_00201F60[0x4];
u8 D_00201F5C[0x4];
u8 D_00201F58[0x4];
u32 D_00201F54;
u8 D_00201F50[0x4];
u8 D_00201F4C[0x4];
s32 D_00201F48;
u8 D_00201F44[0x4];
u8 D_00201F40[0x4];
s32 D_00201F3C;
u8 D_00201F38[0x4];
u8 D_00201F34[0x4];
u8 D_00201F30[0x4];
s32 D_00201F2C;
s32 D_00201F28;
s32 D_00201F24;
s32 D_00201F20;
u8 D_00201F1C[0x4];
u8 D_00201F18[0x4];
u8 D_00201F14[0x4];
u8 D_00201F10[0x4];
u8 D_00201F0C[0x4];
u8 D_00201F08[0x4];
u8 D_00201F04[0x4];
u32 D_00201F00;
u8 D_00201EFC[0x4];
u8 D_00201EF8[0x4];
u32 D_00201EF4;
u32 D_00201EF0;
u8 D_00201EEC[0x4];
s32 D_00201EE8;
u8 D_00201EE4[0x4];
u8 D_00201EE0[0x4]; /* also D_00201EE2 */
u8 D_00201ED8[0x8];
u8 D_00201ED4[0x4]; /* also D_00201ED5, D_00201ED6, D_00201ED7 */
u8 D_00201ED0[0x4];
u8 D_00201EC0[0x10]; /* also D_00201EC4 */
u8 D_00201EBC[0x4];
u8 D_00201EB8[0x4];
f32 D_00201EB4;
s32 D_00201EB0;
s32 D_00201EAC;
s32 D_00201EA8;
s32 D_00201EA4;
s32 D_00201EA0;
s32 D_00201E9C;
s32 D_00201E98;
u8 D_00201E94[0x4];
f32 D_00201E90;
u8 D_00201E8C[0x4];
u8 D_00201E88[0x4];
u8 D_00201E80[0x8] __attribute__((aligned(16)));
