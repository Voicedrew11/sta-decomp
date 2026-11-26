#include "m2c.h"
typedef union {
    u32 w;
    f32 f;
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
    s32 x8;
} B;
void func_00181680(s32, f32 *, f32 *, Col *, S *, u32);
u32 strlen(s32);
void func_001875C0(f32, s32, f32, f32, u32, u32);
extern S D_001F2C30 __attribute__((aligned(16)));
extern s32 D_004A10D4[];

void func_00191420(A *o, s32 unused, u32 kind, B *b) {
    S s __attribute__((aligned(16)));
    Col col;
    s32 h;

    h = b->x8;
    s = D_001F2C30;
    if (h == 0) return;
    if (kind < 200) {
        s.x = o->x30;
        s.y = o->x34;
        col = o->x2C;
        if (D_004A10D4[0] != 0 && b->x4 == 0xFA2) {
            col.c.r = col.c.g = col.c.b = 0x40;
        }
        func_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    }
    switch (kind) {
    case 200:
        col.w = 0x80808080;
        col.c.a = o->x2C.c.a * 2;
        o->x3C += 4.0f;
        if (strlen(h) < 16) {
            o->x3C += 9.0f;
        }
        func_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
        break;
    }
}
