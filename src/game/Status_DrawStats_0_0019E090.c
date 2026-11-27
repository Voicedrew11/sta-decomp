#include "m2c.h"
typedef struct { u16 v[8]; } H;
typedef struct { f32 v[4]; } F;
extern s32 D_004A32C8[];
H *PlayerData_Get_2_001C9BA0(void);
s8 *Player_GetBodyState_1_001C9B60(void);
s32 Player_Exists_3_001C9BF0(void);
void Player_CalcStats_0_0019A500(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);
void Menu_DrawStatRing_0_00186440(f32, H *, H *, H *, H *);
void Menu_SetOffset_0_00185B30(s32, s32);
void Menu_DrawRingD_0_00185510(f32, H *);
void Menu_DrawRingE_0_00185B40(f32, s8 *);
void UiAnim_UpdateAll_1_0017F5C0(void);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);

void Status_DrawStats_0_0019E090(f32 f) {
    s32 r8C;
    s32 r88;
    s32 r84;
    H t70;
    H a60;
    H a50;
    H a40;
    H a30;
    s8 *s;
    s32 i;

    PlayerData_Get_2_001C9BA0();
    s = Player_GetBodyState_1_001C9B60();
    t70 = *PlayerData_Get_2_001C9BA0();
    if (Player_Exists_3_001C9BF0()) {
        a40 = *(H *)(s + 0x460);
        *(F *)&a30 = *(F *)(s + 0x470);
        Player_CalcStats_0_0019A500(&a60, &a50, &r8C, &r88, &r84, -1, 0, 0);
    } else {
        return;
    }
    for (i = 0; i < 8; i++) {
        a40.v[7 - i] -= a60.v[7 - i];
        a30.v[7 - i] -= a50.v[7 - i];
    }
    Menu_DrawStatRing_0_00186440(f, &a60, &a50, &a40, &a30);
    Menu_SetOffset_0_00185B30(0, 0);
    Menu_DrawRingD_0_00185510(f, &t70);
    Menu_DrawRingE_0_00185B40(f, s);
    UiAnim_UpdateAll_1_0017F5C0();
    Menu_DrawFrame_0_00185390(f, 1, 5, D_004A32C8[0]);
}
