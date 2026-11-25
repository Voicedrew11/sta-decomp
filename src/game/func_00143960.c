#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { f32 x, y, z; s32 w; } V3;
typedef struct { s32 p0, p4; u8 type; u8 p9[7]; f32 a; s32 p14; f32 b; s32 p1C; f32 c; } Arg;
Vec *func_0013FF90(s8 *);
Vec *func_0013FFB0(s8 *);
Vec *func_00140340(s8 *);
Vec *func_00140460(s8 *);
void func_00102A60(Vec *, Vec *);
void func_001029D0(Vec *, Vec *, void *);
void func_001403D0(s8 *, Vec *, s8 *);
void func_00140360(s8 *, Vec *);
extern s8 *D_00201FA8;

void func_00143960(Arg *arg0) {
    V3 d;
    Vec t;
    s8 *o;
    s8 *g;
    u8 type;

    g = D_00201FA8;
    type = arg0->type;
    o = *(s8 **)(g + 0x154);
    d.x = arg0->a;
    d.y = arg0->b;
    d.z = arg0->c;
    d.w = 0;
    switch (type) {
    case 0:
        func_00102A60(func_0013FF90(o), func_0013FFB0(o));
        break;
    case 1:
        func_001029D0(func_0013FF90(o), func_00140340(o), &d);
        break;
    case 2: {
        Vec v = {0};
        func_001403D0(o, &t, g);
        v.x += t.x * d.x;
        v.z += t.z * d.x;
        v.y += d.y;
        func_00140360(o, &t);
        v.x += t.x * d.z;
        v.z += t.z * d.z;
        func_001029D0(func_0013FF90(o), func_00140460(o), &v);
        break;
    }
    }
}
