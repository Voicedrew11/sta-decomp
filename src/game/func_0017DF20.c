#include "common.h"
typedef struct { u8 pad[8]; s32 x8; s32 pC; s32 x10; s32 p14; s32 x18; u8 p1C[0xC]; f32 x28; u8 p2C[0x24]; f32 x50; f32 p54; f32 x58; } Arg;
s32 *func_00165130(Arg *, s32);
s32 func_001A9B40(s16);
s32 func_001AC0F0(s32, u16, Vec *);
s32 func_001ABF70(s32, u16, Vec *);

void func_0017DF20(Arg *a0) {
    s32 type;
    f32 dx;
    s32 id;
    f32 dy;
    s32 sub;
    f32 dz;
    s32 *out;
    Vec v;

    type = a0->x8;
    dx = a0->x28;
    id = a0->x10;
    dy = a0->x50;
    sub = a0->x18;
    dz = a0->x58;
    out = func_00165130(a0, 5);
    func_00165130(a0, 6);
    func_00165130(a0, 7);
    func_00165130(a0, 8);
    if (type == 0) {
        *out = func_001A9B40(id);
    }
    if (type == 1) {
        *out = 0;
        *out = func_001AC0F0(id, sub, &v);
        if (*out != 0) {
            v.x += dx;
            v.y += dy;
            v.z += dz;
            v.w = 1.0f;
            *out = func_001ABF70(id, sub, &v);
            if (*out == 0) {
                return;
            }
        }
    }
}
