#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r; u8 g; u8 b; u8 a; } Col;
extern S D_001F25B0[] __attribute__((aligned(16)));
extern f32 D_00202054;
extern f32 D_00486984[];
extern f32 D_00486988[];
s8 *func_00189020(s32);
void func_00181680(s32, s8 *, s8 *, void *, S *, s32);

void func_001803E0(s8 *o, s32 unused, u32 id, s32 up) {
    S t __attribute__((aligned(16)));
    Col col;
    s8 *p;

    t = D_001F25B0[0];
    col.b = 0x80;
    col.g = 0x80;
    col.r = 0x80;
    col.a = 0x40;
    if (id < 200) {
        t.x = *(f32 *)(o + 0x30);
        t.y = *(f32 *)(o + 0x34);
        func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        return;
    }
    if (up) {
        D_00202054 += 4.0f;
        if (!(D_00202054 <= 64.0f)) {
            D_00202054 = 64.0f;
        }
    } else {
        D_00202054 -= 4.0f;
        if (D_00202054 < 0.0f) {
            D_00202054 = 0.0f;
        }
    }
    col.a = D_00202054;
    switch (id) {
    case 200:
        p = *(s8 **)(func_00189020(0) + 0x8C) + 0x30;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C) + D_00486988[0];
        func_00181680(*(s32 *)(p + 4), p + 0x10, p + 0x20, &col, &t, 1);
        break;
    case 201:
        p = *(s8 **)(func_00189020(0) + 0x8C);
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C) + D_00486984[0];
        func_00181680(*(s32 *)(p + 4), p + 0x10, p + 0x20, &col, &t, 1);
        break;
    }
}
