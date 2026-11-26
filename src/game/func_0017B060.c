#include "common.h"
typedef struct { u8 p0[8]; s32 x8; u8 pC[4]; s32 x10; u8 p14[4]; f32 x18; u8 p1c[4]; f32 x20; u8 p24[4]; f32 x28; u8 p2c[4]; f32 x30; u8 p34[4]; f32 x38; u8 p3c[4]; f32 x40; u8 p44[4]; f32 x48; u8 p4c[4]; f32 x50; } O;
void func_0015D800(u16, Vec *, Vec *, f32, f32);
s32 func_001B0C70(s32, s32);
void func_0017B060(O *o) {
    s32 i0 = o->x8;
    f32 x = o->x48;
    s32 i1 = o->x10;
    f32 z = o->x50;
    Vec a;
    Vec b;
    a.x = o->x18;
    a.y = o->x20;
    a.z = o->x28;
    a.w = 1.0f;
    b.x = o->x30;
    b.y = o->x38;
    b.z = o->x40;
    b.w = 0.0f;
    func_0015D800(func_001B0C70(i0, i1), &a, &b, x, z);
}
