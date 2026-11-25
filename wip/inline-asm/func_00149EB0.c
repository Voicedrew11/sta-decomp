#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec m[4]; } Mtx;
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x30];
    f32 x50;
    f32 x54;
    u8 pad58[0x30];
    f32 x88;
    u8 pad8C[0x24];
    f32 xB0;
    u8 padB4[0xC];
    u8 xC0[0x20];
    u8 xE0[0x34];
    u8 b0:1;
    u8 b1:1;
} O;
extern Mtx D_001F2170;
u16 func_0015ED20(void);
void func_00102CC8(f32, Mtx *, Mtx *);
void func_00102C20(f32, Mtx *, Mtx *);
void func_00146140(void *, f32, f32);
void func_001027E0(void *, void *, Mtx *);
f32 func_00102848(Vec *, Vec *);
void func_00102A18(Vec *, void *, f32);
f32 sqrtf(f32);
s32 func_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);
void func_00102A60(void *, void *);
static inline f32 sq(f32 v) { f32 r; asm("sqrt.s %0, %1" : "=f"(r) : "f"(v)); return r; }
static inline f32 jit(f32 a) { f32 t = 0.5f - 0.000015259022f * (f32)(u32)func_0015ED20(); return t * a; }

void func_00149EB0(O *o) {
    Mtx m;
    Vec out;
    Vec lo;
    Vec hi;
    f32 rx;
    f32 ry;
    f32 h;

    rx = 0.0f;
    if (o->x50 != rx) {
        rx = 0.01745f * o->x50;
    }
    rx = jit(rx);
    ry = 0.0f;
    ry = (o->x54 != ry) ? 0.01745f * o->x54 : ry;
    ry = jit(ry);
    o->xB0 = 0;
    func_00102CC8(WRAP(ry), &m, &D_001F2170);
    func_00102C20(WRAP(rx), &m, &m);
    func_00146140(o->xC0, o->v.x, o->v.z);
    func_001027E0(o->xC0, o->xC0, &m);
    func_00102A18(&o->v, o->xE0, sqrtf(func_00102848(&o->v, &o->v)));
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
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}
