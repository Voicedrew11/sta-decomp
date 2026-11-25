#include "m2c.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    u64 a, b;
    f32 x, y;
} S191110;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A191110;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    f32 v10[4];
    f32 v20[4];
} E191110;
typedef struct {
    u8 pad0[0x84];
    E191110 *x84;
    u8 pad88[0xC];
    E191110 *x94;
} P191110;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} B191110;
void func_00181680(s32, f32 *, f32 *, Col *, S191110 *, s32);
P191110 *func_00189020(s32);
s32 func_0017F3D0(s32);
void func_001875C0(f32, s32, f32, f32, u32, u32);
void func_00191580(A191110 *, u32, s32);
extern s32 D_001F2B80[];
extern s32 D_00201D00[2];
extern S191110 D_001F2C70 __attribute__((aligned(16)));
extern u8 D_004A1070[];
extern u8 D_004A1072[];
extern u8 D_004A1078[];
extern f32 D_004A10C4[];
extern f32 D_004A10C8[];

void func_00190DC0(A191110 *o, s32 unused, u32 kind, B191110 *b) {
    Col col;
    S191110 s __attribute__((aligned(16)));
    s32 h;
    s32 alpha;
    s32 r;
    E191110 *e;

    h = b->x8;
    s = D_001F2C70;
    alpha = 0x40;
    col.c.r = col.c.g = col.c.b = 0x80;
    col.c.a = alpha;
    if (h != 0) {
        if (kind < 0xC8) {
            s.x = o->x30;
            s.y = o->x34;
            func_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, 0);
            return;
        }
        if (b->x0 == 2) {
            alpha = D_004A1070[0];
        }
        r = func_0017F3D0(0xB);
        switch (kind) {
        case 0xC8:
            if (b->x4 == 0xFA4) {
                e = func_00189020(0)->x94;
                s.x = o->x38;
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &o->x2C, &s, 0);
            }
            break;
        case 0xC9:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            func_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
            break;
        case 0xCA:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            if (b->x0 == 0) {
                func_001875C0(o->x38, D_00201D00[!D_004A1078[0]], o->x3C, 0.83333331f, 1, col.w);
            } else if (b->x0 == 1) {
                func_001875C0(o->x38, D_001F2B80[D_004A1072[0]], o->x3C, 0.83333331f, 1, col.w);
            }
            break;
        case 0xCB:
            if (r != 0 && b->x4 == 0xFA4) {
                e = &func_00189020(0)->x84[1];
                s.x = o->x38 + D_004A10C8[0];
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0xCC:
            if (r != 0 && b->x4 == 0xFA4) {
                e = func_00189020(0)->x84;
                s.x = o->x38 + D_004A10C4[0];
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        }
        func_00191580(o, kind, alpha);
    }
}
