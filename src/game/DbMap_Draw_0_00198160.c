#include "m2c.h"
void Menu_SetFlags_0_0018A310(s32);
f32 Approachf_3_00187770(f32, f32, f32);
s32 DbMap_GetName_0_00195A30(s32);
typedef union { u32 w; u8 b[4]; } Col;
void Text_Draw_2_001875C0(s32, s32, Col, f32, f32, f32);
void UiAnim_UpdateAll_1_0017F5C0(void);
void DbMap_DrawRing_0_001982A0(s32, f32);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
extern f32 D_00201D44;
extern s32 D_002021A8;
extern s32 D_004A1450[];
extern s32 D_004A18B0[];

void DbMap_Draw_0_00198160(u8 *arg0) {
    Col c;
    s32 s;

    s = D_004A1450[D_004A18B0[0]];
    Menu_SetFlags_0_0018A310(0xE);
    if (arg0[8] == 0x19) {
        D_00201D44 = Approachf_3_00187770(D_00201D44, -0.02f, 3.5f);
    } else {
        D_00201D44 = Approachf_3_00187770(D_00201D44, -2.99f, 3.5f);
    }
    if (!(D_00201D44 <= -2.99f)) {
        DbMap_DrawRing_0_001982A0(s, D_00201D44);
    }
    if (s >= 0) {
        s32 h = DbMap_GetName_0_00195A30(s);
        c.w = 0x80FFFFFF;
        Text_Draw_2_001875C0(h, 2, c, 622.0f, 17.0f, 1.0f);
    }
    UiAnim_UpdateAll_1_0017F5C0();
    Menu_DrawFrame_0_00185390(D_00201D44, 1, D_002021A8, D_004A18B0[0]);
}
