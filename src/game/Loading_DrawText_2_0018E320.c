#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; s8 b[4]; } Col;
extern S D_001F2A70[] __attribute__((aligned(16)));
const s8 D_001FCDF0[0x18] = { -0x7e, 0x6d, -0x7e, 0x6e, -0x7e, 0x76, 0x20, -0x7e, 0x6b, -0x7e, 0x6e, -0x7e, 0x60, -0x7e, 0x63, -0x7e, 0x68, -0x7e, 0x6d, -0x7e, 0x66 };
extern f32 D_002020D4;
void Text_Draw_2_001875C0(f32, f32, f32, s32, s32, u32);
void Color_Pulse_1_00187960(f32, Col *);
void Ui_DrawSprite_2_00181680(s32, s8 *, s8 *, void *, S *, s32);

void Loading_DrawText_2_0018E320(s8 *a0, s32 a1, s32 a2) {
    S t __attribute__((aligned(16)));
    Col col;

    t = D_001F2A70[0];
    t.x = *(f32 *)(a0 + 0x30);
    t.y = *(f32 *)(a0 + 0x34);
    *(u32 *)(a0 + 0x2C) = 0xA0A0A0A0;
    *(u8 *)(a0 + 0x2F) = 0x80;
    if (a2 == 100) {
        col.w = 0x80808080;
        Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 1.0f, (s32)D_001FCDF0, 1, col.w);
    } else if (a1 != 0) {
        col.w = 0x80808080;
        col.b[3] = 0x30;
        Color_Pulse_1_00187960(D_002020D4, &col);
        Ui_DrawSprite_2_00181680(*(s32 *)(a0 + 0x28), a0, a0 + 0x10, &col, &t, a2);
    } else {
        Ui_DrawSprite_2_00181680(*(s32 *)(a0 + 0x28), a0, a0 + 0x10, a0 + 0x2C, &t, a2);
    }
}
