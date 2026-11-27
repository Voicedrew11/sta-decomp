#include "m2c.h"
typedef struct { u8 r, g, b, a; } Col;
typedef struct { u8 b0:1; } B;
void Menu_DrawBackground_0_00187B20(s32);
s32 Text_Render_2_00188010(void *, Col);
extern s32 D_004A0F54[];
extern f32 D_004A0F58[];
extern B D_004A0F5C[];
extern s8 D_004A0F60[];
extern f32 D_004A0F74[];

void Msg_Draw_0_0018ACA0(void) {
    Col c3;
    Col c2;
    Col c5;

    switch (D_004A0F54[0]) {
    case 3:
        if (D_004A0F58[0] > 0.0f) {
            *(u32 *)&c3 = 0x80808080;
            if (D_004A0F58[0] < 8.0f) {
                c3.a = (s32)(16.0f * D_004A0F58[0]);
            }
            Text_Render_2_00188010(D_004A0F60, c3);
            D_004A0F74[0] += 1.0f;
        }
        if (D_004A0F58[0] < 0.0f) {
            D_004A0F54[0] = 0;
        }
        D_004A0F58[0] -= 1.0f;
        break;
    case 2:
        *(u32 *)&c2 = 0x80808080;
        D_004A0F5C[0].b0 = Text_Render_2_00188010(D_004A0F60, c2);
        D_004A0F58[0] -= 1.0f;
        D_004A0F74[0] += 1.0f;
        break;
    case 5:
        *(u32 *)&c5 = 0x80808080;
        D_004A0F5C[0].b0 = Text_Render_2_00188010(D_004A0F60, c5);
        D_004A0F58[0] -= 1.0f;
        D_004A0F74[0] += 1.0f;
        break;
    }
    Menu_DrawBackground_0_00187B20(1);
}
