#include "actor.h"
#include "m2c.h"
#include "common.h"
typedef struct { u8 p:2; u8 v:1; } B2;
typedef struct {
    u8 pad0[0x60];
    f32 x60;
    f32 x64;
    u8 pad68[8];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    u8 pad80[8];
    f32 x88;
    u8 pad8C[4];
    u8 *x90;
    u8 pad94[0x1C];
    f32 xB0;
    u8 padB4[0x60];
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
} O_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct { u8 pad[0x30]; f32 v[4]; } M_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct { u8 pad[0x188]; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; } T_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct {
    u8 pad[0x50]; f32 x, y, z; u8 pad5C[0x2C]; f32 f88; u8 pad8C[4]; T_FxProc_SeekNearestEnemy_0_0014AB80 *t; u8 pad94[0x80]; u8 b0 : 1; u8 b1 : 1;
} O_FxProc_AimAlongGround_0_0014AF10;
typedef struct { f32 m[4][4]; } M_FxProc_AimAlongGround_0_0014AF10;
typedef struct { char pad[0xA8]; s32 a8; } T_FxProc_ReleaseChild_0_0014B170;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } Bits_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct { u128 q[4]; } Res;
typedef struct {
    Vec pos;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[4];
    f32 x74;
    u8 pad78[0x10];
    f32 x88;
    u8 pad8C[4];
    s32 x90;
    u8 pad94[0x14];
    s32 xA8;
    u8 padAC[4];
    f32 xB0;
    f32 xB4;
    f32 xB8;
    u8 padBC[4];
    u8 xC0[0x10];
    u8 xD0[0x44];
    Bits_FxProc_SeekNearestEnemy_0_0014AB80 f114;
} O;
typedef struct {
    char pad[0x5C]; f32 scale; char p60[4]; f32 v64; char p68[0x40];
    s32 a8; char pac[4]; f32 b0; f32 b4; f32 b8;
} Obj_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct { u8 b0 : 1; u8 b1 : 1; } BF;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[0x30];
    f32 v50[4];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[0x2C];
    f32 xB8;
    f32 xBC;
    u8 padC0[0x54];
    BF x114;
} Obj_FxProc_PullTowardEnemy_0_0014BA10;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits_FxProc_TrackEnemyBone_0_0014BC90;
typedef struct {
    Vec pos;
    u8 pad10[0x54];
    f32 x64;
    u8 pad68[0x50];
    f32 xB8;
    f32 xBC;
    u8 padC0[0x54];
    Bits_FxProc_TrackEnemyBone_0_0014BC90 f114;
} Obj;
extern s8 D_001F2160[];
extern M_FxProc_AimAlongGround_0_0014AF10 D_001F2170;
extern f32 D_001FB738[];
extern Mtx D_001F2170__as_FxProc_HomingProjectile_0_0014B1B0;
extern void *D_002022E4__as_FxProc_InitHoming_0_0014B9E0;
extern s32 **D_002022BC;
extern f32 D_001F2160__as_FxProc_PullTowardEnemy_0_0014BA10[];
void FxProc_SeekNearestEnemy_0_0014AB80(O_FxProc_SeekNearestEnemy_0_0014AB80 *o);
void FxProc_RandomRingPos_0_0014AD90(f32 *a0);
inline s32 has(void);
void FxProc_AimAlongGround_0_0014AF10(O_FxProc_AimAlongGround_0_0014AF10 *o);
void FxProc_ReleaseChild_0_0014B170(T_FxProc_ReleaseChild_0_0014B170 *arg0);
void FxProc_HomingProjectile_0_0014B1B0(O *o, f32 kk);
void FxProc_InitHoming_0_0014B9E0(Obj_FxProc_SeekNearestEnemy_0_0014AB80 *o);
void FxProc_PullTowardEnemy_0_0014BA10(Obj_FxProc_PullTowardEnemy_0_0014BA10 *a0);
void FxProc_TrackEnemyBone_0_0014BC90(Obj *a);
void sceVu0CopyVector(void*, void *);
Actor* Proj_FindNearestEnemy_0_00147450(f32, void *);
void Fx_GetWorldMatrix_1_00163C80(void *, void *);
s8* Player_GetPosition_1_00145730(void);
s32 Rand_Next_3_0015ED20(void);
f32 cosf(f32);
f32 sinf(f32);
void sceVu0AddVector(void *, void *, void *);
void Actor_GetYawPitch_1_00145F40(s32, f32 *, f32 *);
void sceVu0RotMatrixY(f32, void *, void *);
void sceVu0ApplyMatrix(f32 *, M_FxProc_AimAlongGround_0_0014AF10 *, f32 *);
void sceVu0CopyMatrix(void *, void *);
s32 Map_LineTest_1_001470F0(f32 *, f32 *, s32, s32, s32, s32 *);
void Actor_GetDirNormalized_0_00146570(Actor *, f32 *);
void Mtx_RotateToward_0_00146140(s32, f32, f32);
void sceVu0AddVector__as_FxProc_SeekNearestEnemy_0_0014AB80(f32 *, f32 *, f32 *);
void sceVu0AddVector__as_FxProc_AimAlongGround_0_0014AF10(f32 *, f32 *, s8 *);
void sceVu0CopyVector__as_FxProc_AimAlongGround_0_0014AF10(void *, f32 *);
void Sfx_RequestStop_1_00167240(s32);
void Actor_GetDir_1_001465C0(Actor *, Vec *);
Actor* Proj_FindEnemyInCone_0_00146EF0(f32, s8 *, f32, Vec *, f32, s32);
void Vec_GetYawPitchBetween_1_00146310(s8 *, Vec *, s8 *, f32 *, f32 *);
f32 fabsf(f32);
f32 atan2f(f32, f32);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0ScaleVector(void *, void *, f32);
s32 Map_RaycastCapsule_0_00145D10(O *, Vec *, s32, s32, Res *);
s32 Map_RaycastSegment_0_00145A80(O *, Vec *, s32, s32, Res *);
Actor* ActorList_NextB_0_001A5710(void);
Actor* ActorList_NextTargetable_0_001A5660(void);
s32 Proj_FindTarget_0_00146C70(O *, Vec *, Actor *, s32 *, Vec *, f32);
f32 Vec_Distance_3_00146940(void *, void *);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Proj_SpawnAttack_0_00146A70(s32, Actor *, u8, s32);
void Proj_SpawnFromSource_0_00146980(s32, Res *, s32);
void Sfx_SetPosition_1_00167710(s8 *, Vec *);
void sceVu0AddVector__as_FxProc_SeekNearestEnemy_0_0014AB80_(f32*, f32*, void *);
void sceVu0RotMatrixY__as_FxProc_SeekNearestEnemy_0_0014AB80_(f32, M_FxProc_AimAlongGround_0_0014AF10 *, M_FxProc_AimAlongGround_0_0014AF10 *);
void sceVu0CopyMatrix__as_FxProc_SeekNearestEnemy_0_0014AB80_(f32 *, s8 *);
void Actor_GetYawPitch_1_00145F40__as_FxProc_HomingProjectile_0_0014B1B0(Actor *, f32 *, s32);
void sceVu0RotMatrixY__as_FxProc_HomingProjectile_0_0014B1B0(f32, Mtx *, Mtx *);
void sceVu0CopyMatrix__as_FxProc_HomingProjectile_0_0014B1B0(void *, Mtx *);
void sceVu0AddVector__as_FxProc_HomingProjectile_0_0014B1B0(Vec *, Vec *, void *);
void Actor_GetYawPitch_1_00145F40__as_FxProc_InitHoming_0_0014B9E0(void *a, f32 *b, s32 c);
s8* ActorList_Next_2_001A5460(s32 *);
u32 Enemy_GetCurrentParamIdx_0_0013E110(void *);
void sceVu0SubVector(void *, void *, void *);
void EnemyScr_Event2015_1_00141510(s8 *, u8, s32, s32);
f32 sceVu0InnerProduct(f32 *, f32 *);
void sceVu0Normalize(f32 *, f32 *);
f32 sqrtf(f32);
void sceVu0ScaleVector__as_FxProc_SeekNearestEnemy_0_0014AB80__(Vec *, void *, f32);
void sceVu0AddVector__as_FxProc_PullTowardEnemy_0_0014BA10(f32 *, f32 *, f32 *);
f32 Vec_Distance_3_00146940__as_FxProc_PullTowardEnemy_0_0014BA10(Obj_FxProc_PullTowardEnemy_0_0014BA10 *, f32 *);
void sceVu0ScaleVector__as_FxProc_PullTowardEnemy_0_0014BA10(f32 *, f32 *, f32);
Vec* Enemy_Ptr6F0_1_0013FFA0(u16 *);

