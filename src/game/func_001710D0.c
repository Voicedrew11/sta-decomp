#include "m2c.h"
typedef struct {
    s32 p0;
    u8 x4;
    u8 p5;
    u16 n;
    u16 x8;
    u16 xA;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    f32 x1C;
    f32 x20;
    u8 p24;
    u8 b0:2;
    u8 st:3;
    u8 b5:3;
    u8 pad[0x1A];
    s8 data[1];
} Obj;
void func_00102A70(s8 *, s8 *);
void func_00171BB0(s8 *, Obj *, u8, u8, u16, f32);
extern s32 D_00201F2C;

void func_001710D0(Obj *obj, s16 a1, f32 a, f32 b, f32 c) {
    f32 v;
    s8 *r;
    s8 *p;
    s8 *q;
    s32 i;
    s32 stride;

    v = -1.0f * (obj->x1C + b);
    if (v < 0.0f) {
        p = obj->data;
        func_00171BB0(p + D_00201F2C * (obj->n * 0x140 + 0x200), obj, obj->x4, obj->n, obj->x8, obj->xC);
        stride = obj->n * 0x140 + 0x200;
        q = p + stride;
        r = p + D_00201F2C * stride;
        for (i = 0; i < obj->n + 1; i++) {
            func_00102A70(p + 0x180, r + 0x140);
            func_00102A70(q + 0x180, r + 0x140);
            r += 0x140;
            p += 0x140;
            q += 0x140;
        }
    }
    obj->xC = v;
    obj->x10 = v;
    obj->x20 = obj->xC;
    *(s32 *)&obj->x8 = a1;
    obj->x14 = a;
    obj->x18 = b;
    obj->x1C = c;
    obj->st = 0;
}
