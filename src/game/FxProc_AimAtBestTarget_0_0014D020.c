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
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[4];
    S90 *p90;
    u8 pad94[0x2C];
    Mtx xC0;
    u8 pad100[0x14];
    Bits f114;
} Obj;
Actor *Proj_FindBestTarget_0_001472A0(Obj *, f32, f32, s8 *, f32, s32);
void sceVu0CopyVector(void *, void *);
void sceVu0CopyMatrix(void *, void *);
void Actor_GetYawPitch_1_00145F40(Actor *, f32 *, s32);
void sceVu0RotMatrixY(f32, Mtx *, void *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
void sceVu0AddVector(Vec *, Vec *, void *);
s32 Map_LineTest_1_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);
void Actor_BuildRotMatrix_0_00146600(Actor *, Info *);
void Mtx_RotateToward_0_00146140(Mtx *, f32, f32);
extern s8 D_001F2150[];
extern s8 D_001F2160[];
extern s32 D_001F2170[];
static inline f32 u2f(u32 x) { return x; }

void FxProc_AimAtBestTarget_0_0014D020(Obj *a) {
    f32 ang;
    Vec p;
    Vec e;
    Mtx m;
    Vec hit;
    Vec lo;
    Vec hi;
    Info s;
    Mtx q;
    f32 dy;
    f32 deg;
    Actor *r;
    s32 ok;
    s32 ok2;
    f32 x;
    s8 *base;

    deg = 0.0f;
    x = a->x60;
    deg = (a->x64 != deg) ? 0.01745f * a->x64 : deg;
    dy = a->x68;
    base = D_002022E4 ? D_002022E4->unk518 + 0x20 : D_001F2150;
    r = Proj_FindBestTarget_0_001472A0(a, x, deg, base, 0.0f, 0);
    if (r) {
        sceVu0CopyVector(&p, r ? r->unk518 + 0x90 : D_001F2160);
    } else {
        sceVu0CopyVector(&e, &a->v50);
        e.w = 1.0f;
        Actor_GetYawPitch_1_00145F40(D_002022E4, &ang, 0);
        sceVu0RotMatrixY((3.1415927f + ang) - (f32)(s32)((3.1415927f + ang) * 0.15915494f) * 6.2831855f + ((3.1415927f + ang) < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f, &m, D_001F2170);
        sceVu0ApplyMatrix(&e, &m, &e);
        ok = 0;
        if (D_002022E4 && D_002022E4->unk518) {
            ok = 1;
        }
        sceVu0AddVector(&e, &e, ok ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
        sceVu0CopyVector(&p, &e);
    }
    ok2 = 0;
    if (D_002022E4 && D_002022E4->unk518) {
        ok2 = 1;
    }
    sceVu0CopyMatrix(&lo, ok2 ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
    sceVu0CopyVector(&hi, &p);
    hi.y += dy;
    if (Map_LineTest_1_001470F0(&lo, &hi, 1, 0x22, 0, &hit)) {
        a->x88 = u2f(a->f114.b1 = 0);
        a->p90->f188.b2 = 0;
    }
    sceVu0CopyVector(a, &hi);
    Actor_BuildRotMatrix_0_00146600(D_002022E4, &s);
    Mtx_RotateToward_0_00146140(&q, s.x20, s.x28);
    sceVu0CopyMatrix(&a->xC0, &q);
}
