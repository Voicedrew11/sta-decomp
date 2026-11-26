#include "common.h"
typedef struct { Vec p; Vec v; u8 pad[0x90]; f32 fB0; f32 fB4; f32 fB8; f32 fBC; Mtx m; } O;
typedef struct { Vec r1; Vec r2; } Ax;
extern Vec D_001F2000;
extern Mtx D_001F2170;
extern Vec D_001F2140;
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
f32 fabsf(f32);
void func_00102CC8(Mtx *, Mtx *, f32);
void func_00102C20(Mtx *, Mtx *, f32);
void func_00102B78(Mtx *, Mtx *, f32);
void func_001027E0(Mtx *, Mtx *, Mtx *);
f32 sqrtf(f32);

#define WRAP(a) (((3.1415927f + (a)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (a)))) + ((3.1415927f + (a)) < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f)

void func_00148120(O *o, f32 dt) {
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

    spd = sqrtf(func_00102848(&o->v, &o->v));
    kE = 0.0125663718f * *(volatile f32 *)&o->fB8;
    kD = 18.849556f * *(volatile f32 *)&o->fB4;
    kB0 = o->fB0;
    func_00102870(&A, &o->v);
    B = D_001F2000;
    func_00102A18(&C, &B, dt);
    l = spd + sqrtf(func_00102848(&C, &C));
    d = func_00102848(&A, &o->m.m[1]);
    s = (0.0f < d) ? 1.0f : -1.0f;
    func_00102A18(&D, &o->m.m[1], -1.0f * s * (kB0 * (l * fabsf(d))));
    l = spd + sqrtf(func_00102848(&C, &C));
    d = func_00102848(&A, &o->m.m[2]);
    s = (0.0f < d) ? 1.0f : -1.0f;
    ry = s * (l * kE);
    d = func_00102848(&D_001F2140, &o->m.m[1]);
    s = (0.0f < d) ? -1.0f : 1.0f;
    rz = s * (kD * fabsf(d));
    func_001029D0(&o->v, &o->v, &C);
    func_001029D0(&o->v, &o->v, &D);
    func_00102A18(&E, &o->v, dt);
    func_001029D0(&o->p, &E, &o->p);
    rx = 0.0f;
    a = rx * dt;
    func_00102CC8(&M, &D_001F2170, WRAP(a));
    func_001027E0(&o->m, &o->m, &M);
    y = ry + rz;
    func_00102C20(&M, &D_001F2170, WRAP(y * dt));
    func_001027E0(&o->m, &o->m, &M);
    func_00102B78(&M, &D_001F2170, WRAP(a));
    func_001027E0(&o->m, &o->m, &M);
}


