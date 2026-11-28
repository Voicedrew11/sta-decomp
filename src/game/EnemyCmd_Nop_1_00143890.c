#include "common.h"
#include "m2c.h"
typedef struct { char pad[8]; u16 h; } Obj_EnemyCmd_GetFlag_0_001438B0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B4b6_1_00143920;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B4b5_1_00143930;
typedef struct { f32 x, y, z; s32 w; } V3;
typedef struct { s32 p0, p4; u8 type; u8 p9[7]; f32 a; s32 p14; f32 b; s32 p1C; f32 c; } Arg_EnemyCmd_GetRelativePos_0_00143960;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Get608_1_00143B20;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5A1b5_1_00143BB0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B4b4_1_00143BC0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_StartTimer_0_00143BD0;
typedef struct { char pad[8]; f32 f; } Obj_EnemyCmd_StartTimer_0_00143BD0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetMotionFrame_1_00143C30;
typedef struct { char pad[0x154]; s32 p; } S_EnemyCmd_ResolveHit_0_00143C70;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetVec660_0_00143D60;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_UpdatePartStat_1_00143DF0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_InitPart_1_00143E10;
typedef struct { Vec s; Vec e; } Seg;
typedef struct { Vec p; u8 pad[0x14]; s32 hit; u8 pad2[0x18]; } Hit;
typedef struct { u8 pad[0xC]; f32 xC; } Q;
typedef struct { Q *p; s32 pad[2]; } QP __attribute__((aligned(16)));
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_BroadcastMotion_1_001442F0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Kill_1_00144360;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_SetHiddenFlags_0_00144370;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B2b6w2_1_001443E0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B2b2_1_001443F0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B2b1_1_00144400;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B0b2_1_00144410;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_ClampHpFromFlag_1_00144420;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_StoreHpToFlag_1_00144490;
typedef struct { u8 pad0[0x34]; u16 x34; u16 x36; u8 x38; u8 x39; u8 x3A; u8 x3B; u8 pad3C[4]; } T_EnemyCmd_FindSpawnPoint_0_001444F0;
typedef struct { u8 pad0[0x5E0]; f32 x5E0[7]; u8 x5FC[7]; u8 pad603; u16 x604; } O;
typedef struct { u8 pad0[0x24]; s32 x24; u8 pad28[0x18]; } Buf;
typedef struct { u8 pad0[8]; u8 x8; u8 pad9[7]; u16 x10; u8 pad12[6]; f32 x18; u8 pad1C[4]; f32 x20; } Msg;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetPosition_2_00144970;
typedef struct { u8 pad[2]; u8 x2; } C;
typedef struct { u8 pad[8]; u16 x8; u8 padA[0xE]; f32 x18; f32 p1C; f32 x20; f32 p24; f32 x28; } Arg_EnemyCmd_SpawnEffectB_0_00144BE0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B2b0_1_00144D70;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_BroadcastFrame_1_00144D80;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B1b7_1_00144DF0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B1b6_1_00144E00;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_BreakPart_1_00144E10;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B0b0_1_00144E30;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_HealPercent_1_00144E40;
typedef struct { char pad[0x154]; void *p; } Ctx;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetParamIdx_1_00144F60;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B1b1_1_00144FA0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_UpdateParamFlags_1_00144FB0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_RegisterKill_0_00144FC0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_RegisterSeen_0_00145010;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B1b0_1_00145060;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_SetDead_1_001450D0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B0b7_1_001450E0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetType_1_00145140;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B0b1_1_00145180;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_AddHp_2_00145190;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Get5B0b0_1_001451A0;
typedef struct { char pad[0x610]; s8 x610; s8 x611; s8 x612; s8 x613; s32 x614; } P_EnemyCmd_AddPartValue_0_001451E0;
typedef struct { char pad[0x154]; P_EnemyCmd_AddPartValue_0_001451E0 *p; } S_EnemyCmd_AddPartValue_0_001451E0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetHpPercent_2_00145250;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_SetMode_1_00145290;
typedef struct { f32 a; f32 b; } P_EnemyCmd_PlaySe_1_001453A0;
typedef struct { char p[0x154]; s32 x154; } S_EnemyCmd_PlaySe_1_001453A0;
typedef struct { char p[8]; u16 x8; char p2[6]; u8 x10; } A;
typedef struct { u32 w; u32 pad; } W;
typedef struct { W x0; W x8; W x10; W x18; } Arg_EnemyCmd_SpawnItem_0_001454E0;
typedef struct { u8 b[12]; f32 v; } T_EnemyCmd_ShakeCamera_0_001455B0;
typedef struct { char pad[8]; f32 f; } Obj_EnemyCmd_ShakeCamera_0_001455B0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_ResetVectors_1_00145610;
extern void *D_00201FA8;
extern s32 D_00201E80;
extern P_EnemyCmd_PlaySe_1_001453A0 D_00201C50;
void EnemyCmd_Nop_1_00143890(void);
void EnemyCmd_Set5B5b7_1_001438A0(void);
void EnemyCmd_GetFlag_0_001438B0(Obj_EnemyCmd_GetFlag_0_001438B0 *o);
void EnemyCmd_GetGlobal_0_001438F0(s32 a);
void EnemyCmd_Set5B4b6_1_00143920(u8 *arg0);
void EnemyCmd_Set5B4b5_1_00143930(u8 *arg0);
void EnemyCmd_Set5B8_1_00143940(void *arg0);
void EnemyCmd_Set60B_1_00143950(void *arg0);
void EnemyCmd_GetRelativePos_0_00143960(Arg_EnemyCmd_GetRelativePos_0_00143960 *arg0);
void EnemyCmd_Get608_1_00143B20(s32 a);
void EnemyCmd_GetPlayerValue_0_00143B60(s32 a);
void EnemyCmd_SelectMotion_1_00143B90(void *arg0);
void EnemyCmd_Set5A1b5_1_00143BB0(u8 *arg0);
void EnemyCmd_Set5B4b4_1_00143BC0(u8 *arg0);
void EnemyCmd_StartTimer_0_00143BD0(Obj_EnemyCmd_StartTimer_0_00143BD0 *o);
void EnemyCmd_GetMotionFrame_1_00143C30(s32 a);
void EnemyCmd_ResolveHit_0_00143C70(u8 *o);
void EnemyCmd_SetPartValue_1_00143D10(void *arg0);
void EnemyCmd_GetVec660_0_00143D60(void *o);
void EnemyCmd_UpdatePartStat_1_00143DF0(u8 *arg0);
void EnemyCmd_LoadPart_1_00143E00(void *arg0);
void EnemyCmd_InitPart_1_00143E10(u8 *arg0);
void EnemyCmd_FindTargetInCone_0_00143E20(s8 *a0, s32 a1, u8 a2, s32 a3, s32 t0, s32 t1, f32 ang);
void EnemyCmd_GetTargetPos_0_001441B0(s8 *arg0);
void EnemyCmd_BroadcastMotion_1_001442F0(u8 *o);
void EnemyCmd_Kill_1_00144360(u8 *arg0);
void EnemyCmd_SetHiddenFlags_0_00144370(u8 *o);
void EnemyCmd_ReturnToTitle_1_001443D0(void);
void EnemyCmd_Set5B2b6w2_1_001443E0(u8 *arg0);
void EnemyCmd_Set5B2b2_1_001443F0(u8 *arg0);
void EnemyCmd_Set5B2b1_1_00144400(u8 *arg0);
void EnemyCmd_Set5B0b2_1_00144410(u8 *arg0);
void EnemyCmd_ClampHpFromFlag_1_00144420(u8 *o);
void EnemyCmd_StoreHpToFlag_1_00144490(u8 *o);
void EnemyCmd_Set5B1b4_1_001444E0(void);
void EnemyCmd_FindSpawnPoint_0_001444F0(Msg *m);
void EnemyCmd_Set5B2b4_1_00144960(void);
void EnemyCmd_GetPosition_2_00144970(void *o);
void EnemyCmd_SpawnEffect_0_00144A00(s8 *a0);
void EnemyCmd_StopEffect_0_00144B80(u16 *a0);
void EnemyCmd_SpawnEffectB_0_00144BE0(Arg_EnemyCmd_SpawnEffectB_0_00144BE0 *a0);
void EnemyCmd_ResetState_1_00144D50(void);
void EnemyCmd_Set5B3b3_1_00144D60(void);
void EnemyCmd_Set5B2b0_1_00144D70(u8 *arg0);
void EnemyCmd_BroadcastFrame_1_00144D80(u8 *o);
void EnemyCmd_Set5B1b7_1_00144DF0(u8 *arg0);
void EnemyCmd_Set5B1b6_1_00144E00(u8 *arg0);
void EnemyCmd_BreakPart_1_00144E10(u8 *arg0);
void EnemyCmd_Set5B0b0_1_00144E30(u8 *arg0);
void EnemyCmd_HealPercent_1_00144E40(u8 *o);
void EnemyCmd_Set5B1b5_1_00144EE0(void);
void EnemyCmd_Set5B1b3_1_00144EF0(void);
void EnemyCmd_Set5B1b2Notify_0_00144F00(unsigned char *a);
void EnemyCmd_GetParamIdx_1_00144F60(s32 a);
void EnemyCmd_Set5B1b1_1_00144FA0(u8 *arg0);
void EnemyCmd_UpdateParamFlags_1_00144FB0(u8 *arg0);
void EnemyCmd_RegisterKill_0_00144FC0(void);
void EnemyCmd_RegisterSeen_0_00145010(void);
void EnemyCmd_Set5B1b0_1_00145060(u8 *arg0);
void EnemyCmd_SetGameFlag_2_00145070(u8 *arg0);
void EnemyCmd_TestGameFlag_2_00145080(u8 *o);
void EnemyCmd_SetDead_1_001450D0(u8 *arg0);
void EnemyCmd_Set5B0b7_1_001450E0(u8 *arg0);
void EnemyCmd_KillNow_1_001450F0(void);
void EnemyCmd_Random_2_00145100(u8 *a);
void EnemyCmd_GetType_1_00145140(s32 a);
void EnemyCmd_Set5B0b1_1_00145180(u8 *arg0);
void EnemyCmd_AddHp_2_00145190(u8 *arg0);
void EnemyCmd_Get5B0b0_1_001451A0(s32 a);
void EnemyCmd_AddPartValue_0_001451E0(u8 *arg0);
void EnemyCmd_GetHpPercent_2_00145250(s32 a);
void EnemyCmd_SetMode_1_00145290(u8 *arg0);
void EnemyCmd_SelectMotionB_1_001452A0(void *arg0);
void EnemyCmd_Set609_1_001452C0(void *arg0);
void EnemyCmd_SetMapObjFlag_0_001452E0(u8 *o);
void EnemyCmd_PlaySe_1_001453A0(A *a);
void EnemyCmd_GetModelPos_0_00145410(s32 a0);
void EnemyCmd_SpawnItem_0_001454E0(Arg_EnemyCmd_SpawnItem_0_001454E0 *a);
void EnemyCmd_ShakeCamera_0_001455B0(Obj_EnemyCmd_ShakeCamera_0_001455B0 *o);
void EnemyCmd_ResetVectors_1_00145610(u8 *arg0);
s8* Script_GetArgPtr_2_00165130(Obj_EnemyCmd_GetFlag_0_001438B0 *o, s32 b);
s8 Save_TestItemBit_1_001A9B40(s16 v);
s8 Save_GetByte2E_0_001AA740(void);
void Enemy_Set5B4b6_1_0013E490(void *arg0, u8 arg1);
void Enemy_Set5B4b5_1_0013E4B0(void *arg0, u8 arg1);
void Enemy_Set5B8_1_0013E480(s32, f32);
void Enemy_Set60B_1_0013E250(s32, u8);
Vec* Enemy_Ptr700_1_0013FF90(s8 *);
Vec* Enemy_Ptr6E0_1_0013FFB0(s8 *);
Vec* Enemy_PtrVec660_1_00140340(s8 *);
Vec* Enemy_GetPositionPtr_2_00140460(s8 *);
void sceVu0CopyVector(void *, void *);
void sceVu0AddVector(Vec *, Vec *, void *);
void Enemy_GetForwardVector_2_001403D0(s8 *, Vec *, s8 *);
void Enemy_GetRightVector_1_00140360(void *, Vec*);
s8 Enemy_Get608_1_0013E290(void *p);
s8 Player_GetFlag521b5_1_00145620(void);
void Enemy_Set5A1b5_1_0013EE90(void *arg0, u8 arg1);
void Enemy_Set5B4b4_1_0013E5F0(void *arg0, u8 arg1);
void Enemy_Set5B4b3_1_0013E620(void *p, s32 v);
void Enemy_Set5C8_1_0013E450(void *p, f32 f);
void Enemy_Set5C0_1_0013E470(void *p, f32 f);
s8 Enemy_GetMotionFrame_0_0013ECA0(void *p);
void Combat_ResolveHit_1_00135E30(s32 a, u8 mode, void *p, void *q, void *r, void *s);
void Enemy_CopyVec660_1_00140350(void *p, f32 *v);
void Enemy_UpdatePartStat_0_0013F0C0(void *arg0, u8 arg1);
void Enemy_LoadPartWrap_0_0013F0B0(s32, u8);
void Enemy_InitPart_1_0013F1B0(void *arg0, u8 arg1);
s32 Enemy_GetTargetHandle_0_0013EDE0(s8 *);
s8* ActorList_Next_2_001A5460(s32 *);
s32 Ent_IsNull0_1_0013EE30(s8 *);
s32 Enemy_GetMotionId_0_0013ED20(void *);
void Enemy_CopyPosition_2_00140470(void *, void *);
Vec* Enemy_GetRotationPtr_1_00140430(s8 *);
void memset(void *, s32, s32);
void Enemy_RaycastMapC_0_0013D430(s32, Hit *, Seg *, s32, s32);
void sceVu0SubVector(Vec *, void *, void *);
void sceVu0ScaleVector(f32, Vec *, Vec *);
s32 Enemy_Get81_1_0013FC00(s8 *);
void Enemy_GetCollider_0_0013FB90(s8 *, u8, QP *, QP *);
void EnemyScr_BroadcastMotionEvent_0_00140F90(u8 x, u8 a, u8 y, u8 b);
void Enemy_Kill_1_0013EF80(void *arg0, u8 arg1);
void Enemy_Set5B3b6_1_0013E710(void *p, s32 v);
void Enemy_Set5B6b1_1_0013E6F0(void *p, s32 v);
void Enemy_Set5B2b6w2_1_0013E730(void *arg0, u8 arg1);
void Enemy_Set5B2b2_1_0013E840(void *arg0, u8 arg1);
void Enemy_Set5B2b1_1_0013E860(void *arg0, u8 arg1);
void Enemy_Set5B0b2_1_0013EBF0(void *arg0, u8 arg1);
u16 GameFlag_GetHalf_0_0013D560(u8, u8);
u16 Enemy_GetHp_2_0013F750(void *p);
void Enemy_AddHp_2_0013F710(void *, s32);
void GameFlag_GetWordWrap_0_0013D540(u8 a, u8 b, u16 c);
T_EnemyCmd_FindSpawnPoint_0_001444F0* Enemy_GetParamPtr10_1_0013E070(O *);
u32 Enemy_Get5B0b7_1_0013EB60(O *);
u32 Enemy_Get5B1b5_1_0013E940(O *);
s32 Ent_GetTypeByte_1_0013E220(O *);
u32 Enemy_Get5B6b4_1_0013EAA0(O *);
Vec* Player_GetBody_1_00145770(void);
s32 Rand_Range_3_0013D500(s32);
f32 cosf(f32);
void Enemy_RaycastMapB_0_0013D320(s32, Buf *, Vec *, s32, s32);
s8 Player_ThrowItem_0_001CA960(void);
s8 Player_HoldItem_0_001CAB20(s16, u8, Vec *, Vec *);
void Enemy_CopyRotation_2_00140440(void *, Vec*);
C* Inventory_GetEntry_1_001CC3F0(s16);
s32 Player_DropItem_0_001CAC30(void);
s32 Player_PlaceItem_0_001CADF0(s16, Vec *, Vec *, s32);
void Enemy_Set5B2b0_1_0013E890(void *arg0, u8 arg1);
void EnemyScr_BroadcastFrameEvent_0_001410C0(u8 x, u8 a, u8 y, u8 b);
void Enemy_Set5B1b7_1_0013E8C0(void *arg0, u8 arg1);
void Enemy_Set5B1b6_1_0013E8F0(void *arg0, u8 arg1);
void Enemy_BreakPart_0_0013F210(void *arg0, u8 arg1, s32 arg2);
void Enemy_Set5B0b0_1_0013EC30(void *arg0, u8 arg1);
u16 Enemy_GetMaxHp_2_0013F700(void *);
s32 Enemy_Get5B1b2_1_0013EA40(void *);
void Msg_Close_1_0018B0C0(void);
void Enemy_Set5B1b2_1_0013EA20(void *, int);
s16 Enemy_GetCurrentParamIdx_0_0013E110(void *p);
void Enemy_Set5B1b1_1_0013EA50(void *arg0, u8 arg1);
void Enemy_UpdateParamFlags_0_0013F760(void *arg0, u8 arg1);
void Bestiary_IsSeen_2_001A9EC0(s16 i);
void Bestiary_SetSeen_1_001A9F10(s16 i);
void Bestiary_SetKilled_1_001A9FA0(s16 i);
void Bestiary_IsKilled_1_001A9F60(s16 i);
void Enemy_Set5B1b0_1_0013EB10(void *arg0, u8 arg1);
void GameFlag_SetBit_2_0013D5C0(u8 arg0, u8 arg1);
s8 GameFlag_TestBit_2_0013D630(u8 a, u8 b);
void Enemy_SetDeadFlag_0_0013EEB0(void *arg0, u8 arg1);
void Enemy_Set5B0b7_1_0013EB40(void *arg0, u8 arg1);
void Enemy_Set5B0b1_1_0013EC10(void *arg0, u8 arg1);
s8 Enemy_Get5B0m1_1_0013EC50(void *p);
s8 Enemy_GetHpPercent_2_0013F620(void *p);
void Enemy_SetMode_0_0013EBA0(void *arg0, u8 arg1);
s16* PlayerData_Get_2_001C9BA0(void);
void Player_PlayLevelUpSe_0_001C9FB0(s32);
void Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
s32 Snd_PlaySeAt_2_001315A0(s32 a, s32 b, f32 *v);
f32* Enemy_Ptr6F0_1_0013FFA0(s32, S_EnemyCmd_PlaySe_1_001453A0 *);
void SndCh_GetPosition_1_00131180(s32, P_EnemyCmd_PlaySe_1_001453A0 *);
Vec* Enemy_GetModelData_1_0013DCE0(s32);
void* MapObj_FindById_0_00179DB0(u16, u16);
u8 Msg_ShowWrap_1_0018AC90(void *, s32);
void Camera_SetShake_0_00189F00(T_EnemyCmd_ShakeCamera_0_001455B0 *t);
void Enemy_ResetVectors_0_0013D1F0(void *arg0, u8 arg1);

