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
u16 Rand_Next_3_0015ED20(void);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void sceVu0RotMatrixX(f32, Mtx *, Mtx *);
void Mtx_RotateToward_0_00146140(void *, f32, f32);
void sceVu0MulMatrix(void *, void *, Mtx *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, void *, f32);
f32 sqrtf(f32);
s32 Map_LineTest_1_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);
void sceVu0CopyVector(void *, void *);
static inline f32 jit(f32 a) { f32 t = 0.5f - 0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20(); return t * a; }

void FxProc_RandomBounce_0_00149EB0(O *o) {
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
    sceVu0RotMatrixY(WRAP(ry), &m, &D_001F2170);
    sceVu0RotMatrixX(WRAP(rx), &m, &m);
    Mtx_RotateToward_0_00146140(o->xC0, o->v.x, o->v.z);
    sceVu0MulMatrix(o->xC0, o->xC0, &m);
    sceVu0ScaleVector(&o->v, o->xE0, sqrtf(sceVu0InnerProduct(&o->v, &o->v)));
    h = 1000.0f;
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
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}
