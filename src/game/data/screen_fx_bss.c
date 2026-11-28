#include "common.h"

/* bss_002F1A60: the game's .bss from 0x002F1A60, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Weather_GetState_0_00157620, Weather_Update_0_00157D50, ScreenFx_ProjectPoint_0_00159160, ScreenFx_SetEnabled_0_00159310,
   ScreenFx_SetFlashParams_0_00159340, ScreenFx_SetFadeTarget_0_00159400, ScreenFx_EnableWeather_0_00159500, ScreenFx_GetParamsA_0_00159590, ScreenFx_GetParamsB_0_001595C0,
   ScreenFx_SetEnabledB_0_001595F0, ScreenFx_GetParamsC_0_00159620, ScreenFx_GetParamsD_0_00159650, ScreenFx_DrawAll_2_00159680, ScreenFx_Update_1_00159970,
   Arc_FindByHash_2_0015ABD0, Arc_Mount_2_0015AD00, Cd_Init_2_0015B040, Light_OffsetAll_0_0015B110, Fog_ApplyDefault_0_0015B270,
   Light_UpdateModel_0_0015B360, Light_CalcIntensity_0_0015B720, LightGroup_Clear_0_0015B890, LightGroup_Get_0_0015B900, Light_Add_0_0015B980,
   Light_SetAmbient_0_0015BB40, Light_Init_1_0015BCA0, PointLight_CalcIntensity_0_0015BDE0, PointLight_Update_0_0015C0C0, PointLight_OffsetAll_0_0015C620,
   PointLightGroup_Clear_0_0015C6D0, PointLight_Add_0_0015C730, PointLight_Init_0_0015C8D0, text_00157630.s,
   text_00159340.s, text_0015C8D0.s */

f32 D_0030C42C[0x1];
f32 D_0030C428[0x1];
f32 D_0030C424[0x1];
u8 D_0030C420[0x4];
u8 D_0030C3E0[0x40];
u8 D_0030C3D0[0x10]; /* also D_0030C3D4 */
u8 D_0030A3C4[0x200c] __attribute__((aligned(4))); /* also D_0030A3C8 */
f32 D_0030A3C0[0x1];
f32 D_0030A3BC[0x1];
f32 D_0030A3B8[0x1];
f32 D_0030A3B4[0x1];
u8 D_0030A3B0[0x4];
f32 D_0030A3AC[0x1];
u8 D_0030A3A0[0xc];
f32 D_0030A39C[0x1];
u8 D_0030A390[0xc];
u8 D_0030A378[0x18] __attribute__((aligned(8))); /* also D_0030A37C */
u8 D_0030A374[0x4];
u8 D_0030A370[0x4];
u8 D_0030A368[0x8];
u8 D_0030A364[0x4];
u8 D_0030A360[0x4];
u8 D_0030A350[0x10];
u8 D_0030A338[0x18] __attribute__((aligned(8))); /* also D_0030A33C */
u8 D_0030A334[0x4];
u8 D_0030A330[0x4];
u8 D_0030A320[0x10];
u8 D_0030A310[0x10];
u8 D_0030A2D0[0x40];
u8 D_0030A290[0x40];
u8 D_0030A0D0[0x1c0];
u8 D_002F20C4[0x1800c] __attribute__((aligned(4))); /* also D_002F20C8 */
u8 D_002F20C0[0x4];
f32 D_002F20BC[0x1];
f32 D_002F2080[0xf];
u8 D_002F2078[0x8];
u8 D_002F2070[0x8];
u8 D_002F1F10[0x160];
u8 D_002F1DB0[0x160];
u8 D_002F1C50[0x160];
u8 D_002F1AF0[0x160];
u8 D_002F1AEC[0x4];
u8 D_002F1AE8[0x4];
u8 D_002F1AE4[0x4];
s32 D_002F1AE0[0x1];
u8 D_002F1AD0[0x10]; /* also D_002F1AD4 */
u8 D_002F1AC0[0x10];
u8 D_002F1AB0[0x10];
u8 D_002F1AA0[0x10];
u8 D_002F1A9C[0x4];
u8 D_002F1A80[0x1c];
u8 D_002F1A78[0x8]; /* also D_002F1A7A, D_002F1A7B, D_002F1A7D, D_002F1A7E, D_002F1A7F */
u8 D_002F1A74[0x4]; /* also D_002F1A76 */
u8 D_002F1A70[0x4]; /* also D_002F1A72 */
u8 D_002F1A6C[0x4]; /* also D_002F1A6E */
u8 D_002F1A68[0x4]; /* also D_002F1A69, D_002F1A6A, D_002F1A6B */
u8 D_002F1A64[0x4]; /* also D_002F1A66 */
u8 D_002F1A60[0x4] __attribute__((aligned(16)));
