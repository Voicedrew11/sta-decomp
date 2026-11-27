#include "common.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    f32 v10[4];
    f32 v20[4];
} E;
typedef struct {
    u8 pad0[0xAC];
    E *xAC;
} P;
typedef struct {
    Flags8 f;
    u8 pad[3];
} Ent;
typedef struct {
    s32 idx;
    u8 pad4[0x14];
    Ent e[1];
} Menu;
void Ui_DrawSprite_2_00181680(s32, f32 *, f32 *, Col *, S *, u32);
P *MenuLayout_GetSub_1_00189020(s32);
f32 sinf(f32);
f32 fabsf(f32);
void sprintf(s8 *, s8 *, s32);
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, u32);
extern S D_001F2DE0 __attribute__((aligned(16)));
extern s8 D_001FD208[];
extern Menu D_004A1180[];
extern f32 D_004A118C[];
extern f32 D_004A1190[];

void LoadMenu_DrawSlot_1_00193AF0(A *o, s32 idx, u32 kind) {
    f32 *py;
    f32 *px;
    E *e;
    f32 f;
    S s __attribute__((aligned(16)));
    Col col;

    s = D_001F2DE0;
    if (kind < 500) {
        s.x = o->x30;
        s.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, kind);
        return;
    }
    switch (kind) {
    case 500:
        if (idx == D_004A1180[0].idx) {
            o->x2C.c.r = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1190[0])));
            o->x2C.c.g = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1190[0])));
            o->x2C.c.b = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1190[0])));
        } else {
            o->x2C.c.r = 0x40;
            o->x2C.c.g = 0x40;
            o->x2C.c.b = 0x40;
            o->x2C.c.a = 0x40;
        }
        if (D_004A1180[0].e[idx].f.f.b0) {
            s.x = o->x30;
            s.y = o->x34;
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, kind);
        }
        break;
    case 0x226:
        e = MenuLayout_GetSub_1_00189020(0)->xAC;
        px = &s.x;
        py = &s.y;
        col.w = 0x30808080;
        s.m[0] = 1.0f;
        s.m[3] = 1.0f;
        *px = o->x38;
        *py = o->x3C;
        col.w = (idx == D_004A1180[0].idx) ? 0x40808000 : 0x30808080;
        Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &col, &s, kind);
        {
        s8 buf[16] = {0};
        col.w = 0x80808080;
        f = D_004A118C[0];
        if (f <= 0.0f) {
            col.c.a = 0;
        } else if (f < 128.0f) {
            col.c.a = col.c.a * (s32)f / 128.0f;
        }
        sprintf(buf, D_001FD208, idx + 1);
        Text_Draw_2_001875C0(8.0f + *px, 4.0f + *py, 1.0f, buf, 0, col.w);
        }
        break;
    }
}