/* EnemyCmd_Nop_1_00143890 */
void EnemyCmd_Nop_1_00143890(void) {

}

/* EnemyCmd_Set5B5b7_1_001438A0 */
void EnemyCmd_Set5B5b7_1_001438A0(void) {
    Enemy_Set5B5b7_1_0013E950(M2C_FIELD(D_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_GetFlag_0_001438B0 */
void EnemyCmd_GetFlag_0_001438B0(Obj_EnemyCmd_GetFlag_0_001438B0 *o)
{
    u16 v = o->h;
    s8 *q = Script_GetArgPtr_2_00165130(o, 1);
    *q = Save_TestItemBit_1_001A9B40(v);
}

/* EnemyCmd_GetGlobal_0_001438F0 */
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetGlobal_0_001438F0
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetGlobal_0_001438F0(s32 a, s32 b);

void EnemyCmd_GetGlobal_0_001438F0(s32 a)
{
    s8 *p = Script_GetArgPtr_2_00165130(a, 0);
    *p = Save_GetByte2E_0_001AA740();
}
#undef Script_GetArgPtr_2_00165130

/* EnemyCmd_Set5B4b6_1_00143920 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B4b6_1_00143920
extern S_EnemyCmd_Set5B4b6_1_00143920 *D_00201FA8__as_EnemyCmd_Set5B4b6_1_00143920;
void EnemyCmd_Set5B4b6_1_00143920(u8 *arg0) { Enemy_Set5B4b6_1_0013E490(D_00201FA8->p, arg0[8]); }
#undef D_00201FA8

/* EnemyCmd_Set5B4b5_1_00143930 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B4b5_1_00143930
extern S_EnemyCmd_Set5B4b5_1_00143930 *D_00201FA8__as_EnemyCmd_Set5B4b5_1_00143930;

void EnemyCmd_Set5B4b5_1_00143930(u8 *arg0)
{
    Enemy_Set5B4b5_1_0013E4B0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_Set5B8_1_00143940 */
void EnemyCmd_Set5B8_1_00143940(void *arg0) {
    Enemy_Set5B8_1_0013E480(M2C_FIELD(D_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, f32 *, 8));
}

/* EnemyCmd_Set60B_1_00143950 */
void EnemyCmd_Set60B_1_00143950(void *arg0) {
    Enemy_Set60B_1_0013E250(M2C_FIELD(D_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, u8 *, 8));
}

/* EnemyCmd_GetRelativePos_0_00143960 */
#define sceVu0CopyVector sceVu0CopyVector__as_EnemyCmd_GetRelativePos_0_00143960
void sceVu0CopyVector__as_EnemyCmd_GetRelativePos_0_00143960(Vec *, Vec *);
#define Enemy_GetRightVector_1_00140360 Enemy_GetRightVector_1_00140360__as_EnemyCmd_GetRelativePos_0_00143960
void Enemy_GetRightVector_1_00140360__as_EnemyCmd_GetRelativePos_0_00143960(s8 *, Vec *);
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetRelativePos_0_00143960
extern s8 *D_00201FA8__as_EnemyCmd_GetRelativePos_0_00143960;

void EnemyCmd_GetRelativePos_0_00143960(Arg_EnemyCmd_GetRelativePos_0_00143960 *arg0) {
    V3 d;
    Vec t;
    s8 *o;
    s8 *g;
    u8 type;

    g = D_00201FA8;
    type = arg0->type;
    o = *(s8 **)(g + 0x154);
    d.x = arg0->a;
    d.y = arg0->b;
    d.z = arg0->c;
    d.w = 0;
    switch (type) {
    case 0:
        sceVu0CopyVector(Enemy_Ptr700_1_0013FF90(o), Enemy_Ptr6E0_1_0013FFB0(o));
        break;
    case 1:
        sceVu0AddVector(Enemy_Ptr700_1_0013FF90(o), Enemy_PtrVec660_1_00140340(o), &d);
        break;
    case 2: {
        Vec v = {0};
        Enemy_GetForwardVector_2_001403D0(o, &t, g);
        v.x += t.x * d.x;
        v.z += t.z * d.x;
        v.y += d.y;
        Enemy_GetRightVector_1_00140360(o, &t);
        v.x += t.x * d.z;
        v.z += t.z * d.z;
        sceVu0AddVector(Enemy_Ptr700_1_0013FF90(o), Enemy_GetPositionPtr_2_00140460(o), &v);
        break;
    }
    }
}
#undef sceVu0CopyVector
#undef Enemy_GetRightVector_1_00140360
#undef D_00201FA8

/* EnemyCmd_Get608_1_00143B20 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Get608_1_00143B20
extern S_EnemyCmd_Get608_1_00143B20 *D_00201FA8__as_EnemyCmd_Get608_1_00143B20;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_Get608_1_00143B20
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_Get608_1_00143B20(s32 a, s32 b);

void EnemyCmd_Get608_1_00143B20(s32 a)
{
    void *p = D_00201FA8->p;
    s8 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Enemy_Get608_1_0013E290(p);
}
#undef Script_GetArgPtr_2_00165130
#undef D_00201FA8

/* EnemyCmd_GetPlayerValue_0_00143B60 */
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPlayerValue_0_00143B60
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPlayerValue_0_00143B60(s32 a, s32 b);

void EnemyCmd_GetPlayerValue_0_00143B60(s32 a)
{
    s8 *p = Script_GetArgPtr_2_00165130(a, 0);
    *p = Player_GetFlag521b5_1_00145620();
}
#undef Script_GetArgPtr_2_00165130

/* EnemyCmd_SelectMotion_1_00143B90 */
void EnemyCmd_SelectMotion_1_00143B90(void *arg0) {
    Enemy_SelectMotion_0_0013C420(M2C_FIELD(D_00201FA8, void **, 0x154), (s32) M2C_FIELD(arg0, u8 *, 8), (s64) M2C_FIELD(arg0, s16 *, 0x10), 2);
}

/* EnemyCmd_Set5A1b5_1_00143BB0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5A1b5_1_00143BB0
extern S_EnemyCmd_Set5A1b5_1_00143BB0 *D_00201FA8__as_EnemyCmd_Set5A1b5_1_00143BB0;

void EnemyCmd_Set5A1b5_1_00143BB0(u8 *arg0)
{
    Enemy_Set5A1b5_1_0013EE90(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_Set5B4b4_1_00143BC0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B4b4_1_00143BC0
extern S_EnemyCmd_Set5B4b4_1_00143BC0 *D_00201FA8__as_EnemyCmd_Set5B4b4_1_00143BC0;

void EnemyCmd_Set5B4b4_1_00143BC0(u8 *arg0)
{
    Enemy_Set5B4b4_1_0013E5F0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_StartTimer_0_00143BD0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_StartTimer_0_00143BD0
extern S_EnemyCmd_StartTimer_0_00143BD0 *D_00201FA8__as_EnemyCmd_StartTimer_0_00143BD0;

void EnemyCmd_StartTimer_0_00143BD0(Obj_EnemyCmd_StartTimer_0_00143BD0 *o)
{
    f32 f = o->f;
    void *p = D_00201FA8->p;
    Enemy_Set5B4b3_1_0013E620(p, 1);
    Enemy_Set5C8_1_0013E450(p, f);
    Enemy_Set5C0_1_0013E470(p, 0.0f);
}
#undef D_00201FA8

/* EnemyCmd_GetMotionFrame_1_00143C30 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetMotionFrame_1_00143C30
extern S_EnemyCmd_GetMotionFrame_1_00143C30 *D_00201FA8__as_EnemyCmd_GetMotionFrame_1_00143C30;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetMotionFrame_1_00143C30
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetMotionFrame_1_00143C30(s32 a, s32 b);

void EnemyCmd_GetMotionFrame_1_00143C30(s32 a)
{
    void *p = D_00201FA8->p;
    s8 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Enemy_GetMotionFrame_0_0013ECA0(p);
}
#undef Script_GetArgPtr_2_00165130
#undef D_00201FA8

/* EnemyCmd_ResolveHit_0_00143C70 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_ResolveHit_0_00143C70
extern S_EnemyCmd_ResolveHit_0_00143C70 *D_00201FA8__as_EnemyCmd_ResolveHit_0_00143C70;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_ResolveHit_0_00143C70
void *Script_GetArgPtr_2_00165130__as_EnemyCmd_ResolveHit_0_00143C70(u8 *o, s32 b);

void EnemyCmd_ResolveHit_0_00143C70(u8 *o)
{
    s32 h = D_00201FA8->p;
    u8 m = o[8];
    void *p = Script_GetArgPtr_2_00165130(o, 1);
    void *q = Script_GetArgPtr_2_00165130(o, 2);
    void *r = Script_GetArgPtr_2_00165130(o, 3);
    Combat_ResolveHit_1_00135E30(h, m, p, q, r, Script_GetArgPtr_2_00165130(o, 4));
}
#undef Script_GetArgPtr_2_00165130
#undef D_00201FA8

/* EnemyCmd_SetPartValue_1_00143D10 */
void EnemyCmd_SetPartValue_1_00143D10(void *arg0) {
    Enemy_SetPartValue_1_0013E3F0(M2C_FIELD(D_00201FA8, s32 *, 0x154), (s32) M2C_FIELD(arg0, u8 *, 8), (M2C_FIELD(arg0, u8 *, 0x10) | ((M2C_FIELD(arg0, u8 *, 0x18) * 8) | ((M2C_FIELD(arg0, u8 *, 0x20) << 6) | ((M2C_FIELD(arg0, u8 *, 0x30) << 0xA) | (M2C_FIELD(arg0, u8 *, 0x28) << 9))))) & 0xFFFF);
}

/* EnemyCmd_GetVec660_0_00143D60 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetVec660_0_00143D60
extern S_EnemyCmd_GetVec660_0_00143D60 *D_00201FA8__as_EnemyCmd_GetVec660_0_00143D60;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetVec660_0_00143D60
f32 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetVec660_0_00143D60(void *o, s32 b);

void EnemyCmd_GetVec660_0_00143D60(void *o)
{
    void *q = D_00201FA8->p;
    f32 *x = Script_GetArgPtr_2_00165130(o, 0);
    f32 *y = Script_GetArgPtr_2_00165130(o, 1);
    f32 *z = Script_GetArgPtr_2_00165130(o, 2);
    f32 v[4];
    Enemy_CopyVec660_1_00140350(q, v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}
#undef Script_GetArgPtr_2_00165130
#undef D_00201FA8

/* EnemyCmd_UpdatePartStat_1_00143DF0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_UpdatePartStat_1_00143DF0
extern S_EnemyCmd_UpdatePartStat_1_00143DF0 *D_00201FA8__as_EnemyCmd_UpdatePartStat_1_00143DF0;

void EnemyCmd_UpdatePartStat_1_00143DF0(u8 *arg0)
{
    Enemy_UpdatePartStat_0_0013F0C0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_LoadPart_1_00143E00 */
void EnemyCmd_LoadPart_1_00143E00(void *arg0) {
    Enemy_LoadPartWrap_0_0013F0B0(M2C_FIELD(D_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, u8 *, 8));
}

/* EnemyCmd_InitPart_1_00143E10 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_InitPart_1_00143E10
extern S_EnemyCmd_InitPart_1_00143E10 *D_00201FA8__as_EnemyCmd_InitPart_1_00143E10;

void EnemyCmd_InitPart_1_00143E10(u8 *arg0)
{
    Enemy_InitPart_1_0013F1B0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_FindTargetInCone_0_00143E20 */
#define Enemy_GetMotionId_0_0013ED20 Enemy_GetMotionId_0_0013ED20__as_EnemyCmd_FindTargetInCone_0_00143E20
s32 Enemy_GetMotionId_0_0013ED20__as_EnemyCmd_FindTargetInCone_0_00143E20(s8 *);
#define Enemy_CopyPosition_2_00140470 Enemy_CopyPosition_2_00140470__as_EnemyCmd_FindTargetInCone_0_00143E20
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_FindTargetInCone_0_00143E20(s8 *, Vec *);
#define Enemy_GetForwardVector_2_001403D0 Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_FindTargetInCone_0_00143E20
void Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_FindTargetInCone_0_00143E20(s8 *, Vec *);
#define sceVu0CopyVector sceVu0CopyVector__as_EnemyCmd_FindTargetInCone_0_00143E20
void sceVu0CopyVector__as_EnemyCmd_FindTargetInCone_0_00143E20(Vec *, Vec *);
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void EnemyCmd_FindTargetInCone_0_00143E20(s8 *a0, s32 a1, u8 a2, s32 a3, s32 t0, s32 t1, f32 ang) {
    u8 k;
    s8 *cur;
    s32 it;
    Vec m;
    Vec p;
    Hit r;
    Seg b;
    QP q1;
    QP q2;
    f32 t;
    u8 n;
    u8 i;
    f32 fz;
    f32 fx;

    k = Enemy_GetTargetHandle_0_0013EDE0(a0);
    it = 0;
    cur = ActorList_Next_2_001A5460(&it);
    if (cur != NULL) {
        do {
            if (Ent_IsNull0_1_0013EE30(cur) == 0 && Enemy_GetTargetHandle_0_0013EDE0(cur) == k && (u8)Enemy_GetMotionId_0_0013ED20(cur) == a2) {
                Enemy_CopyPosition_2_00140470(a0, &p);
                Enemy_GetForwardVector_2_001403D0(a0, &m);
                p.x += m.x * t1;
                p.z += m.z * t1;
                p.x -= m.z * a3;
                p.z += m.x * a3;
                p.y -= t0;
                sceVu0CopyVector(&b.s, Enemy_GetPositionPtr_2_00140460(a0));
                b.s.y -= 100.0f;
                b.s.w = 1.0f;
                sceVu0CopyVector(&b.e, &p);
                b.e.w = 1.0f;
                memset(&r, 0, 0x40);
                if (((s32 **)&D_00201E80)[2] != NULL) {
                    Enemy_RaycastMapC_0_0013D430(*((s32 **)&D_00201E80)[2], &r, &b, 6, 3);
                }
                if (r.hit == 0 && ((s32 **)&D_00201E80)[3] != NULL) {
                    Enemy_RaycastMapC_0_0013D430(*((s32 **)&D_00201E80)[3], &r, &b, 6, 3);
                }
                if (r.hit != 0) {
                    sceVu0SubVector(&p, &r, &b);
                    sceVu0ScaleVector(0.9f, &p, &p);
                    sceVu0AddVector(&p, &p, &b);
                }
                n = Enemy_Get81_1_0013FC00(cur);
                for (i = 0; i < n; i++) {
                    q1.p = NULL;
                    q2.p = NULL;
                    Enemy_GetCollider_0_0013FB90(cur, i, &q1, &q2);
                    if (q1.p != NULL) q1.p->xC = -100.0f;
                    if (q2.p != NULL) q2.p->xC = -100.0f;
                }
                sceVu0CopyVector(Enemy_GetPositionPtr_2_00140460(cur), &p);
                sceVu0CopyVector((Vec *)(*(s8 **)(cur + 0x518) + 0x1C0), &p);
                t = ang + Enemy_GetRotationPtr_1_00140430(a0)->y;
                Enemy_GetRotationPtr_1_00140430(cur)->y = WRAP(t);
                return;
            }
            cur = ActorList_Next_2_001A5460(&it);
        } while (cur != NULL);
    }
}
#undef Enemy_GetMotionId_0_0013ED20
#undef Enemy_CopyPosition_2_00140470
#undef Enemy_GetForwardVector_2_001403D0
#undef sceVu0CopyVector

/* EnemyCmd_GetTargetPos_0_001441B0 */
#define sceVu0CopyVector sceVu0CopyVector__as_EnemyCmd_GetTargetPos_0_001441B0
void sceVu0CopyVector__as_EnemyCmd_GetTargetPos_0_001441B0(s8 *, s8 *);
#define EnemyCmd_FindTargetInCone_0_00143E20 EnemyCmd_FindTargetInCone_0_00143E20__as_EnemyCmd_GetTargetPos_0_001441B0
void EnemyCmd_FindTargetInCone_0_00143E20__as_EnemyCmd_GetTargetPos_0_001441B0(s8 *, s32, s32, s32, s32, s32, f32);
#define Enemy_GetPositionPtr_2_00140460 Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_GetTargetPos_0_001441B0
s8 *Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_GetTargetPos_0_001441B0(s8 *);
#define Enemy_PtrVec660_1_00140340 Enemy_PtrVec660_1_00140340__as_EnemyCmd_GetTargetPos_0_001441B0
s8 *Enemy_PtrVec660_1_00140340__as_EnemyCmd_GetTargetPos_0_001441B0(s8 *);
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetTargetPos_0_001441B0
extern s8 *D_00201FA8__as_EnemyCmd_GetTargetPos_0_001441B0;

void EnemyCmd_GetTargetPos_0_001441B0(s8 *arg0) {
    s32 type;
    s32 b;
    s32 x, y, z;
    s8 *obj;
    s8 *p;
    f32 f;

    type = M2C_FIELD(arg0, u8 *, 8);
    b = M2C_FIELD(arg0, u8 *, 0x10);
    x = M2C_FIELD(arg0, s16 *, 0x18);
    y = M2C_FIELD(arg0, s16 *, 0x20);
    z = M2C_FIELD(arg0, s16 *, 0x28);
    obj = M2C_FIELD(D_00201FA8, s8 **, 0x154);
    f = M2C_FIELD(arg0, f32 *, 0x30);
    if (type == 0) {
        EnemyCmd_FindTargetInCone_0_00143E20(obj, type, b, x, y, z, f);
    } else if (type == 1) {
        p = Enemy_GetPositionPtr_2_00140460(obj);
        M2C_FIELD(p, f32 *, 0) += x;
        M2C_FIELD(p, f32 *, 4) += y;
        M2C_FIELD(p, f32 *, 8) += z;
        sceVu0CopyVector(M2C_FIELD(obj, s8 **, 0x518) + 0x1C0, p);
    } else if (type == 2) {
        p = Enemy_PtrVec660_1_00140340(obj);
        M2C_FIELD(p, f32 *, 0) += x;
        M2C_FIELD(p, f32 *, 4) += y;
        M2C_FIELD(p, f32 *, 8) += z;
    }
}
#undef sceVu0CopyVector
#undef EnemyCmd_FindTargetInCone_0_00143E20
#undef Enemy_GetPositionPtr_2_00140460
#undef Enemy_PtrVec660_1_00140340
#undef D_00201FA8

/* EnemyCmd_BroadcastMotion_1_001442F0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_BroadcastMotion_1_001442F0
extern S_EnemyCmd_BroadcastMotion_1_001442F0 *D_00201FA8__as_EnemyCmd_BroadcastMotion_1_001442F0;
#define Enemy_GetTargetHandle_0_0013EDE0 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_BroadcastMotion_1_001442F0
u8 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_BroadcastMotion_1_001442F0(void *p);

void EnemyCmd_BroadcastMotion_1_001442F0(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    void *p = D_00201FA8->p;
    u8 x = Enemy_GetTargetHandle_0_0013EDE0(p);
    EnemyScr_BroadcastMotionEvent_0_00140F90(x, a, (u8)Enemy_GetMotionId_0_0013ED20(p), b);
}
#undef Enemy_GetTargetHandle_0_0013EDE0
#undef D_00201FA8

/* EnemyCmd_Kill_1_00144360 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Kill_1_00144360
extern S_EnemyCmd_Kill_1_00144360 *D_00201FA8__as_EnemyCmd_Kill_1_00144360;

void EnemyCmd_Kill_1_00144360(u8 *arg0)
{
    Enemy_Kill_1_0013EF80(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_SetHiddenFlags_0_00144370 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_SetHiddenFlags_0_00144370
extern S_EnemyCmd_SetHiddenFlags_0_00144370 *D_00201FA8__as_EnemyCmd_SetHiddenFlags_0_00144370;

void EnemyCmd_SetHiddenFlags_0_00144370(u8 *o)
{
    void *p = D_00201FA8->p;
    u8 a = o[8];
    u8 b = o[0x10];
    if (a)
        Enemy_Set5B3b6_1_0013E710(p, 1);
    if (b)
        Enemy_Set5B6b1_1_0013E6F0(p, 1);
}
#undef D_00201FA8

/* EnemyCmd_ReturnToTitle_1_001443D0 */
void EnemyCmd_ReturnToTitle_1_001443D0(void) {
    Game_RequestTitle_0_0012C040();
}

/* EnemyCmd_Set5B2b6w2_1_001443E0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B2b6w2_1_001443E0
extern S_EnemyCmd_Set5B2b6w2_1_001443E0 *D_00201FA8__as_EnemyCmd_Set5B2b6w2_1_001443E0;

void EnemyCmd_Set5B2b6w2_1_001443E0(u8 *arg0)
{
    Enemy_Set5B2b6w2_1_0013E730(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_Set5B2b2_1_001443F0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B2b2_1_001443F0
extern S_EnemyCmd_Set5B2b2_1_001443F0 *D_00201FA8__as_EnemyCmd_Set5B2b2_1_001443F0;

void EnemyCmd_Set5B2b2_1_001443F0(u8 *arg0)
{
    Enemy_Set5B2b2_1_0013E840(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_Set5B2b1_1_00144400 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B2b1_1_00144400
extern S_EnemyCmd_Set5B2b1_1_00144400 *D_00201FA8__as_EnemyCmd_Set5B2b1_1_00144400;

void EnemyCmd_Set5B2b1_1_00144400(u8 *arg0)
{
    Enemy_Set5B2b1_1_0013E860(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_Set5B0b2_1_00144410 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B0b2_1_00144410
extern S_EnemyCmd_Set5B0b2_1_00144410 *D_00201FA8__as_EnemyCmd_Set5B0b2_1_00144410;

void EnemyCmd_Set5B0b2_1_00144410(u8 *arg0)
{
    Enemy_Set5B0b2_1_0013EBF0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_ClampHpFromFlag_1_00144420 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_ClampHpFromFlag_1_00144420
extern S_EnemyCmd_ClampHpFromFlag_1_00144420 *D_00201FA8__as_EnemyCmd_ClampHpFromFlag_1_00144420;
void EnemyCmd_ClampHpFromFlag_1_00144420(u8 *o) {
    void *p = D_00201FA8->p;
    u16 a = GameFlag_GetHalf_0_0013D560(o[8], o[0x10]);
    u16 b = Enemy_GetHp_2_0013F750(p);
    if (a < b && a > 0) {
        Enemy_AddHp_2_0013F710(p, a - b);
    }
}
#undef D_00201FA8

/* EnemyCmd_StoreHpToFlag_1_00144490 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_StoreHpToFlag_1_00144490
extern S_EnemyCmd_StoreHpToFlag_1_00144490 *D_00201FA8__as_EnemyCmd_StoreHpToFlag_1_00144490;
#define Enemy_GetHp_2_0013F750 Enemy_GetHp_2_0013F750__as_EnemyCmd_StoreHpToFlag_1_00144490
s32 Enemy_GetHp_2_0013F750__as_EnemyCmd_StoreHpToFlag_1_00144490(void *p);

void EnemyCmd_StoreHpToFlag_1_00144490(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    GameFlag_GetWordWrap_0_0013D540(a, b, Enemy_GetHp_2_0013F750(D_00201FA8->p));
}
#undef Enemy_GetHp_2_0013F750
#undef D_00201FA8

/* EnemyCmd_Set5B1b4_1_001444E0 */
void EnemyCmd_Set5B1b4_1_001444E0(void) {
    Enemy_Set5B1b4IfUnlocked_0_0013E980(M2C_FIELD(D_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_FindSpawnPoint_0_001444F0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_FindSpawnPoint_0_001444F0
extern s8 *D_00201FA8__as_EnemyCmd_FindSpawnPoint_0_001444F0;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_FindSpawnPoint_0_001444F0
u8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_FindSpawnPoint_0_001444F0(Msg *, s32);
#define Enemy_GetPositionPtr_2_00140460 Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_FindSpawnPoint_0_001444F0
Vec *Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_FindSpawnPoint_0_001444F0(O *);
#define sceVu0CopyVector sceVu0CopyVector__as_EnemyCmd_FindSpawnPoint_0_001444F0
void sceVu0CopyVector__as_EnemyCmd_FindSpawnPoint_0_001444F0(Vec *, Vec *);

void EnemyCmd_FindSpawnPoint_0_001444F0(Msg *m) {
    u8 list[8];
    Buf buf;
    Vec B;
    Vec A;
    f32 f20;
    u8 mask;
    f32 f21;
    u16 id;
    O *o;
    u8 *res;
    T_EnemyCmd_FindSpawnPoint_0_001444F0 *e;
    u16 best;
    u8 n;
    u8 i;
    u8 ok;
    u8 r;
    u8 *p;
    u8 flag;

    f20 = m->x18;
    mask = m->x8;
    f21 = m->x20;
    id = m->x10;
    o = *(O **)(D_00201FA8 + 0x154);
    res = Script_GetArgPtr_2_00165130(m, 4);
    e = Enemy_GetParamPtr10_1_0013E070(o);
    best = 0xFFFF;
    n = 0;
    *res = 0xFF;
    o->x5FC[0] = 0;
    o->x5FC[1] = 0;
    o->x5FC[2] = 0;
    o->x5FC[3] = 0;
    o->x5FC[4] = 0;
    o->x5FC[5] = 0;
    o->x5FC[6] = 0;
    o->x604 = id;
    if (mask == 0) return;
    for (i = 0; i < 7; i++) {
        if (mask & (1 << i)) {
            o->x5FC[i] |= 1;
            if (!(o->x5E0[i] <= f21)) {
                o->x5E0[i] -= f21;
            } else {
                o->x5E0[i] = 0.0f;
            }
        }
    }
    if (Enemy_Get5B0b7_1_0013EB60(o) != 0) return;
    if (Enemy_Get5B1b5_1_0013E940(o) != 0) return;
    for (i = 0; i < 7; i++) {
        if (mask & 1) {
            ok = 0;
            p = &o->x5FC[i];
            *p |= 1;
            if (id < e->x36 && !(id < e->x34)) {
                if (!(f20 <= cosf(3.1415927f * (e->x38 / 180.0f)))) {
                    *p |= 2;
                    if (o->x5E0[i] == 0.0f) {
                        o->x5E0[i] = e->x3B / 10.0f;
                        ok = 1;
                    }
                }
            }
            if (ok) {
                r = Rand_Range_3_0013D500(100);
                if (r <= e->x3A) {
                if (best > e->x39) {
                    list[0] = i;
                    best = e->x39;
                    n = 1;
                } else if (best == e->x39) {
                    list[n++] = i;
                }
                }
            }
        }
        mask >>= 1;
        e++;
    }
    if (n) {
        *res = list[(u8)Rand_Range_3_0013D500(n - 1)];
    } else {
        *res = 0xFF;
    }
    if (*res == 0xFF) return;
    flag = 1;
    if ((u8)Ent_GetTypeByte_1_0013E220(o) == 0x69) flag = 0;
    if (!flag) return;
    if (!Enemy_Get5B6b4_1_0013EAA0(o)) return;
    sceVu0CopyVector(&A, Enemy_GetPositionPtr_2_00140460(o));
    A.y -= 100.0f;
    A.w = 1.0f;
    sceVu0CopyVector(&B, Player_GetBody_1_00145770());
    B.w = 1.0f;
    memset(&buf, 0, 0x40);
    if ((&D_00201E80)[2]) Enemy_RaycastMapB_0_0013D320(*(s32 *)(&D_00201E80)[2], &buf, &A, 6, 7);
    if (buf.x24 == 0 && (&D_00201E80)[3]) Enemy_RaycastMapB_0_0013D320(*(s32 *)(&D_00201E80)[3], &buf, &A, 6, 7);
    if (buf.x24) *res = 0xFF;
}
#undef Script_GetArgPtr_2_00165130
#undef Enemy_GetPositionPtr_2_00140460
#undef sceVu0CopyVector
#undef D_00201FA8

/* EnemyCmd_Set5B2b4_1_00144960 */
void EnemyCmd_Set5B2b4_1_00144960(void) {
    Enemy_Set5B2b4_1_0013E790(M2C_FIELD(D_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_GetPosition_2_00144970 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetPosition_2_00144970
extern S_EnemyCmd_GetPosition_2_00144970 *D_00201FA8__as_EnemyCmd_GetPosition_2_00144970;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPosition_2_00144970
f32 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPosition_2_00144970(void *o, s32 b);
#define Enemy_CopyPosition_2_00140470 Enemy_CopyPosition_2_00140470__as_EnemyCmd_GetPosition_2_00144970
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_GetPosition_2_00144970(void *p, f32 *v);

void EnemyCmd_GetPosition_2_00144970(void *o)
{
    void *q = D_00201FA8->p;
    f32 *x = Script_GetArgPtr_2_00165130(o, 0);
    f32 *y = Script_GetArgPtr_2_00165130(o, 1);
    f32 *z = Script_GetArgPtr_2_00165130(o, 2);
    f32 v[4];
    Enemy_CopyPosition_2_00140470(q, v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}
#undef Script_GetArgPtr_2_00165130
#undef Enemy_CopyPosition_2_00140470
#undef D_00201FA8

/* EnemyCmd_SpawnEffect_0_00144A00 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_SpawnEffect_0_00144A00
extern s8 *D_00201FA8__as_EnemyCmd_SpawnEffect_0_00144A00;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnEffect_0_00144A00
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, s32);
#define Enemy_CopyPosition_2_00140470 Enemy_CopyPosition_2_00140470__as_EnemyCmd_SpawnEffect_0_00144A00
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, Vec *);
#define Enemy_GetForwardVector_2_001403D0 Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_SpawnEffect_0_00144A00
void Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, Vec *);
#define Enemy_GetRightVector_1_00140360 Enemy_GetRightVector_1_00140360__as_EnemyCmd_SpawnEffect_0_00144A00
void Enemy_GetRightVector_1_00140360__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, Vec *);
#define Enemy_CopyRotation_2_00140440 Enemy_CopyRotation_2_00140440__as_EnemyCmd_SpawnEffect_0_00144A00
void Enemy_CopyRotation_2_00140440__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, Vec *);

void EnemyCmd_SpawnEffect_0_00144A00(s8 *a0) {
    Vec A;
    Vec B;
    Vec C;
    s8 *o = *(s8 **)(D_00201FA8 + 0x154);
    u16 id = *(u16 *)(a0 + 8);
    s32 k = *(u8 *)(a0 + 0x10);
    s8 *res = Script_GetArgPtr_2_00165130(a0, 2);
    f32 f1 = *(f32 *)(a0 + 0x20);
    f32 f2 = *(f32 *)(a0 + 0x28);
    f32 f3 = *(f32 *)(a0 + 0x30);
    s8 r = Player_ThrowItem_0_001CA960();
    if (r == -1) {
        Enemy_CopyPosition_2_00140470(o, &A);
        Enemy_GetForwardVector_2_001403D0(o, &B);
        A.x = A.x + B.x * f1;
        A.z = A.z + B.z * f1;
        A.y = A.y + f2;
        Enemy_GetRightVector_1_00140360(o, &B);
        A.x = A.x + B.x * f3;
        A.z = A.z + B.z * f3;
        Enemy_CopyRotation_2_00140440(o, &C);
        r = Player_HoldItem_0_001CAB20(id, k, &A, &C);
    }
    if (r == 0) {
        *res = 0;
    } else {
        *res = 1;
    }
}
#undef Script_GetArgPtr_2_00165130
#undef Enemy_CopyPosition_2_00140470
#undef Enemy_GetForwardVector_2_001403D0
#undef Enemy_GetRightVector_1_00140360
#undef Enemy_CopyRotation_2_00140440
#undef D_00201FA8

/* EnemyCmd_StopEffect_0_00144B80 */
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_StopEffect_0_00144B80
u8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_StopEffect_0_00144B80(s32, s32);
void EnemyCmd_StopEffect_0_00144B80(u16 *a0) {
    u16 v;
    u8 *p;
    u8 b;
    v = a0[4];
    p = Script_GetArgPtr_2_00165130((s32)a0, 1);
    b = Inventory_GetEntry_1_001CC3F0(v)->x2;
    if (b > 0x80) {
        *p = 0x80;
        return;
    }
    *p = b;
}
#undef Script_GetArgPtr_2_00165130

/* EnemyCmd_SpawnEffectB_0_00144BE0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_SpawnEffectB_0_00144BE0
extern char *D_00201FA8__as_EnemyCmd_SpawnEffectB_0_00144BE0;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnEffectB_0_00144BE0
u8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnEffectB_0_00144BE0(Arg_EnemyCmd_SpawnEffectB_0_00144BE0 *, s32);
#define Enemy_CopyPosition_2_00140470 Enemy_CopyPosition_2_00140470__as_EnemyCmd_SpawnEffectB_0_00144BE0
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_SpawnEffectB_0_00144BE0(char *, Vec *);
#define Enemy_GetForwardVector_2_001403D0 Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_SpawnEffectB_0_00144BE0
void Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_SpawnEffectB_0_00144BE0(char *, Vec *);
#define Enemy_GetRightVector_1_00140360 Enemy_GetRightVector_1_00140360__as_EnemyCmd_SpawnEffectB_0_00144BE0
void Enemy_GetRightVector_1_00140360__as_EnemyCmd_SpawnEffectB_0_00144BE0(char *, Vec *);
#define Enemy_CopyRotation_2_00140440 Enemy_CopyRotation_2_00140440__as_EnemyCmd_SpawnEffectB_0_00144BE0
void Enemy_CopyRotation_2_00140440__as_EnemyCmd_SpawnEffectB_0_00144BE0(char *, Vec *);

void EnemyCmd_SpawnEffectB_0_00144BE0(Arg_EnemyCmd_SpawnEffectB_0_00144BE0 *a0) {
    char *pl = *(char **)(D_00201FA8 + 0x154);
    u16 n = a0->x8;
    u8 *out = Script_GetArgPtr_2_00165130(a0, 1);
    f32 f22 = a0->x18;
    f32 f21 = a0->x20;
    f32 f20 = a0->x28;
    s8 r = Player_DropItem_0_001CAC30();
    if (r == -1) {
        Vec p;
        Vec d;
        Vec q;
        Enemy_CopyPosition_2_00140470(pl, &p);
        Enemy_GetForwardVector_2_001403D0(pl, &d);
        p.x += d.x * f22;
        p.z += d.z * f22;
        p.y += f21;
        Enemy_GetRightVector_1_00140360(pl, &d);
        p.x += d.x * f20;
        p.z += d.z * f20;
        Enemy_CopyRotation_2_00140440(pl, &q);
        r = Player_PlaceItem_0_001CADF0(n, &p, &q, 0);
    }
    if (r == 0) {
        *out = 0;
    } else {
        *out = 1;
    }
}
#undef Script_GetArgPtr_2_00165130
#undef Enemy_CopyPosition_2_00140470
#undef Enemy_GetForwardVector_2_001403D0
#undef Enemy_GetRightVector_1_00140360
#undef Enemy_CopyRotation_2_00140440
#undef D_00201FA8

/* EnemyCmd_ResetState_1_00144D50 */
void EnemyCmd_ResetState_1_00144D50(void) {
    Enemy_SetStateResetTimer_1_0013E7E0(M2C_FIELD(D_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_Set5B3b3_1_00144D60 */
void EnemyCmd_Set5B3b3_1_00144D60(void) {
    Enemy_Set5B3b3_1_0013E7C0(M2C_FIELD(D_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_Set5B2b0_1_00144D70 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B2b0_1_00144D70
extern S_EnemyCmd_Set5B2b0_1_00144D70 *D_00201FA8__as_EnemyCmd_Set5B2b0_1_00144D70;

void EnemyCmd_Set5B2b0_1_00144D70(u8 *arg0)
{
    Enemy_Set5B2b0_1_0013E890(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_BroadcastFrame_1_00144D80 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_BroadcastFrame_1_00144D80
extern S_EnemyCmd_BroadcastFrame_1_00144D80 *D_00201FA8__as_EnemyCmd_BroadcastFrame_1_00144D80;
#define Enemy_GetTargetHandle_0_0013EDE0 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_BroadcastFrame_1_00144D80
u8 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_BroadcastFrame_1_00144D80(void *p);

void EnemyCmd_BroadcastFrame_1_00144D80(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    void *p = D_00201FA8->p;
    u8 x = Enemy_GetTargetHandle_0_0013EDE0(p);
    EnemyScr_BroadcastFrameEvent_0_001410C0(x, a, (u8)Enemy_GetMotionId_0_0013ED20(p), b);
}
#undef Enemy_GetTargetHandle_0_0013EDE0
#undef D_00201FA8

/* EnemyCmd_Set5B1b7_1_00144DF0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B1b7_1_00144DF0
extern S_EnemyCmd_Set5B1b7_1_00144DF0 *D_00201FA8__as_EnemyCmd_Set5B1b7_1_00144DF0;

void EnemyCmd_Set5B1b7_1_00144DF0(u8 *arg0)
{
    Enemy_Set5B1b7_1_0013E8C0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_Set5B1b6_1_00144E00 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B1b6_1_00144E00
extern S_EnemyCmd_Set5B1b6_1_00144E00 *D_00201FA8__as_EnemyCmd_Set5B1b6_1_00144E00;

void EnemyCmd_Set5B1b6_1_00144E00(u8 *arg0)
{
    Enemy_Set5B1b6_1_0013E8F0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_BreakPart_1_00144E10 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_BreakPart_1_00144E10
extern S_EnemyCmd_BreakPart_1_00144E10 *D_00201FA8__as_EnemyCmd_BreakPart_1_00144E10;

void EnemyCmd_BreakPart_1_00144E10(u8 *arg0)
{
    Enemy_BreakPart_0_0013F210(D_00201FA8->p, arg0[8], 1);
}
#undef D_00201FA8

/* EnemyCmd_Set5B0b0_1_00144E30 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B0b0_1_00144E30
extern S_EnemyCmd_Set5B0b0_1_00144E30 *D_00201FA8__as_EnemyCmd_Set5B0b0_1_00144E30;

void EnemyCmd_Set5B0b0_1_00144E30(u8 *arg0)
{
    Enemy_Set5B0b0_1_0013EC30(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_HealPercent_1_00144E40 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_HealPercent_1_00144E40
extern S_EnemyCmd_HealPercent_1_00144E40 *D_00201FA8__as_EnemyCmd_HealPercent_1_00144E40;
#define Enemy_AddHp_2_0013F710 Enemy_AddHp_2_0013F710__as_EnemyCmd_HealPercent_1_00144E40
u16 Enemy_AddHp_2_0013F710__as_EnemyCmd_HealPercent_1_00144E40(void *, s32);
void EnemyCmd_HealPercent_1_00144E40(u8 *o) {
    void *p;
    u8 pct;
    u16 hp;
    pct = o[8];
    p = D_00201FA8->p;
    hp = Enemy_GetMaxHp_2_0013F700(p);
    Enemy_AddHp_2_0013F710(p, -hp);
    if (pct > 100) pct = 100;
    Enemy_AddHp_2_0013F710(p, hp * pct / 100);
}
#undef Enemy_AddHp_2_0013F710
#undef D_00201FA8

/* EnemyCmd_Set5B1b5_1_00144EE0 */
void EnemyCmd_Set5B1b5_1_00144EE0(void) {
    Enemy_Set5B1b5_1_0013E920(M2C_FIELD(D_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_Set5B1b3_1_00144EF0 */
void EnemyCmd_Set5B1b3_1_00144EF0(void) {
    Enemy_Set5B1b3IfUnlocked_1_0013E9D0(M2C_FIELD(D_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_Set5B1b2Notify_0_00144F00 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B1b2Notify_0_00144F00
extern Ctx *D_00201FA8__as_EnemyCmd_Set5B1b2Notify_0_00144F00;

void EnemyCmd_Set5B1b2Notify_0_00144F00(unsigned char *a)
{
    void *p = D_00201FA8->p;
    int v = a[8];
    if (!(unsigned char)Enemy_Get5B1b2_1_0013EA40(p) && v)
        Msg_Close_1_0018B0C0();
    Enemy_Set5B1b2_1_0013EA20(p, v);
}
#undef D_00201FA8

/* EnemyCmd_GetParamIdx_1_00144F60 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetParamIdx_1_00144F60
extern S_EnemyCmd_GetParamIdx_1_00144F60 *D_00201FA8__as_EnemyCmd_GetParamIdx_1_00144F60;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetParamIdx_1_00144F60
s16 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetParamIdx_1_00144F60(s32 a, s32 b);

void EnemyCmd_GetParamIdx_1_00144F60(s32 a)
{
    void *p = D_00201FA8->p;
    s16 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Enemy_GetCurrentParamIdx_0_0013E110(p);
}
#undef Script_GetArgPtr_2_00165130
#undef D_00201FA8

/* EnemyCmd_Set5B1b1_1_00144FA0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B1b1_1_00144FA0
extern S_EnemyCmd_Set5B1b1_1_00144FA0 *D_00201FA8__as_EnemyCmd_Set5B1b1_1_00144FA0;

void EnemyCmd_Set5B1b1_1_00144FA0(u8 *arg0)
{
    Enemy_Set5B1b1_1_0013EA50(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_UpdateParamFlags_1_00144FB0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_UpdateParamFlags_1_00144FB0
extern S_EnemyCmd_UpdateParamFlags_1_00144FB0 *D_00201FA8__as_EnemyCmd_UpdateParamFlags_1_00144FB0;

void EnemyCmd_UpdateParamFlags_1_00144FB0(u8 *arg0)
{
    Enemy_UpdateParamFlags_0_0013F760(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_RegisterKill_0_00144FC0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_RegisterKill_0_00144FC0
extern S_EnemyCmd_RegisterKill_0_00144FC0 *D_00201FA8__as_EnemyCmd_RegisterKill_0_00144FC0;
#define Ent_GetTypeByte_1_0013E220 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_RegisterKill_0_00144FC0
u8 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_RegisterKill_0_00144FC0(void *p);

void EnemyCmd_RegisterKill_0_00144FC0(void)
{
    s16 i = Ent_GetTypeByte_1_0013E220(D_00201FA8->p);
    Bestiary_SetKilled_1_001A9FA0(i);
    Bestiary_IsSeen_2_001A9EC0(i);
    Bestiary_SetSeen_1_001A9F10(i);
}
#undef Ent_GetTypeByte_1_0013E220
#undef D_00201FA8

/* EnemyCmd_RegisterSeen_0_00145010 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_RegisterSeen_0_00145010
extern S_EnemyCmd_RegisterSeen_0_00145010 *D_00201FA8__as_EnemyCmd_RegisterSeen_0_00145010;
#define Ent_GetTypeByte_1_0013E220 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_RegisterSeen_0_00145010
u8 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_RegisterSeen_0_00145010(void *p);

void EnemyCmd_RegisterSeen_0_00145010(void)
{
    s16 i = Ent_GetTypeByte_1_0013E220(D_00201FA8->p);
    Bestiary_IsKilled_1_001A9F60(i);
    Bestiary_SetKilled_1_001A9FA0(i);
}
#undef Ent_GetTypeByte_1_0013E220
#undef D_00201FA8

/* EnemyCmd_Set5B1b0_1_00145060 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B1b0_1_00145060
extern S_EnemyCmd_Set5B1b0_1_00145060 *D_00201FA8__as_EnemyCmd_Set5B1b0_1_00145060;

void EnemyCmd_Set5B1b0_1_00145060(u8 *arg0)
{
    Enemy_Set5B1b0_1_0013EB10(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_SetGameFlag_2_00145070 */
void EnemyCmd_SetGameFlag_2_00145070(u8 *arg0)
{
    GameFlag_SetBit_2_0013D5C0(arg0[8], arg0[0x10]);
}

/* EnemyCmd_TestGameFlag_2_00145080 */
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_TestGameFlag_2_00145080
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_TestGameFlag_2_00145080(u8 *o, s32 b);

void EnemyCmd_TestGameFlag_2_00145080(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    s8 *p = Script_GetArgPtr_2_00165130(o, 2);
    *p = GameFlag_TestBit_2_0013D630(a, b);
}
#undef Script_GetArgPtr_2_00165130

/* EnemyCmd_SetDead_1_001450D0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_SetDead_1_001450D0
extern S_EnemyCmd_SetDead_1_001450D0 *D_00201FA8__as_EnemyCmd_SetDead_1_001450D0;

void EnemyCmd_SetDead_1_001450D0(u8 *arg0)
{
    Enemy_SetDeadFlag_0_0013EEB0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_Set5B0b7_1_001450E0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B0b7_1_001450E0
extern S_EnemyCmd_Set5B0b7_1_001450E0 *D_00201FA8__as_EnemyCmd_Set5B0b7_1_001450E0;

void EnemyCmd_Set5B0b7_1_001450E0(u8 *arg0)
{
    Enemy_Set5B0b7_1_0013EB40(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_KillNow_1_001450F0 */
#define Enemy_Kill_1_0013EF80 Enemy_Kill_1_0013EF80__as_EnemyCmd_KillNow_1_001450F0
int Enemy_Kill_1_0013EF80__as_EnemyCmd_KillNow_1_001450F0();

void EnemyCmd_KillNow_1_001450F0(void) {
    Enemy_Kill_1_0013EF80(M2C_FIELD(D_00201FA8, void **, 0x154), 0xFF);
}
#undef Enemy_Kill_1_0013EF80

/* EnemyCmd_Random_2_00145100 */
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_Random_2_00145100
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_Random_2_00145100(void *a, s32 b);
#define Rand_Range_3_0013D500 Rand_Range_3_0013D500__as_EnemyCmd_Random_2_00145100
s8 Rand_Range_3_0013D500__as_EnemyCmd_Random_2_00145100(u8 v);

void EnemyCmd_Random_2_00145100(u8 *a)
{
    s8 *p = Script_GetArgPtr_2_00165130(a, 0);
    *p = Rand_Range_3_0013D500(a[0x10]);
}
#undef Script_GetArgPtr_2_00165130
#undef Rand_Range_3_0013D500

/* EnemyCmd_GetType_1_00145140 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetType_1_00145140
extern S_EnemyCmd_GetType_1_00145140 *D_00201FA8__as_EnemyCmd_GetType_1_00145140;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetType_1_00145140
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetType_1_00145140(s32 a, s32 b);
#define Ent_GetTypeByte_1_0013E220 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_GetType_1_00145140
s8 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_GetType_1_00145140(void *p);

void EnemyCmd_GetType_1_00145140(s32 a)
{
    void *p = D_00201FA8->p;
    s8 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Ent_GetTypeByte_1_0013E220(p);
}
#undef Script_GetArgPtr_2_00165130
#undef Ent_GetTypeByte_1_0013E220
#undef D_00201FA8

/* EnemyCmd_Set5B0b1_1_00145180 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Set5B0b1_1_00145180
extern S_EnemyCmd_Set5B0b1_1_00145180 *D_00201FA8__as_EnemyCmd_Set5B0b1_1_00145180;

void EnemyCmd_Set5B0b1_1_00145180(u8 *arg0)
{
    Enemy_Set5B0b1_1_0013EC10(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_AddHp_2_00145190 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_AddHp_2_00145190
extern S_EnemyCmd_AddHp_2_00145190 *D_00201FA8__as_EnemyCmd_AddHp_2_00145190;
#define Enemy_AddHp_2_0013F710 Enemy_AddHp_2_0013F710__as_EnemyCmd_AddHp_2_00145190
void Enemy_AddHp_2_0013F710__as_EnemyCmd_AddHp_2_00145190(void *arg0, u16 arg1);

void EnemyCmd_AddHp_2_00145190(u8 *arg0)
{
    Enemy_AddHp_2_0013F710(D_00201FA8->p, arg0[8]);
}
#undef Enemy_AddHp_2_0013F710
#undef D_00201FA8

/* EnemyCmd_Get5B0b0_1_001451A0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_Get5B0b0_1_001451A0
extern S_EnemyCmd_Get5B0b0_1_001451A0 *D_00201FA8__as_EnemyCmd_Get5B0b0_1_001451A0;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_Get5B0b0_1_001451A0
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_Get5B0b0_1_001451A0(s32 a, s32 b);

void EnemyCmd_Get5B0b0_1_001451A0(s32 a)
{
    void *p = D_00201FA8->p;
    s8 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Enemy_Get5B0m1_1_0013EC50(p);
}
#undef Script_GetArgPtr_2_00165130
#undef D_00201FA8

/* EnemyCmd_AddPartValue_0_001451E0 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_AddPartValue_0_001451E0
extern S_EnemyCmd_AddPartValue_0_001451E0 *D_00201FA8__as_EnemyCmd_AddPartValue_0_001451E0;
void EnemyCmd_AddPartValue_0_001451E0(u8 *arg0) {
    P_EnemyCmd_AddPartValue_0_001451E0 *p;
    u8 a;
    s32 d;
    u8 b;
    u8 c;
    p = D_00201FA8->p;
    a = arg0[0x10];
    d = arg0[8];
    b = arg0[0x18];
    c = arg0[0x20];
    if (a != 0xFF) p->x610 = a;
    if ((b & 0xFF) != 0xFF) p->x612 = b;
    if (c & 0xFF) p->x613 = c;
    if (d != 0) {
        p->x611 = 0;
        p->x614 = 0;
    }
}
#undef D_00201FA8

/* EnemyCmd_GetHpPercent_2_00145250 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetHpPercent_2_00145250
extern S_EnemyCmd_GetHpPercent_2_00145250 *D_00201FA8__as_EnemyCmd_GetHpPercent_2_00145250;
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetHpPercent_2_00145250
s8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetHpPercent_2_00145250(s32 a, s32 b);

void EnemyCmd_GetHpPercent_2_00145250(s32 a)
{
    void *p = D_00201FA8->p;
    s8 *q = Script_GetArgPtr_2_00165130(a, 0);
    *q = Enemy_GetHpPercent_2_0013F620(p);
}
#undef Script_GetArgPtr_2_00165130
#undef D_00201FA8

/* EnemyCmd_SetMode_1_00145290 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_SetMode_1_00145290
extern S_EnemyCmd_SetMode_1_00145290 *D_00201FA8__as_EnemyCmd_SetMode_1_00145290;

void EnemyCmd_SetMode_1_00145290(u8 *arg0)
{
    Enemy_SetMode_0_0013EBA0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8

/* EnemyCmd_SelectMotionB_1_001452A0 */
void EnemyCmd_SelectMotionB_1_001452A0(void *arg0) {
    Enemy_SelectMotion_0_0013C420(M2C_FIELD(D_00201FA8, void **, 0x154), (s32) M2C_FIELD(arg0, u8 *, 8), (s64) M2C_FIELD(arg0, s16 *, 0x10), 1);
}

/* EnemyCmd_Set609_1_001452C0 */
void EnemyCmd_Set609_1_001452C0(void *arg0) {
    M2C_FIELD(M2C_FIELD(D_00201FA8, void **, 0x154), s8 *, 0x609) = (s8) M2C_FIELD(arg0, s8 *, 8);
}

/* EnemyCmd_SetMapObjFlag_0_001452E0 */
void EnemyCmd_SetMapObjFlag_0_001452E0(u8 *o) {
    u8 m = o[8];
    s16 *p = PlayerData_Get_2_001C9BA0();
    u8 fl = 0;
    u8 i;
    if (m & 1) { fl |= 1; p[2] = p[0]; }
    if (m & 2) { fl |= 2; p[3] = p[1]; }
    if (fl) Player_PlayLevelUpSe_0_001C9FB0(0);
    for (i = 0; i < 3; i++) if (fl & (1 << i)) Sfx_Spawn_2_00169B50(i + 0x1EA, 0, 1, 0);
}

/* EnemyCmd_PlaySe_1_001453A0 */
#define sceVu0CopyVector sceVu0CopyVector__as_EnemyCmd_PlaySe_1_001453A0
void sceVu0CopyVector__as_EnemyCmd_PlaySe_1_001453A0(f32 *, f32 *);
#define D_00201FA8 D_00201FA8__as_EnemyCmd_PlaySe_1_001453A0
extern S_EnemyCmd_PlaySe_1_001453A0 *D_00201FA8__as_EnemyCmd_PlaySe_1_001453A0;
void EnemyCmd_PlaySe_1_001453A0(A *a) {
    S_EnemyCmd_PlaySe_1_001453A0 *s;
    u16 h;
    u8 b;
    f32 v[4];
    P_EnemyCmd_PlaySe_1_001453A0 p;
    s32 k;
    s = D_00201FA8;
    k = s->x154;
    h = a->x8;
    b = a->x10;
    p = D_00201C50;
    sceVu0CopyVector(v, Enemy_Ptr6F0_1_0013FFA0(k, s));
    SndCh_GetPosition_1_00131180(Snd_PlaySeAt_2_001315A0(h, b, v), &p);
}
#undef sceVu0CopyVector
#undef D_00201FA8

/* EnemyCmd_GetModelPos_0_00145410 */
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_GetModelPos_0_00145410
f32 *Script_GetArgPtr_2_00165130__as_EnemyCmd_GetModelPos_0_00145410(s32, s32);
#define sceVu0CopyVector sceVu0CopyVector__as_EnemyCmd_GetModelPos_0_00145410
void sceVu0CopyVector__as_EnemyCmd_GetModelPos_0_00145410(Vec *, Vec *);
#define D_00201FA8 D_00201FA8__as_EnemyCmd_GetModelPos_0_00145410
extern s8 *D_00201FA8__as_EnemyCmd_GetModelPos_0_00145410;

void EnemyCmd_GetModelPos_0_00145410(s32 a0) {
    s32 o;
    f32 *x, *y, *z;
    Vec *s;
    o = *(s32 *)(D_00201FA8 + 0x154);
    x = Script_GetArgPtr_2_00165130(a0, 0);
    y = Script_GetArgPtr_2_00165130(a0, 1);
    z = Script_GetArgPtr_2_00165130(a0, 2);
    {
        Vec v = {0};
        s = Enemy_GetModelData_1_0013DCE0(o);
        if (s) sceVu0CopyVector(&v, s);
        *x = v.x;
        *y = v.y;
        *z = v.z;
    }
}
#undef Script_GetArgPtr_2_00165130
#undef sceVu0CopyVector
#undef D_00201FA8

/* EnemyCmd_SpawnItem_0_001454E0 */
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnItem_0_001454E0
u8 *Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnItem_0_001454E0(Arg_EnemyCmd_SpawnItem_0_001454E0 *, s32);

void EnemyCmd_SpawnItem_0_001454E0(Arg_EnemyCmd_SpawnItem_0_001454E0 *a) {
    u32 v = a->x8.w;
    u8 *p = Script_GetArgPtr_2_00165130(a, 1);
    u8 k = a->x18.w;
    void *o = MapObj_FindById_0_00179DB0(v / 1000, v % 1000);
    if (o) {
        if (k == 0) *p = Msg_ShowWrap_1_0018AC90(o, 0);
        if (k == 1) *p = Msg_ShowWrap_1_0018AC90(o, -1);
    } else {
        *p = 3;
    }
}
#undef Script_GetArgPtr_2_00165130

/* EnemyCmd_ShakeCamera_0_001455B0 */
void EnemyCmd_ShakeCamera_0_001455B0(Obj_EnemyCmd_ShakeCamera_0_001455B0 *o)
{
    T_EnemyCmd_ShakeCamera_0_001455B0 t = { 0 };
    t.v = 256.0f * o->f;
    Camera_SetShake_0_00189F00(&t);
}

/* EnemyCmd_ResetVectors_1_00145610 */
#define D_00201FA8 D_00201FA8__as_EnemyCmd_ResetVectors_1_00145610
extern S_EnemyCmd_ResetVectors_1_00145610 *D_00201FA8__as_EnemyCmd_ResetVectors_1_00145610;

void EnemyCmd_ResetVectors_1_00145610(u8 *arg0)
{
    Enemy_ResetVectors_0_0013D1F0(D_00201FA8->p, arg0[8]);
}
#undef D_00201FA8