/* FxProc_SeekNearestEnemy_0_0014AB80___ */
#define Fx_GetWorldMatrix_1_00163C80 Fx_GetWorldMatrix_1_00163C80__as_FxProc_SeekNearestEnemy_0_0014AB80___
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_SeekNearestEnemy_0_0014AB80___(O_FxProc_SeekNearestEnemy_0_0014AB80 *, M_FxProc_SeekNearestEnemy_0_0014AB80 *);
#define Enemy_GetCurrentParamIdx_0_0013E110 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_SeekNearestEnemy_0_0014AB80___
u32 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_SeekNearestEnemy_0_0014AB80___(s8 *);
#define sceVu0SubVector sceVu0SubVector__as_FxProc_SeekNearestEnemy_0_0014AB80___
void sceVu0SubVector__as_FxProc_SeekNearestEnemy_0_0014AB80___(f32 *, f32 *, f32 *);

/* FxProc_SeekNearestEnemy_0_0014AB80__ */

/* FxProc_SeekNearestEnemy_0_0014AB80__ */
/* FxProc_SeekNearestEnemy_0_0014AB80_ */

/* FxProc_SeekNearestEnemy_0_0014AB80_ */
/* FxProc_SeekNearestEnemy_0_0014AB80 */

/* FxProc_SeekNearestEnemy_0_0014AB80 */
void FxProc_SeekNearestEnemy_0_0014AB80(O_FxProc_SeekNearestEnemy_0_0014AB80 *o) {
    Actor *a;
    s32 f;
    f32 pos[4];
    M_FxProc_SeekNearestEnemy_0_0014AB80 m;
    f32 t;

    f = 1;
    if (o->x60 == 0.0f) {
        f = 0;
    }
    if ((s32)o->x64 == 0) {
        if (o->b5) {
            Fx_GetWorldMatrix_1_00163C80(o, &m);
            sceVu0CopyVector(pos, m.v);
        } else {
            sceVu0CopyVector(pos, o);
        }
        a = Proj_FindNearestEnemy_0_00147450(1000.0f, pos);
    } else {
        a = D_002022E4;
    }
    if (a == NULL) {
        o->x88 = (f32)(u32)(o->b1 = 0);
        ((B2 *)(o->x90 + 0x188))->v = 0;
        return;
    }
    if (*(u16 *)a != 0) {
        sceVu0CopyVector(o, a != NULL ? a->unk518 + 0x90 : D_001F2160);
    } else {
        sceVu0CopyVector(o, D_002022E4 != NULL ? Player_GetPosition_1_00145730() : D_001F2160);
    }
    if (f != 0) {
        t = (f32)(u32)*(u16 *)(a->unk4B0 + 4) * o->x60;
        o->x70 = o->x74 = o->x78 = t;
        o->x7C = 1.0f;
        o->xB0 = t;
    }
}

