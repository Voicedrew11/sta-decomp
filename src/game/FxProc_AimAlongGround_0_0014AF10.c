#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 pad[0x188]; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; } T;
typedef struct {
    u8 pad[0x50]; f32 x, y, z; u8 pad5C[0x2C]; f32 f88; u8 pad8C[4]; T *t; u8 pad94[0x80]; u8 b0 : 1; u8 b1 : 1;
} O;
typedef struct { f32 m[4][4]; } M;
extern s8 D_001F2160[];
extern M D_001F2170;
void Actor_GetYawPitch_1_00145F40(s32, f32 *, f32 *);
void sceVu0RotMatrixY(f32, M *, M *);
void sceVu0ApplyMatrix(f32 *, M *, f32 *);
void sceVu0AddVector(f32 *, f32 *, s8 *);
void sceVu0CopyMatrix(f32 *, s8 *);
void sceVu0CopyVector(void *, f32 *);
s32 Map_LineTest_1_001470F0(f32 *, f32 *, s32, s32, s32, s32 *);
void Actor_GetDirNormalized_0_00146570(Actor *, f32 *);
void Mtx_RotateToward_0_00146140(s32, f32, f32);
inline s32 has(void) {
    return D_002022E4 != NULL && D_002022E4->unk518 != NULL;
}

void FxProc_AimAlongGround_0_0014AF10(O *o) {
    f32 ang;
    s32 res[4];
    f32 v[4];
    M m;
    f32 a[4];
    f32 b[4];
    f32 w[4];

    v[0] = o->x;
    v[1] = o->y;
    v[2] = o->z;
    v[3] = 1.0f;
    Actor_GetYawPitch_1_00145F40((s32)D_002022E4, &ang, NULL);
    sceVu0RotMatrixY(WRAP(ang), &m, &D_001F2170);
    sceVu0ApplyMatrix(v, &m, v);
    sceVu0AddVector(v, v, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
    v[3] = 1.0f;
    sceVu0CopyMatrix(a, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
    sceVu0CopyVector(b, v);
    a[1] = a[1];
    if (Map_LineTest_1_001470F0(a, b, 1, 0x22, 1, res) != 0) {
        o->f88 = o->b1 = 0;
        o->t->b2 = 0;
    }
    sceVu0CopyVector(o, v);
    Actor_GetDirNormalized_0_00146570(D_002022E4, w);
    Mtx_RotateToward_0_00146140((s32)o + 0xC0, w[0], w[2]);
}
