#include "common.h"
#include "actor.h"
#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; } F;
typedef struct { u8 pad[4]; f32 x4; u8 pad8[0x58]; f32 x60; u8 pad64[0x24]; f32 x88; u8 pad8c[0x28]; f32 xB4; u8 xB0p[4]; f32 xBC; u8 padc0[0x54]; F x114; } O_FxProc_SpawnTimed_0_0014BE70;
typedef struct { char pad[0x50]; f32 x, y, z; char p5c[0x64]; f32 m[3][4]; f32 v[4]; } Obj_FxProc_SpawnTimed_0_0014BE70;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    f32 x54;
    f32 x58;
    u8 pad5C[4];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[0x34];
    u8 xC0[0x54];
    Bits f114;
} O_FxProc_RandomWander_0_0014C160;
typedef struct { u8 pad[0x2A]; u16 f; u8 pad2C[0x80]; f32 xAC; } P;
typedef struct { u8 pad[0x210]; P *tbl[1]; } Q;
typedef struct {
    u8 pad0[0x4C];
    f32 x4C;
    u8 pad50[0x10];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[0x20];
    Q *x90;
    u16 x94;
    u8 pad96[0x7E];
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
} O_FxProc_SpawnTimed_0_0014BE70_;
typedef struct { u8 pad[0x30]; f32 v[4]; } M_FxProc_SpawnTimed_0_0014BE70_;
typedef struct {
    char pad[0x114];
    unsigned char : 3;
    unsigned char f : 1;
} Obj_FxProc_SetDone_0_0014C870;
typedef struct { u8 pad[0x10]; f32 pos[3]; u8 pad1C[0x14]; f32 rot[3]; f32 rz; u8 pad40[0x20]; f32 range[3]; f32 ang; } O_FxProc_RandomJitter_0_0014C890;
typedef struct { f32 m[4][4]; } M_FxProc_RandomJitter_0_0014C890_;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits_FxProc_RandomJitter_0_0014C890;
typedef struct { u8 pad[0x188]; Bits_FxProc_RandomJitter_0_0014C890 f188; } S90_FxProc_RandomJitter_0_0014C890;
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
    S90_FxProc_RandomJitter_0_0014C890 *p90;
    u8 pad94[0x2C];
    u8 xC0[0x54];
    Bits_FxProc_RandomJitter_0_0014C890 f114;
} Obj_FxProc_RandomJitter_0_0014C890;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:6; } Bits_FxProc_StopAtWall_0_0014CDC0;
typedef struct {
    Vec p;
    u8 pad10[0x54];
    f32 x64;
    u8 pad68[0x20];
    f32 x88;
    u8 pad8C[0x88];
    Bits_FxProc_StopAtWall_0_0014CDC0 f114;
} O_FxProc_StopAtWall_0_0014CDC0;
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
} O_FxProc_RandomJitter_0_0014C890_;
typedef struct { u8 pad[0x188]; Bits f188; } S90_FxProc_AimAtBestTarget_0_0014D020;
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
    S90_FxProc_AimAtBestTarget_0_0014D020 *p90;
    u8 pad94[0x2C];
    Mtx xC0;
    u8 pad100[0x14];
    Bits f114;
} Obj_FxProc_AimAtBestTarget_0_0014D020;
extern f32 D_001F2160[4];
extern Mtx D_001F2170;
extern void *D_002022E4__as_FxProc_SpawnTimed_0_0014BE70;
extern s8 D_001F2160__as_FxProc_ScaleByDistance_0_0014C6F0[];
extern s8 D_001F2150[];
void FxProc_SpawnTimed_0_0014BE70(O_FxProc_SpawnTimed_0_0014BE70 *o);
void FxProc_SnapToGround_0_0014BF60(f32 *o);
void FxProc_AttachRotated_0_0014C060(Obj_FxProc_SpawnTimed_0_0014BE70 *o);
void FxProc_AttachRotatedB_0_0014C0E0(Obj_FxProc_SpawnTimed_0_0014BE70 *o);
void FxProc_RandomWander_0_0014C160(O_FxProc_RandomWander_0_0014C160 *o);
inline s32 has(void);
void FxProc_ScaleByDistance_0_0014C6F0(O_FxProc_SpawnTimed_0_0014BE70_ *o);
void FxProc_SetDone_0_0014C870(Obj_FxProc_SetDone_0_0014C870 *o);
void FxProc_RandomJitter_0_0014C890(O_FxProc_RandomJitter_0_0014C890 *o);
void FxProc_AimAtEnemyCone_0_0014CAC0(Obj_FxProc_RandomJitter_0_0014C890 *a);
void FxProc_StopAtWall_0_0014CDC0(O_FxProc_StopAtWall_0_0014CDC0 *o);
void FxProc_SlideOnSurface_0_0014CEC0(O_FxProc_RandomJitter_0_0014C890_ *o);
void FxProc_AimAtBestTarget_0_0014D020(Obj_FxProc_AimAtBestTarget_0_0014D020 *a);
s32 Sfx_IsLoaded_2_00169BB0(s32);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetPosition_1_00167710(s8 *, void *);
s32 Map_LineTest_1_001470F0(Vec *, Vec *, s32, u8, s32, Vec *);
void Actor_BuildRotMatrix_0_00146600(void *a, f32 (*m)[4]);
void sceVu0ApplyMatrix(f32 *out, f32 (*m)[4], f32 *v);
void sceVu0CopyMatrix(f32 (*m0)[4], f32 (*m1)[4]);
void sceVu0CopyVector(void *, void *);
u16 Rand_Next_3_0015ED20(void);
void sceVu0RotMatrixZ(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
s32 Map_LineTest_1_001470F0__as_FxProc_RandomWander_0_0014C160(Vec *, Vec *, s32, s32, s32, O_FxProc_RandomWander_0_0014C160 *);
void sceVu0CopyMatrix__as_FxProc_RandomWander_0_0014C160(void *, Mtx *);
void Fx_GetWorldMatrix_1_00163C80(void *, void *);
f32 Vec_Distance_3_00146940(f32 *, s8 *);
void sceVu0CopyVector__as_FxProc_SpawnTimed_0_0014BE70(f32 *v0, f32 *v1);
void Actor_GetDirNormalized_0_00146570(Actor *, Vec *);
Actor* Proj_FindEnemyInCone_0_00146EF0(f32, s8 *, f32, Vec *, f32, s32);
void Actor_GetYawPitch_1_00145F40(Actor *, f32 *, s32);
void Player_GetPos_1_001C9410(Vec *);
void sceVu0AddVector(Vec*, Vec*, void *);
void Mtx_RotateToward_0_00146140(void *, f32, f32);
void sceVu0ApplyMatrix__as_FxProc_RandomJitter_0_0014C890(f32 *, M_FxProc_RandomJitter_0_0014C890_ *, f32 *);
void sceVu0ApplyMatrix__as_FxProc_AimAtEnemyCone_0_0014CAC0(Vec *, Mtx *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(float);
void Mtx_RotateToward_0_00146140__as_FxProc_SlideOnSurface_0_0014CEC0(Vec *, f32, f32);
Actor* Proj_FindBestTarget_0_001472A0(Obj_FxProc_AimAtBestTarget_0_0014D020 *, f32, f32, s8 *, f32, s32);
void sceVu0AddVector__as_FxProc_RandomJitter_0_0014C890_(Vec *, Vec *, Vec *);
void sceVu0ApplyMatrix__as_FxProc_AimAtBestTarget_0_0014D020(Vec *, Mtx *, Vec *);
void Mtx_RotateToward_0_00146140__as_FxProc_AimAtBestTarget_0_0014D020(Mtx *, f32, f32);

/* FxProc_SpawnTimed_0_0014BE70_ */
#define Fx_GetWorldMatrix_1_00163C80 Fx_GetWorldMatrix_1_00163C80__as_FxProc_SpawnTimed_0_0014BE70_
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_SpawnTimed_0_0014BE70_(O_FxProc_SpawnTimed_0_0014BE70_ *, M_FxProc_SpawnTimed_0_0014BE70_ *);

/* FxProc_SpawnTimed_0_0014BE70_ */
/* FxProc_SpawnTimed_0_0014BE70 */

/* FxProc_SpawnTimed_0_0014BE70 */
/* FxProc_SpawnTimed_0_0014BE70 */
/* FxProc_SpawnTimed_0_0014BE70 */
/* FxProc_SpawnTimed_0_0014BE70 */
static inline f32 u2f_FxProc_SpawnTimed_0_0014BE70(u32 x) { return x; }

void FxProc_SpawnTimed_0_0014BE70(O_FxProc_SpawnTimed_0_0014BE70 *o) {
    s32 id;
    s8 *p;
    if (o->xBC && o->xB4 < o->x4) {
        id = o->x60;
        o->x88 = u2f_FxProc_SpawnTimed_0_0014BE70(o->x114.b1 = 0);
        if (Sfx_IsLoaded_2_00169BB0(id)) {
            p = Sfx_Spawn_2_00169B50(id, 0, 0, 0);
            if (p) Sfx_SetPosition_1_00167710(p, (u8 *)o + 0xB0);
        }
    }
}

/* FxProc_SnapToGround_0_0014BF60 */
void FxProc_SnapToGround_0_0014BF60(f32 *o) {
    s32 fl;
    Vec a;
    Vec b;
    f32 z;
    fl = 0;
    if (o[0x19] == 0.0f) fl = 0x80;
    if (o[0x19] == 1.0f) fl = 4;
    if (o[0x19] == 2.0f) fl = 0x84;
    z = 0.0f;
    a.x = o[0];
    a.y = o[1] - z;
    a.z = o[2];
    b.x = o[0];
    b.y = o[1] + (z = 10000.0f);
    b.z = o[2];
    b.w = 1.0f;
    a.w = 1.0f;
    o[0x2F] = Map_LineTest_1_001470F0(&a, &b, 1, fl, 1, (Vec *)(o + 0x2C));
}

/* FxProc_AttachRotated_0_0014C060 */
void FxProc_AttachRotated_0_0014C060(Obj_FxProc_SpawnTimed_0_0014BE70 *o)
{
    f32 m[4][4];
    f32 v[4];
    v[0] = o->x;
    v[1] = o->y;
    v[2] = o->z;
    v[3] = 1.0f;
    Actor_BuildRotMatrix_0_00146600(D_002022E4__as_FxProc_SpawnTimed_0_0014BE70, m);
    sceVu0ApplyMatrix((f32 *)o, m, v);
    sceVu0CopyMatrix(o->m, m);
    sceVu0CopyVector__as_FxProc_SpawnTimed_0_0014BE70(o->v, D_001F2160);
}

/* FxProc_AttachRotatedB_0_0014C0E0 */
void FxProc_AttachRotatedB_0_0014C0E0(Obj_FxProc_SpawnTimed_0_0014BE70 *o)
{
    f32 m[4][4];
    f32 v[4];
    v[0] = o->x;
    v[1] = o->y;
    v[2] = o->z;
    v[3] = 1.0f;
    Actor_BuildRotMatrix_0_00146600(D_002022E4__as_FxProc_SpawnTimed_0_0014BE70, m);
    sceVu0ApplyMatrix((f32 *)o, m, v);
    sceVu0CopyMatrix(o->m, m);
    sceVu0CopyVector__as_FxProc_SpawnTimed_0_0014BE70(o->v, D_001F2160);
}

/* FxProc_RandomWander_0_0014C160 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 u2f_FxProc_RandomWander_0_0014C160(u32 x) { return x; }

void FxProc_RandomWander_0_0014C160(O_FxProc_RandomWander_0_0014C160 *o) {
    Mtx m;
    Vec lo;
    Vec hi;
    s32 ok;
    f32 up;
    f32 dn;
    f32 a;
    f32 rx;

    o->p.x += o->x50 * ((0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20()) - 0.5f);
    o->p.z += o->x58 * ((0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20()) - 0.5f);
    if (o->x68) {
        ok = 1;
    } else {
        up = (0.0f < o->x64) ? o->x64 : 1000.0f;
        dn = (0.0f < o->x64) ? o->x64 : 1000.0f;
        lo.x = o->p.x;
        lo.y = o->p.y - dn;
        lo.z = o->p.z;
        hi.x = o->p.x;
        hi.y = o->p.y + up;
        hi.z = o->p.z;
        hi.w = 1.0f;
        lo.w = 1.0f;
        ok = Map_LineTest_1_001470F0__as_FxProc_RandomWander_0_0014C160(&lo, &hi, 3, 4, 1, o);
    }
    o->p.y += o->x54;
    if (!ok) {
        o->x88 = u2f_FxProc_RandomWander_0_0014C160(o->f114.b1 = 0);
        return;
    }
    rx = 0.0f;
    if (rx == o->x60) return;
    rx = (o->x60 != rx) ? 0.01745f * o->x60 : rx;
    a = 0.5f * rx;
    sceVu0RotMatrixZ(&m, &D_001F2170, WRAP(a * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20())));
    sceVu0RotMatrixY(&m, &m, WRAP(6.2831855f * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20())));
    sceVu0CopyMatrix__as_FxProc_RandomWander_0_0014C160(o->xC0, &m);
}

/* FxProc_ScaleByDistance_0_0014C6F0 */
inline s32 has(void) {
    return D_002022E4 != NULL && D_002022E4->unk518 != NULL;
}

void FxProc_ScaleByDistance_0_0014C6F0(O_FxProc_SpawnTimed_0_0014BE70_ *o) {
    f32 a, b, c, d;
    f32 pos[4];
    M_FxProc_SpawnTimed_0_0014BE70_ m;
    f32 t;
    P *p;

    a = o->x60;
    b = o->x64;
    c = o->x68;
    d = o->x6C;
    if (o->b5) {
        Fx_GetWorldMatrix_1_00163C80(o, &m);
        sceVu0CopyVector(pos, m.v);
    } else {
        sceVu0CopyVector(pos, o);
    }
    t = Vec_Distance_3_00146940(pos, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160__as_FxProc_ScaleByDistance_0_0014C6F0);
    if (c < t) {
        a = a;
    } else if (t < d) {
        a = b;
    } else {
        a = b + (a - b) * (t - d) / (c - d);
    }
    p = o->x90->tbl[o->x94];
    if (p->f & 0x10) {
        o->x4C = o->x4C * a;
    } else {
        o->x4C = a * p->xAC;
    }
    if (127.0f < o->x4C) {
        o->x4C = 127.0f;
    }
}

/* FxProc_SetDone_0_0014C870 */
/* Bitfield setter on an object's flag byte at 0x114. */


void FxProc_SetDone_0_0014C870(Obj_FxProc_SetDone_0_0014C870 *o)
{
    o->f = 1;
}
#undef Fx_GetWorldMatrix_1_00163C80

/* FxProc_RandomJitter_0_0014C890__ */
#define D_001F2160 D_001F2160__as_FxProc_RandomJitter_0_0014C890__
extern s8 D_001F2160__as_FxProc_RandomJitter_0_0014C890__[];
#define D_001F2170 D_001F2170__as_FxProc_RandomJitter_0_0014C890__
extern s32 D_001F2170__as_FxProc_RandomJitter_0_0014C890__[];
#define Rand_Next_3_0015ED20 Rand_Next_3_0015ED20__as_FxProc_RandomJitter_0_0014C890__
u32 Rand_Next_3_0015ED20__as_FxProc_RandomJitter_0_0014C890__(void);
#define Fx_GetWorldMatrix_1_00163C80 Fx_GetWorldMatrix_1_00163C80__as_FxProc_RandomJitter_0_0014C890__
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_RandomJitter_0_0014C890__(O_FxProc_RandomJitter_0_0014C890 *, M_FxProc_RandomJitter_0_0014C890_ *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_FxProc_RandomJitter_0_0014C890__
void sceVu0ApplyMatrix__as_FxProc_RandomJitter_0_0014C890__(void *, void *, void *);
#define sceVu0RotMatrixY sceVu0RotMatrixY__as_FxProc_RandomJitter_0_0014C890__
void sceVu0RotMatrixY__as_FxProc_RandomJitter_0_0014C890__(f32, Mtx *, void *);
#define Map_LineTest_1_001470F0 Map_LineTest_1_001470F0__as_FxProc_RandomJitter_0_0014C890__
s32 Map_LineTest_1_001470F0__as_FxProc_RandomJitter_0_0014C890__(Vec *, Vec *, s32, s32, s32, Vec *);
#define Actor_BuildRotMatrix_0_00146600 Actor_BuildRotMatrix_0_00146600__as_FxProc_RandomJitter_0_0014C890__
void Actor_BuildRotMatrix_0_00146600__as_FxProc_RandomJitter_0_0014C890__(Actor *, Info *);
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_FxProc_RandomJitter_0_0014C890__
void sceVu0CopyMatrix__as_FxProc_RandomJitter_0_0014C890__(void *, void *);

/* FxProc_RandomJitter_0_0014C890_ */

/* FxProc_RandomJitter_0_0014C890_ */
/* FxProc_RandomJitter_0_0014C890_ */
/* FxProc_RandomJitter_0_0014C890 */

static inline f32 sc(f32 x) { return x ? 0.01745f * x : 0.0f; }
void FxProc_RandomJitter_0_0014C890(O_FxProc_RandomJitter_0_0014C890 *o) {
    f32 v[4];
    M_FxProc_RandomJitter_0_0014C890_ m;
    s32 i;

    f32 *r;
    f32 *q;
    f32 *p;

    p = v;
    q = p;
    r = (f32 *)o;
    for (i = 0; i < 3; i++) {
        *q++ = r[0x18] * (0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF) - 0.5f);
        r++;
    }
    v[3] = 0.0f;
    Fx_GetWorldMatrix_1_00163C80(o, &m);
    sceVu0ApplyMatrix__as_FxProc_RandomJitter_0_0014C890(v, &m, v);
    o->pos[0] += p[0];
    o->pos[1] += v[1];
    o->pos[2] += v[2];
    if (o->ang != -1.0f) {
        for (i = 0; i < 3; i++) {
            o->rot[i] = 0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF);
        }
        o->rz += (0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF) - 0.5f) * sc(o->ang);
    }
}

