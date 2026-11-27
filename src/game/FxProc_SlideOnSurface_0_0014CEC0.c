#include "common.h"
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x40];
    f32 x60;
    u8 pad64[0x24];
    f32 x88;
    u8 pad8C[0x34];
    Vec c0;
    u8 padD0[0x10];
    f32 xE0;
    f32 xE4;
    f32 xE8;
    u8 padEC[0x28];
    u8 b0:1;
    u8 b1:1;
} O;
s32 Map_LineTest_1_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);
void sceVu0CopyVector(void *, void *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void Mtx_RotateToward_0_00146140(Vec *, f32, f32);
float sqrtf(float);

void FxProc_SlideOnSurface_0_0014CEC0(O *o) {
    Vec out;
    Vec lo;
    Vec hi;
    f32 h;
    f32 s;
    f32 r;
    h = o->x60;
    lo.x = o->p.x;
    lo.y = o->p.y - h;
    lo.z = o->p.z;
    hi.x = o->p.x;
    hi.y = o->p.y + h;
    hi.z = o->p.z;
    hi.w = 1.0f;
    lo.w = 1.0f;
    if (Map_LineTest_1_001470F0(&lo, &hi, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
        s = sqrtf(sceVu0InnerProduct(&o->v, &o->v));
        o->v.y = 0;
        r = s / sqrtf(sceVu0InnerProduct(&o->v, &o->v));
        o->v.x *= r;
        o->v.z *= r;
        Mtx_RotateToward_0_00146140(&o->c0, o->xE0, o->xE8);
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}
