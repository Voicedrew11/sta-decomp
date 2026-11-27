#include "common.h"
typedef struct { u8 pad[8]; s16 x8; u8 p2[6]; s16 x10; u8 p3[6]; f32 x18; u8 p4[4]; f32 x20; u8 p5[4]; f32 x28; u8 p6[4]; f32 x30; u8 p7[4]; f32 x38; u8 p8[4]; f32 x40; } O;
void MapObj_SpawnSfx_0_001B0D60(s16, s16, Vec *, Vec *);
void MapCmd_SetLightPos_0_0017DC00(O *o) {
    Vec a;
    Vec b;
    s16 i = o->x8;
    s16 j = o->x10;
    f32 ax = o->x18, ay = o->x20, az = o->x28;
    f32 bx = o->x30, by = o->x38, bz = o->x40;
    a.x = ax;
    a.y = ay;
    a.z = az;
    a.w = 1.0f;
    b.x = bx;
    b.y = by;
    b.z = bz;
    b.w = 1.0f;
    MapObj_SpawnSfx_0_001B0D60(i, j, &a, &b);
}