/* FxProc_AimAtEnemyCone_0_0014CAC0 */
static inline f32 u2f_FxProc_RandomJitter_0_0014C890(u32 x) { return x; }

void FxProc_AimAtEnemyCone_0_0014CAC0(Obj_FxProc_RandomJitter_0_0014C890 *a) {
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
        sceVu0ApplyMatrix__as_FxProc_AimAtEnemyCone_0_0014CAC0(&e, &m, &e);
        sceVu0AddVector__as_FxProc_RandomJitter_0_0014C890_(&e, &e, &d);
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
    a->x88 = u2f_FxProc_RandomJitter_0_0014C890(a->f114.b1 = 0);
    a->p90->f188.b2 = 0;
}

/* FxProc_StopAtWall_0_0014CDC0 */
void FxProc_StopAtWall_0_0014CDC0(O_FxProc_StopAtWall_0_0014CDC0 *o) {
    Vec out;
    Vec a;
    Vec b;
    f32 h = o->x64;

    a.x = o->p.x;
    a.y = o->p.y - h;
    a.z = o->p.z;
    b.x = o->p.x;
    b.y = o->p.y + h;
    b.z = o->p.z;
    b.w = 1.0f;
    a.w = 1.0f;
    if (Map_LineTest_1_001470F0(&a, &b, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
        return;
    }
    o->x88 = (f32)(u32)(o->f114.b1 = 0);
}

/* FxProc_SlideOnSurface_0_0014CEC0 */

void FxProc_SlideOnSurface_0_0014CEC0(O_FxProc_RandomJitter_0_0014C890_ *o) {
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
        Mtx_RotateToward_0_00146140__as_FxProc_SlideOnSurface_0_0014CEC0(&o->c0, o->xE0, o->xE8);
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}

/* FxProc_AimAtBestTarget_0_0014D020 */
static inline f32 u2f_FxProc_AimAtBestTarget_0_0014D020(u32 x) { return x; }

void FxProc_AimAtBestTarget_0_0014D020(Obj_FxProc_AimAtBestTarget_0_0014D020 *a) {
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
        sceVu0ApplyMatrix__as_FxProc_AimAtBestTarget_0_0014D020(&e, &m, &e);
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
        a->x88 = u2f_FxProc_AimAtBestTarget_0_0014D020(a->f114.b1 = 0);
        a->p90->f188.b2 = 0;
    }
    sceVu0CopyVector(a, &hi);
    Actor_BuildRotMatrix_0_00146600(D_002022E4, &s);
    Mtx_RotateToward_0_00146140__as_FxProc_AimAtBestTarget_0_0014D020(&q, s.x20, s.x28);
    sceVu0CopyMatrix(&a->xC0, &q);
}
#undef Rand_Next_3_0015ED20
#undef Fx_GetWorldMatrix_1_00163C80
#undef sceVu0ApplyMatrix
#undef sceVu0RotMatrixY
#undef Map_LineTest_1_001470F0
#undef Actor_BuildRotMatrix_0_00146600
#undef sceVu0CopyMatrix
#undef D_001F2160
#undef D_001F2170