/* FxProc_RandomRingPos_0_0014AD90 */
void FxProc_RandomRingPos_0_0014AD90(f32 *a0) {
    f32 v[4];
    f32 r = a0[0x50 / 4];
    f32 h = a0[0x54 / 4];
    f32 ang = 6.2831855f * (0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20() & 0xFFFF));
    r *= 0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20() & 0xFFFF);
    v[0] = r * cosf(ang);
    v[2] = r * sinf(ang);
    v[1] = h * (1.0f - 2.0f * (0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20() & 0xFFFF)));
    v[3] = 0.0f;
    sceVu0AddVector__as_FxProc_SeekNearestEnemy_0_0014AB80(a0, a0, v);
}

/* FxProc_AimAlongGround_0_0014AF10 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
inline s32 has(void) {
    return D_002022E4 != NULL && D_002022E4->unk518 != NULL;
}

void FxProc_AimAlongGround_0_0014AF10(O_FxProc_AimAlongGround_0_0014AF10 *o) {
    f32 ang;
    s32 res[4];
    f32 v[4];
    M_FxProc_AimAlongGround_0_0014AF10 m;
    f32 a[4];
    f32 b[4];
    f32 w[4];

    v[0] = o->x;
    v[1] = o->y;
    v[2] = o->z;
    v[3] = 1.0f;
    Actor_GetYawPitch_1_00145F40((s32)D_002022E4, &ang, NULL);
    sceVu0RotMatrixY__as_FxProc_SeekNearestEnemy_0_0014AB80_(WRAP(ang), &m, &D_001F2170);
    sceVu0ApplyMatrix(v, &m, v);
    sceVu0AddVector__as_FxProc_AimAlongGround_0_0014AF10(v, v, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
    v[3] = 1.0f;
    sceVu0CopyMatrix__as_FxProc_SeekNearestEnemy_0_0014AB80_(a, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
    sceVu0CopyVector__as_FxProc_AimAlongGround_0_0014AF10(b, v);
    a[1] = a[1];
    if (Map_LineTest_1_001470F0(a, b, 1, 0x22, 1, res) != 0) {
        o->f88 = o->b1 = 0;
        o->t->b2 = 0;
    }
    sceVu0CopyVector__as_FxProc_AimAlongGround_0_0014AF10(o, v);
    Actor_GetDirNormalized_0_00146570(D_002022E4, w);
    Mtx_RotateToward_0_00146140((s32)o + 0xC0, w[0], w[2]);
}

/* FxProc_ReleaseChild_0_0014B170 */
void FxProc_ReleaseChild_0_0014B170(T_FxProc_ReleaseChild_0_0014B170 *arg0) {
    volatile s32 sp2C;
    s32 v;

    sp2C = arg0->a8;
    v = sp2C;
    if (v != 0) {
        Sfx_RequestStop_1_00167240(v);
        arg0->a8 = 0;
    }
}

