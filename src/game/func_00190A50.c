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
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    f32 v10[4];
    f32 v20[4];
} E;
typedef struct {
    u8 pad0[0x84];
    E *x84;
    u8 pad88[0xC];
    E *x94;
} P;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} B;
void func_00181680(s32, f32 *, f32 *, Col *, S *, s32);
P *func_00189020(s32);
s32 func_0017F3D0(s32);
void func_001875C0(f32, s32, f32, f32, u32, u32);
extern s32 D_00201D00[2];
extern s32 D_001F2B90[];
extern S D_001F2C90 __attribute__((aligned(16)));
extern u8 D_004A1073[];
extern u8 D_004A1077[];
extern f32 D_004A10C4[];
extern f32 D_004A10C8[];

void func_00190A50(A *o, s32 unused, u32 kind, B *b) {
    Col col;
    S s __attribute__((aligned(16)));
    s32 h;
    s32 r;
    E *e;

    h = b->x8;
    s = D_001F2C90;
    col.c.r = col.c.g = col.c.b = 0x80;
    col.c.a = 0x40;
    if (h != 0) {
        if (kind < 0xC8) {
            s.x = o->x30;
            s.y = o->x34;
            col = o->x2C;
            func_00181680(o->x28, o->v0, o->v10, &col, &s, 0);
            return;
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
                func_001875C0(o->x38, D_00201D00[!D_004A1073[0]], o->x3C, 0.83333331f, 1, col.w);
            } else if (b->x0 == 1) {
                func_001875C0(o->x38, D_001F2B90[D_004A1077[0]], o->x3C, 0.83333331f, 1, col.w);
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
        case 0x190:
            s.x = o->x30;
            s.y = o->x34;
            func_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, 0);
            break;
        }
    }
}
