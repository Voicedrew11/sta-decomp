#include "common.h"
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x68];
    f32 x88;
    u8 pad8C[0x24];
    f32 xB0;
    u8 padB4[0x60];
    u8 b0:1;
    u8 b1:1;
} O;
s32 func_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);
void func_00102A60(void *, void *);
f32 func_00102848(Vec *, Vec *);
float sqrtf(float);

void func_00149D20(O *o) {
    Vec out;
    Vec lo;
    Vec hi;
    f32 s;
    f32 r;
    f32 h;
    if (5.0f < o->xB0) {
        o->xB0 = 0;
    } else {
        o->xB0 = o->xB0 + 1.0f;
        return;
    }
    h = 1000.0f;
    lo.x = o->p.x;
    lo.y = o->p.y - h;
    lo.z = o->p.z;
    hi.x = o->p.x;
    hi.y = o->p.y + h;
    hi.z = o->p.z;
    hi.w = 1.0f;
    lo.w = 1.0f;
    if (func_001470F0(&lo, &hi, 3, 4, 1, &out)) {
        func_00102A60(o, &out);
        s = sqrtf(func_00102848(&o->v, &o->v));
        o->v.y = 0;
        r = s / sqrtf(func_00102848(&o->v, &o->v));
        o->v.x *= r;
        o->v.z *= r;
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}
