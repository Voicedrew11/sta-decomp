#include "common.h"

/* bss_002F1120: the game's .bss from 0x002F1120, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Gfx_InitDisplay_2_00129040, Camera_UpdateView_1_001296C0, Frame_RenderGame_1_0012A070, Frame_UpdateGame_1_0012A520,
   Loading_Loop_0_0012AC00, Frame_RenderLoading_0_0012B600, Game_RunSubLoop_0_0012B8E0, SndEmit_Update_1_0012F6F0, SndEmit_Update3D_1_0012FC20,
   SndEmit_UpdateAmbientRandom_1_00130090, SndEmit_UpdateLooping_1_001302A0, SndCh_Update3D_2_00130810, Snd_StartRequest_2_00131640, GsPkt_ResetFrame_1_00153770,
   GsPkt_DrawFadeRect_0_00153B50, GsPkt_DrawClearRect_0_00153D80, Gfx_SphereInFrustum_1_00153FA0, GsPkt_AddRegData_1_001541F0, GsPkt_EndADDirect_1_00154230,
   GsPkt_BeginADDirect_1_001542D0, GsPkt_PushTag_1_00154310, GsPkt_AllocDirect_1_001543A0, GsPkt_SetReg_3_001543E0, GsPkt_EndAD_3_00154420,
   GsPkt_BeginAD_3_001545D0, GsPkt_SetLayerB_0_00154610, GsPkt_SetLayer_1_00154700, GsPkt_SetLayerRange_0_001547F0, GsPkt_SetLayerTop_0_001548F0,
   GsPkt_CloseChain_1_001549D0, GsPkt_Alloc_3_00154A80, GsPkt_GetUsedQw_1_00154AC0, GsPkt_ResetLayer_0_00154AF0, GsPkt_SetBaseTex_0_00154B00,
   Gfx_KickFrame_1_00154B70, Gfx_WaitDraw_1_001552A0, Gfx_FlipBuffers_2_00155370, Gfx_UploadVu1Program_0_00155460, GsPkt_EndLayer_1_00155900,
   GsPkt_EndLayerEx_0_001559C0, GsPkt_GetLayerCount_0_00155A90, Draw_ShadowDisc_0_00156920, Weather_Update_0_00157D50, Weather_RespawnParticle_0_00157FE0,
   ScreenFx_ProjectPoint_0_00159160, ScreenFx_SetFadeColor_0_00159460, ScreenFx_GetParamsC_0_00159620, ScreenFx_GetParamsD_0_00159650, ScreenFx_DrawAll_2_00159680,
   ScreenFx_Init_1_00159A60, Lightning_BuildStrip_0_00164440, Mdl_SetLayerForBounds_0_0016B500, Hud_DrawOverlay_0_001BCB60, Player_DrawWeapon_0_001BCFF0,
   text_00153770.s, text_001544C0.s, text_00155090.s, text_00157630.s,
   text_00157FE0.s, text_00164440.s, text_0016BD00.s */

s16 D_002F1A48[0x4];
f32 D_002F19E0[0x1a];
s32 D_002F19DC[0x1];
s32 D_002F19D8[0x1];
u8 D_002F19D4[0x4];
u8 D_002F19C8[0xc]; /* also D_002F19CA, D_002F19CB, D_002F19CC */
u8 D_002F19C4[0x4];
u8 D_002F19C0[0x4];
u8 D_002F19B0[0x10];
u8 D_002F19AC[0x4];
u8 D_002F19A8[0x4];
u32 D_002F19A4[0x1];
u32 D_002F19A0[0x1];
u32 D_002F199C[0x1];
u8 D_002F1998[0x4];
u8 D_002F1994[0x4];
u8 D_002F1990[0x4];
s32 D_002F1950[0x10];
s32 D_002F194C[0x1];
s32 D_002F1948[0x1];
u32 D_002F1944[0x1];
u8 D_002F1940[0x4];
u8 D_002F1900[0x40];
u8 D_002F18C0[0x40];
u8 D_002F1880[0x40];
u8 D_002F1840[0x40];
u8 D_002F1800[0x40];
u8 D_002F17C0[0x40];
u8 D_002F1780[0x40];
u8 D_002F1740[0x40];
u8 D_002F1700[0x40];
u8 D_002F16E4[0x1c] __attribute__((aligned(4))); /* also D_002F16E8 */
u8 D_002F16E0[0x4];
u8 D_002F16D8[0x8];
u8 D_002F16D4[0x4];
u8 D_002F16D0[0x4];
u8 D_002F16C8[0x8];
u8 D_002F16C4[0x4];
u8 D_002F16C0[0x4];
u8 D_002F1694[0x2c] __attribute__((aligned(4))); /* also D_002F1698 */
f32 D_002F1690[0x1];
u8 D_002F1680[0x10];
u8 D_002F1640[0x40];
u8 D_002F1600[0x40];
u8 D_002F15E4[0x1c] __attribute__((aligned(4))); /* also D_002F15E8 */
u8 D_002F15E0[0x4];
u8 D_002F15D8[0x8];
u8 D_002F15D4[0x4];
u8 D_002F15D0[0x4];
u8 D_002F15C8[0x8];
u8 D_002F15C4[0x4];
u8 D_002F15C0[0x4];
u8 D_002F1580[0x40];
u8 D_002F1510[0x70];
u8 D_002F1500[0x10]; /* also D_002F1504 */
u8 D_002F14F0[0x10];
u8 D_002F14E0[0x10];
u8 D_002F1490[0x50];
u8 D_002F1420[0x70];
u8 D_002F1410[0x10]; /* also D_002F1414 */
u8 D_002F1400[0x10];
u8 D_002F13F0[0x10];
u8 D_002F13D0[0x20];
u8 D_002F13C8[0x8];
u8 D_002F13A0[0x28]; /* also D_002F13A8 */
u8 D_002F1390[0x10];
u8 D_002F1388[0x8];
u8 D_002F1340[0x48];
u8 D_002F1338[0x8];
u8 D_002F12D4[0x64] __attribute__((aligned(4))); /* also D_002F12D8, D_002F12E8, D_002F1328 */
u8 D_002F12D0[0x4];
u8 D_002F12C8[0x8];
u8 D_002F12C0[0x8];
u8 D_002F12B8[0x8];
u8 D_002F12B0[0x8];
u8 D_002F1250[0x60]; /* also D_002F1298 */
u8 D_002F1248[0x8];
u8 D_002F11E4[0x64] __attribute__((aligned(4))); /* also D_002F11E8, D_002F11F8, D_002F1238 */
u8 D_002F11E0[0x4];
u8 D_002F11D8[0x8];
u8 D_002F11D0[0x8];
u8 D_002F11C8[0x8];
u8 D_002F11C0[0x8];
u8 D_002F1170[0x50]; /* also D_002F1198 */
u8 D_002F1160[0x10];
u8 D_002F1158[0x8];
u8 D_002F1150[0x8];
u8 D_002F1148[0x8];
u8 D_002F1140[0x8];
u8 D_002F113C[0x4];
u8 D_002F1138[0x4];
u8 D_002F1134[0x4];
u8 D_002F1130[0x4];
u8 D_002F112C[0x4];
u8 D_002F1128[0x4];
u8 D_002F1124[0x4];
u8 D_002F1120[0x4] __attribute__((aligned(16)));
