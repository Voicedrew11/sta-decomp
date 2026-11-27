#include "common.h"
typedef struct { u8 pad[8]; s32 id; s32 p0C; f32 x10, p14, x18, p1C, x20, p24, x28, p2C, x30, p34, x38, p3C, x40, p44, x48, p4C, x50, p54; u16 x58; u16 p5A, p5C, p5E; u16 x60; u16 p62; s32 p64; s32 x68; } O;
void MapObj_SpawnItem_0_001B0990(s32, Vec *, Vec *, Vec *, u16, u16, s32);
void MapCmd_SetEffectPos_0_0017CAC0(O *o) {
    Vec a, b, c;
    s32 id = o->id;
    u16 x58 = o->x58;
    u16 x60 = o->x60;
    s32 x68 = o->x68;
    a.x = o->x10; a.y = o->x18; a.z = o->x20; a.w = 1.0f;
    b.x = o->x28; b.y = o->x30; b.z = o->x38; b.w = 1.0f;
    c.x = o->x40; c.y = o->x48; c.z = o->x50; c.w = 1.0f;
    MapObj_SpawnItem_0_001B0990(id, &a, &b, &c, x58, x60, x68);
}
