#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r; u8 g; u8 b; u8 a; } Col;
extern S D_001F2770[] __attribute__((aligned(16)));
extern f32 D_002020A4;
f32 func_0011DA18(f32);
s8 *func_00189020(s32);
void func_00181680(s32, s8 *, s8 *, void *, S *, s32);

void func_00182EF0(s32 x0, s32 y0, s32 x1, s32 y1, f32 u0, f32 u1, f32 alpha) {
    S t __attribute__((aligned(16)));
    Col col;
    s8 *o;

    t = D_001F2770[0];
    o = *(s8 **)(func_00189020(0) + 0x84);
    col.r = 0x80;
    col.g = 0x80;
    col.b = 0x80;
    D_002020A4 += 0.1f;
    col.a = alpha / 2.0f;
    t.x = (f32)x0 + 6.0f * func_0011DA18(D_002020A4);
    t.y = (f32)y0;
    func_00181680(*(s32 *)(o + 4), o + 0x10, o + 0x20, &col, &t, 0);
    t.x = (f32)x1 - 6.0f * func_0011DA18(D_002020A4);
    t.y = (f32)y1;
    func_00181680(*(s32 *)(o + 4), o + 0x10, o + 0x20, &col, &t, 1);
}
