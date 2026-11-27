#include "m2c.h"
void Menu_SetFlags_0_0018A310(s32);
f32 Approachf_3_00187770(f32, f32, f32);
s32 DbItem_FindA_1_0019D4A0(s32);
void Text_Draw_2_001875C0(s32, s32, u32, f32, f32, f32);
void UiAnim_UpdateAll_1_0017F5C0(void);
void DbItem_DrawRing_0_00197130(s32, f32);
void DbItem_DrawStats_0_00196F90(f32);
extern s32 *D_00201D3C;
extern f32 D_00201D40;
extern s32 D_004A1430[];
extern f32 D_004A1440[];
typedef union { u32 w; u8 b[4]; } Col;

void DbItem_Draw_0_00196E20(u8 *arg0) {
    Col c;
    s32 h;

    Menu_SetFlags_0_0018A310(0xE);
    if (arg0[8] == 0x1B) {
        D_00201D40 = Approachf_3_00187770(D_00201D40, -0.02f, 3.5f);
    } else {
        D_00201D40 = Approachf_3_00187770(D_00201D40, -2.99f, 3.5f);
    }
    h = DbItem_FindA_1_0019D4A0(D_00201D3C[D_004A1430[0]]);
    c.w = 0x80FFFFFF;
    c.b[3] = D_004A1440[0];
    Text_Draw_2_001875C0(h, 2, c.w, 622.0f, 17.0f, 1.0f);
    UiAnim_UpdateAll_1_0017F5C0();
    if (!(D_00201D40 <= -2.99f)) {
        DbItem_DrawRing_0_00197130(D_00201D3C[D_004A1430[0]], D_00201D40);
        DbItem_DrawStats_0_00196F90(D_00201D40);
    }
}
