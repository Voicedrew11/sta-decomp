#include "common.h"
s8 *PlayerData_Get_2_001C9BA0(void);
s8 *Player_GetBodyState_1_001C9B60(void);
s32 Player_Exists_3_001C9BF0(void);
void Menu_DrawStatRing_0_00186440(f32, s8 *, s8 *, s8 *, s8 *);
void Menu_SetOffset_0_00185B30(s32, s32);
void Menu_DrawRingD_0_00185510(f32, s8 *);
void Menu_DrawRingE_0_00185B40(f32, s8 *);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void UiAnim_UpdateAll_1_0017F5C0(void);
extern s32 D_004A4350[];
void Storage_DrawStatus_0_001A31E0(f32 f) { s8 *p; s8 *q; s8 *a; s8 *b; PlayerData_Get_2_001C9BA0(); a = Player_GetBodyState_1_001C9B60(); b = PlayerData_Get_2_001C9BA0(); if (Player_Exists_3_001C9BF0()) { p = a + 0x460; q = a + 0x470; } else { return; } Menu_DrawStatRing_0_00186440(f, p, q, 0, 0); Menu_DrawRingD_0_00185510(f, b); Menu_SetOffset_0_00185B30(0, 0); Menu_DrawRingE_0_00185B40(f, a); UiAnim_UpdateAll_1_0017F5C0(); Menu_DrawFrame_0_00185390(f, 1, 4, D_004A4350[0]); }