/* FxProc_HomingProjectile_0_0014B1B0 */
static inline f32 u2f_FxProc_SeekNearestEnemy_0_0014AB80(u32 x) { return x; }
static inline void spawn(s32 id, Vec *p) {
    s8 *q = Sfx_Spawn_2_00169B50(id, 0, 0, 0);
    if (q) Sfx_SetPosition_1_00167710(q, p);
}
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define BASE() ((D_002022E4 != NULL && D_002022E4->unk518 != NULL) ? D_002022E4->unk518 + 0x1C0 : D_001F2160)
static inline s8 *base(void) {
    s32 ok = 0;
    if (D_002022E4 && D_002022E4->unk518) ok = 1;
    return ok ? D_002022E4->unk518 + 0x1C0 : D_001F2160;
}

void FxProc_HomingProjectile_0_0014B1B0(O *o, f32 kk) {
    f32 ang;
    f32 k = kk;
    s32 cc;
    volatile s32 v198;
    volatile s32 v194;
    f32 ang190;
    f32 a18C;
    Mtx m;
    Res r100;
    Res rC0;
    Vec vB0;
    Vec vA0;
    Vec v90;
    Vec v80;
    Vec v70;
    Actor *r;

    f32 lim;
    f32 t;
    f32 d;
    s32 s3;
    s32 s2;
    s32 id;

    Actor *n;
    s32 ok;
    f32 w;
    f32 u;

    s8 *q;
    s8 *pos;

    Actor_GetDir_1_001465C0(D_002022E4, &v80);
    r = Proj_FindEnemyInCone_0_00146EF0(D_001FB738[0], base(), 1.5707964f, &v80, 1.5707964f, 1);
    if (r) {
        Actor_GetDir_1_001465C0(D_002022E4, &v70);
        Vec_GetYawPitchBetween_1_00146310(base(), &v70, r ? r->unk518 + 0x90 : D_001F2160, &ang190, NULL);
    } else {
        ang190 = 0.0f;
    }
    Actor_GetYawPitch_1_00145F40__as_FxProc_HomingProjectile_0_0014B1B0(D_002022E4, &a18C, 0);
    ang = ang190 + a18C;
    ang190 = ang;
    if (3.1415927f < fabsf(ang - o->xB4)) {
        if (ang < o->xB4) {
            w = 6.2831855f;
        } else {
            w = -6.2831855f;
        }
        ang += w;
    }
    ang -= o->xB4;
    u = o->v50.x ? 0.01745f * o->v50.x : 0.0f;


    lim = k * u;
    if (lim < fabsf(ang)) {
        ang = lim * (f32)(ang < 0.0f ? -1 : 1);
    }
    ang += o->xB4;
    o->xB4 = ang;
    t = o->x60;
    sceVu0CopyVector(o, base());
    o->pos.w = 1.0f;
    o->pos.y += o->v50.y;
    o->xB0 += t * k;
    t = atan2f(o->xB0, 190.0f);
    sceVu0RotMatrixX(&m, &D_001F2170__as_FxProc_HomingProjectile_0_0014B1B0, WRAP(t));
    sceVu0RotMatrixY__as_FxProc_HomingProjectile_0_0014B1B0(WRAP(ang), &m, &m);
    sceVu0CopyMatrix__as_FxProc_HomingProjectile_0_0014B1B0(o->xC0, &m);
    sceVu0ScaleVector__as_FxProc_SeekNearestEnemy_0_0014AB80__(&vB0, o->xD0, 10000.0f);
    sceVu0AddVector__as_FxProc_HomingProjectile_0_0014B1B0(&vB0, &vB0, o);
    s3 = Map_RaycastCapsule_0_00145D10(o, &vB0, 6, 0, &rC0);
    if (s3) {
        sceVu0CopyVector(&vB0, &rC0);
        vB0.w = 1.0f;
    }
    s2 = Map_RaycastSegment_0_00145A80(o, &vB0, 0xFF, 0, &r100);
    if (s2) {
        sceVu0CopyVector(&vB0, &r100);
        vB0.w = 1.0f;
    }
    d = o->v50.z;
    for (n = ActorList_NextB_0_001A5710(); n != NULL; n = ActorList_NextTargetable_0_001A5660()) {
        if (*(u16 *)n && Proj_FindTarget_0_00146C70(o, &vB0, n, &cc, &vA0, d)) {
            ok = 1;
            goto found;
        }
    }
    cc = 0;
    n = NULL;
    ok = 0;
found:
    if (ok) {
        sceVu0CopyVector(&vB0, &vA0);
    }
    if (!s2 && !ok && !s3) {
        o->x88 = u2f_FxProc_SeekNearestEnemy_0_0014AB80(o->f114.b1 = 0);
        return;
    }
    d = o->xB8;
    t = Vec_Distance_3_00146940(o, &vB0);
    if (1.5f * d < t) {
        o->x88 = u2f_FxProc_SeekNearestEnemy_0_0014AB80(o->f114.b1 = 0);
        return;
    }
    o->xB8 = t;
    if (o->xA8 == 0) {
        v198 = (s32)Sfx_Spawn_2_00169B50((s32)o->x68, 0, 0, 0);
        o->xA8 = v198;
    }
    if (ok) {
        id = (u32)o->x6C;
        Proj_SpawnAttack_0_00146A70(o->x90, n, cc, 0x2B);
        if (id) {
            spawn(id, (Vec *)(n ? n->unk518 + 0x90 : D_001F2160));
        }
        o->x88 = u2f_FxProc_SeekNearestEnemy_0_0014AB80(o->f114.b1 = 0);
        return;
    }
    if (s2 || s3) {
        if (s2) {
            Proj_SpawnFromSource_0_00146980(o->x90, &r100, 0x2B);
            sceVu0CopyVector(&v90, &r100);
            v90.w = 1.0f;
            spawn(0x2D, &v90);
            o->x88 = u2f_FxProc_SeekNearestEnemy_0_0014AB80(o->f114.b1 = 0);
        } else {
            sceVu0CopyVector(&v90, &rC0);
            v90.w = 1.0f;
        }
        if (o->xA8) {
            v194 = o->xA8;
            Sfx_SetPosition_1_00167710((s8 *)v194, &v90);
        }
        o->x74 = Vec_Distance_3_00146940(&v90, o);
    }
}

