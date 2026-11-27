#include "actor.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct { u8 pad[0x188]; Bits f188; } S90;
typedef struct { u8 pad[0x20]; f32 x20; u8 pad24[4]; f32 x28; u8 pad2C[0x14]; } Info;
typedef struct {
    Vec pos;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    u8 pad68[0x20];
    f32 x88;
    u8 pad8C[4];
    S90 *p90;
    u8 pad94[0x2C];
    u8 xC0[0x54];
    Bits f114;
} Obj;
void Actor_GetDirNormalized_0_00146570(Actor *, Vec *);
Actor *Proj_FindEnemyInCone_0_00146EF0(f32, s8 *, f32, Vec *, f32, s32);
void sceVu0CopyVector(void *, void *);
void Actor_GetYawPitch_1_00145F40(Actor *, f32 *, s32);
void Player_GetPos_1_001C9410(Vec *);
void sceVu0RotMatrixY(f32, Mtx *, void *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
s32 Map_LineTest_1_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);
void Actor_BuildRotMatrix_0_00146600(Actor *, Info *);
void Mtx_RotateToward_0_00146140(void *, f32, f32);
extern s8 D_001F2160[];
extern s32 D_001F2170[];
static inline f32 u2f(u32 x) { return x; }

void FxProc_AimAtEnemyCone_0_0014CAC0(Obj *a) {
    f32 ang;
    Vec p;
    Vec f;
    Vec e;
    Vec d;
    Mtx m;
    Info s;
    Vec lo;
    Vec hi;
    f32 x;
    f32 deg;
    s32 ok;
    s8 *base;
    f32 u;
    Actor *r;

    deg = 0.0f;
    x = a->x60;
    if (a->x64 != deg) {
        deg = 0.01745f * a->x64;
    }
    Actor_GetDirNormalized_0_00146570(D_002022E4, &f);
    ok = 0;
    if (D_002022E4 && D_002022E4->unk518) {
        ok = 1;
    }
    base = ok ? D_002022E4->unk518 + 0x1C0 : D_001F2160;
    r = Proj_FindEnemyInCone_0_00146EF0(x, base, 3.1415927f, &f, deg, 0);
    if (r) {
        sceVu0CopyVector(&p, r ? r->unk518 + 0x90 : D_001F2160);
    } else {
        sceVu0CopyVector(&e, &a->v50);
        e.w = 1.0f;
        Actor_GetYawPitch_1_00145F40(D_002022E4, &ang, 0);
        Player_GetPos_1_001C9410(&d);
        sceVu0RotMatrixY((3.1415927f + ang) - 6.2831855f * (f32)(s32)((3.1415927f + ang) * 0.15915494f) + ((3.1415927f + ang) < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f, &m, D_001F2170);
        sceVu0ApplyMatrix(&e, &m, &e);
        sceVu0AddVector(&e, &e, &d);
        sceVu0CopyVector(&p, &e);
    }
    hi.x = lo.x = p.x;
    u = 200.0f;
    lo.y = p.y - u;
    lo.z = p.z;
    lo.w = hi.w = 1.0f;
    hi.y = p.y + u;
    hi.z = p.z;
    if (Map_LineTest_1_001470F0(&lo, &hi, 1, 4, 1, &p)) {
        sceVu0CopyVector(a, &p);
        a->pos.y -= 5.0f;
        Actor_BuildRotMatrix_0_00146600(D_002022E4, &s);
        Mtx_RotateToward_0_00146140(a->xC0, s.x20, s.x28);
        return;
    }
    a->x88 = u2f(a->f114.b1 = 0);
    a->p90->f188.b2 = 0;
}
