#include "common.h"
typedef union { u128 q[4]; f32 f[16]; s32 w[16]; } M;
typedef struct { Vec a; Vec b; } Ray;
typedef struct { Vec p; Vec d; } Seg;
typedef union { u128 q[4]; struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; } s; } Res;
typedef struct { f32 v[3]; } V3;
typedef struct { u8 pad[4]; u8 a, b, c; Flags8 f7; u8 pad8[0x108]; f32 t[1][5]; } E;
typedef struct { u8 pad[0x210]; E *e[1]; } T;
typedef struct { u8 pad[0xC]; s32 xC; } C;
typedef struct { u8 pad[0xA]; u16 xA; u16 xC; u16 xE; } AI;
typedef struct { u8 pad[0x4B0]; AI *x4B0; } A;
typedef struct { Vec v; u8 pad10[0x80]; T *x90; u16 x94; u8 pad96[0x6A]; Vec x100; u8 pad110[4]; Flags8 x114; } O;
void Fx_GetWorldMatrix_1_00163C80(O *, Mtx *);
void sceVu0CopyVector(Vec *, Vec *);
void Seg_Init_1_001502A0(Ray *, Vec *, Vec *, f32);
C *Attack_GetParams_0_001D2C60(O *);
u8 Attack_GetCollFlags_0_001D2B80(C *);
s32 Map_RaycastCapsule_0_00145D10(Vec *, Vec *, u8, s32, M *);
s32 Map_RaycastNearest_0_00145840(Ray *, u8, s32, M *);
f32 Vec_Distance_3_00146940(M *, Vec *);
u8 Attack_GetHitMask_0_001D2A80(O *);
A *ActorList_NextB_0_001A5710(void);
A *ActorList_NextTargetable_0_001A5660(void);
s32 Attack_IsNull_1_001D2A70(A *);
s32 Attack_IsActive_0_001D2A40(A *);
s32 Attack_GetFlagB2_0_001D2A20(A *);
s32 Actor_CanTarget_0_0013BA90(T *, A *);
s32 Enemy_IsBusy_0_0013EE40(A *);
void Enemy_CopyPosition_2_00140470(A *, Vec *);
void Seg_ClosestPoints_3_00151B20(Res *, Ray *, Seg *);
s32 Attack_TestActor_0_001D2890(O *, A *, Ray *, Res *);
s32 Attack_Ricochet_0_001D31E0(O *, M *);
s32 Attack_SpawnHitEffect_1_001D2CB0(O *, A *, u8, Res *, s32);
extern Vec D_001F2140;
static inline f32 u2f(u32 x) { return x; }
static inline E *ent(T **t, u16 *i) { return (*t)->e[*i]; }
static inline u8 mask(O *o) {
    u8 m = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        C *c = Attack_GetParams_0_001D2C60(o) + i;
        if (c->xC) m |= Attack_GetCollFlags_0_001D2B80(c);
    }
    return m;
}

s32 Attack_TraceProjectile_0_001D22E0(O *o) {
    s32 ret;
    Ray ray;
    M best;
    Vec pos;
    M h2;
    M h1;
    Res bres;
    Mtx m;
    Vec v160;
    Res res;
    Seg seg;
    Res r;
    E *e;
    s32 i1;
    u8 m1;
    s32 r3;
    s32 i2;
    u16 *pi;
    T **pt;
    u8 m2;
    s32 h;
    f32 min;
    s32 idx;
    u8 fl;
    A *a;
    A *ba;

    pi = &o->x94;
    pt = &o->x90;
    if (!ent(pt, pi)->f7.f.b1) return 0;
    ret = 0;
    if (o->x114.f.b5) {
        Fx_GetWorldMatrix_1_00163C80(o, &m);
        sceVu0CopyVector(&pos, &m.m[3]);
    } else {
        sceVu0CopyVector(&pos, &o->v);
    }
    e = ent(pt, pi);
    Seg_Init_1_001502A0(&ray, &o->x100, &pos, (e->t[e->a] + e->b)[e->c * 3]);
    m1 = 0;
    for (i1 = 0; i1 < 4; i1++) {
        C *c = Attack_GetParams_0_001D2C60(o) + i1;
        if (c->xC) m1 |= Attack_GetCollFlags_0_001D2B80(c);
    }
    r3 = Map_RaycastCapsule_0_00145D10(&o->x100, &pos, m1, 0, &h2);
    m2 = 0;
    for (i2 = 0; i2 < 4; i2++) {
        C *c = Attack_GetParams_0_001D2C60(o) + i2;
        if (c->xC) m2 |= Attack_GetCollFlags_0_001D2B80(c);
    }
    h = Map_RaycastNearest_0_00145840(&ray, m2, 0, &h1);
    if (h && r3) {
        min = Vec_Distance_3_00146940(&h1, &o->x100);
        best = *(min < Vec_Distance_3_00146940(&h2, &o->x100) ? &h1 : &h2);
    } else if (r3) {
        best = h2;
    } else if (h) {
        best = h1;
    } else {
        best.w[9] = 0;
    }
    min = 5.0f;
    idx = -1;
    fl = Attack_GetHitMask_0_001D2A80(o);
    ba = 0;
    for (a = ActorList_NextB_0_001A5710(); a; a = ActorList_NextTargetable_0_001A5660()) {
        if (Attack_IsNull_1_001D2A70(a) && !(fl & 1)) continue;
        if (Attack_IsActive_0_001D2A40(a) && !(fl & 2)) continue;
        if (Attack_GetFlagB2_0_001D2A20(a) && !(fl & 8)) continue;
        if (!Actor_CanTarget_0_0013BA90(o->x90, a)) continue;
        if (Enemy_IsBusy_0_0013EE40(a)) continue;
        Enemy_CopyPosition_2_00140470(a, &v160);
        sceVu0CopyVector(&seg.p, &v160);
        seg.p.y -= u2f(a->x4B0->xE);
        seg.p.w = u2f(a->x4B0->xA);
        sceVu0CopyVector(&seg.d, &D_001F2140);
        seg.d.w = u2f(a->x4B0->xE);
        Seg_ClosestPoints_3_00151B20(&res, &ray, &seg);
        if (res.s.hit) {
            s32 k;
            r.s.hit = 0;
            k = Attack_TestActor_0_001D2890(o, a, &ray, &r);
            if (k != -1 && r.s.a.w < min) {
                idx = k;
                ba = a;
                min = r.s.a.w;
                bres = r;
            }
        }
    }
    if (idx != -1) {
        if (best.w[9] && best.f[3] < min) {
            if (Attack_Ricochet_0_001D31E0(o, &best)) ret = 1;
        } else {
            if (Attack_SpawnHitEffect_1_001D2CB0(o, ba, idx, &bres, 2)) ret = 1;
        }
    } else if (best.w[9]) {
        if (Attack_Ricochet_0_001D31E0(o, &best)) ret = 1;
    }
    return ret;
}
