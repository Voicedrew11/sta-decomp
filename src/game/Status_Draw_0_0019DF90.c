#include "common.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { u8 pad[8]; u8 x8; } E;
void Menu_SetFlags_0_0018A310(s32);
void Status_DrawStats_0_0019E090(f32, E *);
f32 Approachf_3_00187770(f32, f32, f32);
s8 *Msg_GetText_2_00195B10(s32);
void Text_Draw_2_001875C0(s8 *, s32, Col, f32, f32, f32);
extern f32 D_00201D78;
extern s32 D_004A32C8[];

void Status_Draw_0_0019DF90(E *e) {
    Col c;
    Menu_SetFlags_0_0018A310(0xC);
    if (!(D_00201D78 <= -2.49f)) Status_DrawStats_0_0019E090(D_00201D78, e);
    if (e->x8 == 0x14) {
        D_00201D78 = Approachf_3_00187770(D_00201D78, -0.02f, 3.5f);
        c.w = 0x80FFFFFF;
        if (D_004A32C8[0] >= 0) {
            Text_Draw_2_001875C0(Msg_GetText_2_00195B10(D_004A32C8[0] + 0xA), 2, c, 622.0f, 17.0f, 1.0f);
        }
    } else {
        D_00201D78 = Approachf_3_00187770(D_00201D78, -2.99f, 3.5f);
    }
}