/* FxProc_InitHoming_0_0014B9E0 */

void FxProc_InitHoming_0_0014B9E0(Obj_FxProc_SeekNearestEnemy_0_0014AB80 *o)
{
    o->scale = 1.0f;
    o->b0 = o->v64;
    o->b8 = 100000.0f;
    o->a8 = 0;
    Actor_GetYawPitch_1_00145F40__as_FxProc_InitHoming_0_0014B9E0(D_002022E4__as_FxProc_InitHoming_0_0014B9E0, &o->b4, 0);
}

/* FxProc_PullTowardEnemy_0_0014BA10 */
#define POS(p) ((p) ? (f32 *)(*(s32 *)((p) + 0x518) + 0x90) : D_001F2160__as_FxProc_PullTowardEnemy_0_0014BA10)
static inline s8 *find(u16 id) {
    s32 it;
    s8 *p;
    it = 0;
    for (p = ActorList_Next_2_001A5460(&it); p != NULL; p = ActorList_Next_2_001A5460(&it)) {
        if (*(u16 *)p != 0 && (u16)Enemy_GetCurrentParamIdx_0_0013E110(p) == id) return p;
    }
    return NULL;
}
static inline s32 ok(void) {
    return D_002022BC != NULL && *D_002022BC != NULL;
}

