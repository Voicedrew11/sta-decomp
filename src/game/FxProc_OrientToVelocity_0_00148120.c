#include "common.h"
typedef struct { Vec p; Vec v; u8 pad[0x90]; f32 fB0; f32 fB4; f32 fB8; f32 fBC; Mtx m; } O;
typedef struct { Vec r1; Vec r2; } Ax;
Vec D_001F2000 = { 0.0f, 980.0f };
extern Mtx D_001F2170;
extern Vec D_001F2140;
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
f32 fabsf(f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixZ(Mtx *, Mtx *, f32);
void sceVu0MulMatrix(Mtx *, Mtx *, Mtx *);
f32 sqrtf(f32);

#define WRAP(a) (((3.1415927f + (a)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (a)))) + ((3.1415927f + (a)) < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f)

void FxProc_OrientToVelocity_0_00148120(O *o, f32 dt) {
    Vec A;
    Vec D;
    Vec C;
    Vec B;
    Vec E;
    Mtx M;
    f32 spd;
    f32 rx;
    f32 d;
    f32 l;
    f32 s;
    f32 ry;
    f32 kB0;
    f32 rz;
    f32 a;
    f32 t;
    f32 y;
    f32 kE;
    f32 kD;

    spd = sqrtf(sceVu0InnerProduct(&o->v, &o->v));
    kE = 0.0125663718f * *(volatile f32 *)&o->fB8;
    kD = 18.849556f * *(volatile f32 *)&o->fB4;
    kB0 = o->fB0;
    sceVu0Normalize(&A, &o->v);
    B = D_001F2000;
    sceVu0ScaleVector(&C, &B, dt);
    l = spd + sqrtf(sceVu0InnerProduct(&C, &C));
    d = sceVu0InnerProduct(&A, &o->m.m[1]);
    s = (0.0f < d) ? 1.0f : -1.0f;
    sceVu0ScaleVector(&D, &o->m.m[1], -1.0f * s * (kB0 * (l * fabsf(d))));
    l = spd + sqrtf(sceVu0InnerProduct(&C, &C));
    d = sceVu0InnerProduct(&A, &o->m.m[2]);
    s = (0.0f < d) ? 1.0f : -1.0f;
    ry = s * (l * kE);
    d = sceVu0InnerProduct(&D_001F2140, &o->m.m[1]);
    s = (0.0f < d) ? -1.0f : 1.0f;
    rz = s * (kD * fabsf(d));
    sceVu0AddVector(&o->v, &o->v, &C);
    sceVu0AddVector(&o->v, &o->v, &D);
    sceVu0ScaleVector(&E, &o->v, dt);
    sceVu0AddVector(&o->p, &E, &o->p);
    rx = 0.0f;
    a = rx * dt;
    sceVu0RotMatrixY(&M, &D_001F2170, WRAP(a));
    sceVu0MulMatrix(&o->m, &o->m, &M);
    y = ry + rz;
    sceVu0RotMatrixX(&M, &D_001F2170, WRAP(y * dt));
    sceVu0MulMatrix(&o->m, &o->m, &M);
    sceVu0RotMatrixZ(&M, &D_001F2170, WRAP(a));
    sceVu0MulMatrix(&o->m, &o->m, &M);
}


