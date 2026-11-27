#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r, g, b, a; } C;
typedef struct {
    u8 pad0[0x10];
    u8 x10[0x18];
    s32 x28;
    u8 x2C;
    u8 x2D;
    u8 x2E;
    u8 x2F;
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
} O;
typedef struct { s32 x0; s32 x4; s8 *x8; } P;
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } R;
typedef struct { u8 pad0[0x9C]; R *x9C; u8 padA0[0x24]; R *xC4; } G;
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, S *, u32);
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, u32);
void Color_PulseB_1_00187A20(f32, u8 *, s32);
G *MenuLayout_GetSub_1_00189020(s32);
#pragma explicit_zero_data on
S D_001F2590 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
extern s32 D_00201CC8;
extern s32 D_00201CCC;
extern s32 *D_00202040;
extern s32 *D_00202048;
extern f32 D_002020D4;
static inline s32 get(s32 *tbl, s32 i) {
    if (tbl != 0 && i > 0) {
        return tbl[i];
    }
    return 0;
}

void UiProc_DrawText_0_00180CA0(O *o, s32 a1, u32 mode, P *p) {
    S buf __attribute__((aligned(16)));
    C col;
    s8 *str;
    R *r;

    str = p->x8;
    buf = D_001F2590;
    if (str == 0) {
        return;
    }
    if (mode < 200) {
        buf.x = o->x30;
        buf.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
        if (get(D_00202040, p->x0) == 0) {
            return;
        }
        r = MenuLayout_GetSub_1_00189020(0)->xC4;
        buf.x = o->x38;
        buf.y = o->x3C - 4.0f;
        o->x2C = 0x50;
        o->x2D = 0x80;
        o->x2E = 0x40;
        Color_PulseB_1_00187A20(D_002020D4, &o->x2C, 0x50);
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 200:
        if (p->x0 == D_00201CC8 || p->x0 == D_00201CCC) {
            r = MenuLayout_GetSub_1_00189020(0)->x9C;
            buf.x = o->x38;
            buf.y = o->x3C;
            Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, &buf, mode);
        }
        break;
    case 201:
        if (get(D_00202048, p->x0) != 0) {
            *(u32 *)&col = 0x80404080;
        } else {
            *(u32 *)&col = 0x80808080;
        }
        col.a = o->x2F * 2;
        o->x38 += 96.0f;
        Text_Draw_2_001875C0(o->x38, o->x3C, 1.0f, str, 1, *(u32 *)&col);
        break;
    }
}