void FxProc_PullTowardEnemy_0_0014BA10(Obj_FxProc_PullTowardEnemy_0_0014BA10 *a0) {
    f32 c[4];
    f32 b[4];
    f32 a[4];
    s8 *p;
    s32 id;
    f32 x60 = a0->x60;
    f32 x68 = a0->x68;
    f32 bc;
    f32 len;

    id = (u16)(u32)a0->xB8;
    if (id != 0) {
        p = find(id);
    } else {
        p = NULL;
    }
    if (p != NULL) {
        sceVu0AddVector__as_FxProc_PullTowardEnemy_0_0014BA10(c, POS(p), a0->v50);
        c[3] = 1.0f;
        if (Vec_Distance_3_00146940__as_FxProc_PullTowardEnemy_0_0014BA10(a0, c) < x68) {
            EnemyScr_Event2015_1_00141510(p, ok() ? **D_002022BC : 0, 3, 0);
            a0->x88 = (f32)(u32)(a0->x114.b1 = 0);
        }
        bc = a0->xBC;
        sceVu0SubVector(b, c, (f32 *)a0);
        len = sqrtf(sceVu0InnerProduct(a0->v10, a0->v10));
        sceVu0Normalize(a, b);
        sceVu0ScaleVector__as_FxProc_PullTowardEnemy_0_0014BA10(a, a, -1.0f * bc);
        sceVu0AddVector__as_FxProc_PullTowardEnemy_0_0014BA10(a0->v10, a0->v10, a);
        sceVu0Normalize(a0->v10, a0->v10);
        sceVu0ScaleVector__as_FxProc_PullTowardEnemy_0_0014BA10(a0->v10, a0->v10, len);
        a0->xBC -= x60;
    }
}
#undef Fx_GetWorldMatrix_1_00163C80
#undef Enemy_GetCurrentParamIdx_0_0013E110
#undef sceVu0SubVector

/* FxProc_TrackEnemyBone_0_0014BC90 */
#define ActorList_Next_2_001A5460 ActorList_Next_2_001A5460__as_FxProc_TrackEnemyBone_0_0014BC90
u16 *ActorList_Next_2_001A5460__as_FxProc_TrackEnemyBone_0_0014BC90(s32 *);
#define Enemy_GetCurrentParamIdx_0_0013E110 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_TrackEnemyBone_0_0014BC90
u32 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_TrackEnemyBone_0_0014BC90(u16 *);
#define Fx_GetWorldMatrix_1_00163C80 Fx_GetWorldMatrix_1_00163C80__as_FxProc_TrackEnemyBone_0_0014BC90
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_TrackEnemyBone_0_0014BC90(Obj *, Mtx *);
#define sceVu0SubVector sceVu0SubVector__as_FxProc_TrackEnemyBone_0_0014BC90
void sceVu0SubVector__as_FxProc_TrackEnemyBone_0_0014BC90(Vec *, Vec *, Vec *);
static inline f32 u2f_FxProc_TrackEnemyBone_0_0014BC90(u32 x) { return x; }

void FxProc_TrackEnemyBone_0_0014BC90(Obj *a) {
    s32 it;
    Vec d;
    Vec t;
    Vec s;
    Mtx m;
    u16 id;
    u16 *p;
    f32 k;
    f32 r;

    r = 0.05f;
    id = a->x64;
    it = 0;
    for (p = ActorList_Next_2_001A5460(&it); p != 0; p = ActorList_Next_2_001A5460(&it)) {
        if (*p != 0 && *p == id) break;
    }
    if (p) {
        a->xB8 = u2f_FxProc_TrackEnemyBone_0_0014BC90(Enemy_GetCurrentParamIdx_0_0013E110(p));
    } else {
        a->xB8 = 0.0f;
    }
    if (p) {
        sceVu0CopyVector(&t, Enemy_Ptr6F0_1_0013FFA0(p));
        if (a->f114.b5) {
            Fx_GetWorldMatrix_1_00163C80(a, &m);
            sceVu0CopyVector(&s, &m.m[3]);
        } else {
            sceVu0CopyVector(&s, a);
        }
        sceVu0SubVector(&d, &t, &s);

        k = (r - sqrtf(d.x * d.x + d.z * d.z)) / (2.0f * (f32)r);
        k *= 0.001f;
    } else {
        k = 0.0f;
    }
    a->xBC = k;
}
#undef ActorList_Next_2_001A5460
#undef Enemy_GetCurrentParamIdx_0_0013E110
#undef Fx_GetWorldMatrix_1_00163C80
#undef sceVu0SubVector
