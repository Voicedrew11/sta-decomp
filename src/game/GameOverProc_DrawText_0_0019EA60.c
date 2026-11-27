#include "m2c.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    u64 a, b;
    f32 x, y;
} S;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A;
void Ui_DrawSprite_2_00181680(s32, f32 *, f32 *, Col *, S *, s32);
void Text_Draw_2_001875C0(f32, char *, f32, f32, u32, u32);
char *Msg_GetText_2_00195B10(s32);
void Color_Pulse_1_00187960(f32, Col *);
extern S D_001F31E0 __attribute__((aligned(16)));
extern char D_001FD660[];
extern s32 D_0020220C;
extern f32 D_0020221C;
extern f32 D_002020D4;
static inline f32 u2f(u32 x) { return x; }

void GameOverProc_DrawText_0_0019EA60(A *o, s32 mode, u32 kind, u32 c) {
    Col col;
    S s __attribute__((aligned(16)));

    s = D_001F31E0;
    s.x = o->x30;
    s.y = o->x34;
    o->x2C.w = c;
    if (mode == 1) {
        if (kind < 100) {
            col.w = 0x80303030;
            col.c.a = o->x2C.c.a;
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        } else if (kind == 100 && mode == 1) {
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a;
            Text_Draw_2_001875C0(o->x38, Msg_GetText_2_00195B10(0x4B), o->x3C, 1.0f, 1, col.w);
        }
    } else if (mode == 2) {
        if (kind == 100) {
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a;
            Text_Draw_2_001875C0(o->x38, Msg_GetText_2_00195B10(0x4C), o->x3C, 1.0f, 1, col.w);
        }
        if (kind == 0 && D_0020220C == 0) {
            col.w = 0x80303030;
            col.c.a = (s32)(D_0020221C * u2f(o->x2C.c.a));
            Color_Pulse_1_00187960(D_002020D4, &col);
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        }
    } else if (mode == 3) {
        if (kind == 100 && mode == 3) {
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a;
            Text_Draw_2_001875C0(o->x38, Msg_GetText_2_00195B10(0x4D), o->x3C, 1.0f, 1, col.w);
        }
        if (kind == 0 && D_0020220C == 1) {
            col.w = 0x80303030;
            col.c.a = (s32)(D_0020221C * u2f(o->x2C.c.a));
            Color_Pulse_1_00187960(D_002020D4, &col);
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        }
    } else {
        if (kind < 100) {
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, kind);
        } else if (kind == 100 && mode == 1) {
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a;
            Text_Draw_2_001875C0(o->x38, D_001FD660, o->x3C, 1.0f, 1, col.w);
        }
    }
}
