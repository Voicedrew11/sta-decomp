#include "common.h"
#include "m2c.h"
#include "actor.h"
typedef struct { u8 pad[0x10]; Vec v; u8 p2[0x68]; f32 x88; u8 p3[0x1C]; s32 xA8; u8 p4[0xC]; f32 xB8; } O_FxProc_InitChase_0_001493E0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } Bits;
typedef struct { u16 x0; u8 pad2[2]; u8 x4; u8 x5; u8 x6; Bits x7; u8 pad8[0x74 - 8]; u8 x74[4]; f32 x78; u8 pad7C[0x108-0x7C]; s32 rows[4][5]; } M;
typedef struct { s32 r[5]; } R5;
typedef struct { u8 pad[0x210]; M *tbl[1]; } S90;
typedef struct {
    u8 pad[0x60];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[0x18];
    f32 x88;
    f32 x8C;
    S90 *p90;
    u16 x94;
    u8 pad96[0x114 - 0x96];
    Bits f114;
} O_FxProc_FireAtTarget_0_001494A0;
typedef struct { f32 v[4]; } V4;
typedef struct { f32 m[8]; } V8;
typedef struct { u8 pad[4]; u32 x4; f32 x8; f32 xC; V4 v; V8 m; } Src;
typedef struct { u8 a; u8 b0:1; u8 b1:1; } W;
typedef union { u32 w; W f; } WU;
typedef struct { V4 v; V8 m; WU w; u8 pad[0xC]; } Dst;
typedef struct { u8 pad[0x30]; Vec p; u8 pad40[0x10]; u8 x50; u8 pad51[0x2F]; } El;
typedef struct {
    s32 x0;
    u8 pad4[0x6A];
    u16 x6E;
    u8 pad70[0x110];
    El *x180;
    u8 pad184[0x54];
    u8 x1D8;
} Ent;
typedef struct {
    u8 pad[0x188];
    u8 pad188[2];
    u8 b0:1;
    u8 b1:1;
} N;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    u8 pad54[0xC];
    f32 x60, x64, x68, x6C;
    u8 pad70[0x20];
    N *x90;
    u8 pad94[0x14];
    f32 xA8;
    u8 padAC[4];
    u16 xB0[8];
    u8 padC0[0x54];
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1;
} O_FxProc_InitChase_0_001493E0_;
typedef struct { char pad[0xA8]; s32 a8; char pac[4]; f32 v[4]; } Obj_FxProc_InitChase_0_001493E0;
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x68];
    f32 x88;
    u8 pad8C[0x24];
    f32 xB0;
    u8 padB4[0x60];
    u8 b0:1;
    u8 b1:1;
} O_FxProc_DropToGround_0_00149D20;
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
} O_FxProc_RandomBounce_0_00149EB0;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    f32 x54;
    u8 pad58[8];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x24];
    s8 *x90;
    u8 pad94[0x2C];
    Mtx xC0;
} O_FxProc_DropToGround_0_00149D20_;
typedef struct { u8 pad[0x68]; f32 x68; u8 pad6C[0x44]; f32 xB0; } O_FxProc_StopLight_0_0014A860;
typedef struct { u8 pad[0x188]; Flags8 x188; } P;
typedef struct {
    Vec x0; u8 pad10[0x40]; Vec x50; f32 x60; f32 x64; f32 x68; u8 pad6C[0x24];
    P *x90; u8 pad94[0x1C]; f32 xB0; u8 padB4[0x60]; Flags8 x114;
} O_FxProc_UpdateLight_0_0014A8A0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF8;
typedef struct { u8 pad[0x188]; BF8 x188; } P90;
typedef struct {
    Vec v0;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    f32 x68;
    s32 x6C[3];
    s32 x5C_dummy;
    u8 pad7C[0x14];
    P90 *x90;
    u8 pad94[0x1C];
    f32 xB0;
    u8 padB4[0x60];
    BF8 x114;
} O;
typedef struct { char pad[0x60]; f32 f60; f32 f64; char p68[8]; f32 v[4]; char p80[0x30]; f32 fb0; } Obj_FxProc_StopLight_0_0014A860;
extern s32 D_003139A0[];
extern s32 D_00201E80;
extern f32 D_001F2160[];
extern Mtx D_001F2170;
extern f32 D_001F2160__as_FxProc_SplashDamage_0_0014A5F0[];
extern s8 D_001F2160__as_FxProc_DropToGround_0_00149D20[];
void FxProc_InitChase_0_001493E0(O_FxProc_InitChase_0_001493E0 *o);
void FxProc_FireAtTarget_0_001494A0(O_FxProc_FireAtTarget_0_001494A0 *o);
void FxProc_AreaDamage_0_00149810(O_FxProc_InitChase_0_001493E0_ *o, f32 dt);
void FxProc_AreaDamageWrap_0_00149CB0(u16 *arg0, f32 arg1);
void FxProc_InitAreaDamage_0_00149CC0(Obj_FxProc_InitChase_0_001493E0 *o);
void FxProc_DropToGround_0_00149D20(O_FxProc_DropToGround_0_00149D20 *o);
void FxProc_RandomBounce_0_00149EB0(O_FxProc_RandomBounce_0_00149EB0 *o);
inline s32 has(void);
void FxProc_ScatterAround_0_0014A210(O_FxProc_DropToGround_0_00149D20_ *o);
void FxProc_SplashDamage_0_0014A5F0(s8 *a0);
void FxProc_StopLight_0_0014A860(O_FxProc_StopLight_0_0014A860 *o);
void FxProc_UpdateLight_0_0014A8A0(O_FxProc_UpdateLight_0_0014A8A0 *o);
void FxProc_InitLight_0_0014A9C0(O *o);
void FxProc_FollowPlayer_0_0014AAF0(Obj_FxProc_StopLight_0_0014A860 *o);
u32 Enemy_GetCurrentParamIdx_0_0013E110(u16 *);
void sceVu0CopyVector(void *, void *);
u16* ActorList_Next_2_001A5460(s32 *);
void Fx_EvalCurveVec_1_001631E0(Vec *, f32, u8 *, void *, u8 *, f32, s32);
void Fx_GetWorldMatrix_1_00163C80(void *, Mtx*);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
u16* ActorList_NextB_0_001A5710(void);
u16* ActorList_NextTargetable_0_001A5660(void);
s32 Proj_FindTarget_0_00146C70(Vec *, Vec *, u16 *, s32 *, Vec *, f32);
void Proj_SpawnAttack_0_00146A70(S90 *, u16 *, u8, u32);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetPosition_1_00167710(s8*, void *);
s32 Map_LineTest_1_001470F0(void *, Vec*, s32, s32, s32, Vec*);
void memcpy(void *, void *, s32);
f32 Vec_Distance_3_00146940(void *, Vec *);
void MapObj_PlayAnimWrap_0_001B7CC0(s32, s32);
s32 Enemy_IsBusy_0_0013EE40(s8 *);
Src* EnemyType_Get_0_001A8360(s32);
void memset(void *, s32, s32);
s32 Sfx_GetOwner_1_001675D0(N *);
void Combat_ProcessHitWrap_0_0013BA60(s32, void *, s8 *, s32);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitChase_0_001493E0(O_FxProc_FireAtTarget_0_001494A0 *, Mtx *);
s8* ActorList_Next_2_001A5460__as_FxProc_AreaDamage_0_00149810(s32 *);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_AreaDamage_0_00149810(O_FxProc_InitChase_0_001493E0_ *, Mtx *);
u16 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_AreaDamage_0_00149810(s8 *);
void FxProc_AreaDamage_0_00149810__as_FxProc_AreaDamageWrap_0_00149CB0(u16 *arg0, f32 arg1);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(float);
u16 Rand_Next_3_0015ED20(void);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void sceVu0RotMatrixX(f32, Mtx *, Mtx *);
void Mtx_RotateToward_0_00146140(void *, f32, f32);
void sceVu0MulMatrix(void *, void *, Mtx *);
void sceVu0ScaleVector(Vec *, void *, f32);
f32 cosf(f32);
f32 sinf(f32);
void sceVu0AddVector(void *, void *, Vec *);
void sceVu0SubVector(Vec *, s8 *, s8 *);
void Actor_GetDirNormalized_0_00146570(Actor *, Vec *);
void Actor_GetYawPitch_1_00145F40(Actor *, f32 *, f32 *);
void sceVu0RotMatrixY__as_FxProc_ScatterAround_0_0014A210(Mtx *, Mtx *, f32);
f64 pow(double, double);
f64 fptodp(f32);
f64 dpadd(double, double);
f32 dptofp(double);
void Sfx_SetPosition_1_00167710__as_FxProc_InitChase_0_001493E0_(s8 *, Vec *);
s32 Map_LineTest_1_001470F0__as_FxProc_InitChase_0_001493E0_(O_FxProc_FireAtTarget_0_001494A0 *, Vec *, s32, s32, s32, Vec *);
s32 Map_LineTest_1_001470F0__as_FxProc_DropToGround_0_00149D20(Vec *, Vec *, s32, s32, s32, Vec *);
s8* ActorList_Next_2_001A5460__as_FxProc_DropToGround_0_00149D20(s32 *);
void Sfx_SetPosition_1_00167710__as_FxProc_DropToGround_0_00149D20(s8 *, f32 *);
void Proj_SpawnAttack_0_00146A70__as_FxProc_DropToGround_0_00149D20(s32, s8 *, s32, u16);
void GlowFx_Stop_0_001E0D30(f32, s32);
s32 GlowFx_Start_0_001E1050(s32);
void GlowFx_SetParams_0_001E0F30(f32, f32, s32, Vec *, Vec *);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_StopLight_0_0014A860(O_FxProc_UpdateLight_0_0014A8A0 *, Mtx *);
s32 GlowFx_Start_0_001E1050__as_FxProc_InitLight_0_0014A9C0(void);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitLight_0_0014A9C0(O *, Mtx *);
void sceVu0CopyVector__as_FxProc_InitLight_0_0014A9C0(Vec *, Vec *);
f32* Player_GetPosition_1_00145730(s32 k);
void sceVu0CopyVector__as_FxProc_FollowPlayer_0_0014AAF0(f32 *v0, f32 *v1);

/* FxProc_InitChase_0_001493E0__ */
/* FxProc_InitChase_0_001493E0_ */

/* FxProc_InitChase_0_001493E0_ */
/* FxProc_InitChase_0_001493E0_ */
/* FxProc_InitChase_0_001493E0 */

/* FxProc_InitChase_0_001493E0 */
void FxProc_InitChase_0_001493E0(O_FxProc_InitChase_0_001493E0 *o) {
    s32 it;
    u16 *e;
    o->xA8 = 0;
    o->x88 = 600.0f;
    sceVu0CopyVector(&o->v, D_003139A0);
    it = 0;
    do {
        e = ActorList_Next_2_001A5460(&it);
    } while (e != NULL && *e != 0x3C);
    if (e != NULL) {
        o->xB8 = Enemy_GetCurrentParamIdx_0_0013E110(e);
        return;
    }
    o->xB8 = 0.0f;
}

/* FxProc_FireAtTarget_0_001494A0 */
static inline f32 u2f(u32 x) { return x; }

void FxProc_FireAtTarget_0_001494A0(O_FxProc_FireAtTarget_0_001494A0 *o) {
    Vec b;
    Vec a;
    Vec out;
    Mtx mtx;
    Vec hit;
    s32 cc;
    M *m;
    u8 *p;
    f32 r;
    u16 *n;
    s32 ok;
    s32 t;
    s8 *q;

    m = o->p90->tbl[o->x94];
    p = (u8 *)&((R5 *)((u8 *)m + 0x108))[m->x4].r[m->x5] + m->x6 * 12;
    p = m->x7.b1 ? p + 0x40 : p;
    p = m->x7.b2 ? p + 0xA0 : p;
    b.x = 0.0f;
    b.y = m->x78;
    b.w = 1.0f;
    b.z = 0.0f;
    Fx_EvalCurveVec_1_001631E0(&a, o->x8C, m->x74, NULL, p, 0.033333335f * u2f(m->x0), m->x7.b0);
    a.w = 1.0f;
    a.x = 0.0f;
    a.z = 0.0f;
    Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitChase_0_001493E0(o, &mtx);
    sceVu0ApplyMatrix(&b, &mtx, &b);
    sceVu0ApplyMatrix(&a, &mtx, &a);
    r = o->x60;
    for (n = ActorList_NextB_0_001A5710(); n != NULL; n = ActorList_NextTargetable_0_001A5660()) {
        if (*n && Proj_FindTarget_0_00146C70(&b, &a, n, &cc, &out, r)) {
            ok = 1;
            goto found;
        }
    }
    cc = 0;
    n = NULL;
    ok = 0;
found:
    if (ok) {
        Proj_SpawnAttack_0_00146A70(o->p90, n, cc, o->x64);
        o->x88 = u2f(o->f114.b1 = 0);
        t = o->x6C;
        if (t) {
            q = Sfx_Spawn_2_00169B50(t, 0, 0, 0);
            if (q) {
                Sfx_SetPosition_1_00167710__as_FxProc_InitChase_0_001493E0_(q, &out);
            }
        }
    } else if (Map_LineTest_1_001470F0__as_FxProc_InitChase_0_001493E0_(o, &a, 3, 6, 0, &hit)) {
        q = Sfx_Spawn_2_00169B50(o->x68, 0, 0, 0);
        if (q) {
            Sfx_SetPosition_1_00167710__as_FxProc_InitChase_0_001493E0_(q, &hit);
        }
        o->x88 = u2f(o->f114.b1 = 0);
    }
}

/* FxProc_AreaDamage_0_00149810 */

void FxProc_AreaDamage_0_00149810(O_FxProc_InitChase_0_001493E0_ *o, f32 dt) {
    f32 t;
    s32 it;
    Vec pos;
    u16 ta[8];
    Dst d;
    u16 tb[8];
    Mtx m;
    u16 id;
    s32 first;
    s32 i;
    El *el;
    s32 j;
    Ent *e;
    Ent ***pp;
    s8 *a;

    it = 0;
    a = ActorList_Next_2_001A5460__as_FxProc_AreaDamage_0_00149810(&it);
    if (o->b5) {
        Fx_GetWorldMatrix_1_00163C80__as_FxProc_AreaDamage_0_00149810(o, &m);
        sceVu0CopyVector(&pos, &m.m[3]);
    } else {
        sceVu0CopyVector(&pos, o);
    }
    memcpy(&t, &o->xA8, 4);
    first = (t == 0.0f);
    t += dt;
    if (o->x50 <= t) {
        t = 0.0f;
    }
    memcpy(&o->xA8, &t, 4);
    if (!first) return;
    {
        if (o->x64 == 2.0f) {
            for (i = 0, pp = (Ent ***)(&D_00201E80 + 2); i < 2; i++, pp++) {
                if (*pp != 0 && ((e = **pp)->x1D8 & 1)) {
                    for (j = 0; j < e->x6E; j++) {
                        el = &e->x180[j];
                        if (!(el->x50 & 3)) {
                            if (Vec_Distance_3_00146940(&el->p, &pos) < o->x60) {
                                MapObj_PlayAnimWrap_0_001B7CC0(e->x0, j);
                            }
                        }
                    }
                }
            }
        }
        if (o->x64 == 2.0f) return;
        {
            while (a) {
                if (*(u16 *)a == 0 && o->x64 == 1.0f) goto next;
                if (*(u16 *)a != 0 && o->x64 == 0.0f) goto next;
                if (Enemy_IsBusy_0_0013EE40(a)) goto next;
                if (o->x6C == 0.0f) {
                    id = Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_AreaDamage_0_00149810(a);
                    sceVu0CopyVector(ta, o->xB0);
                    for (j = 0; j < 8; j++) {
                        if (id == ta[j]) {
                            id = 0xFFFF;
                            break;
                        }
                    }
                    if (id == 0xFFFF) goto next;
                }
                if (Vec_Distance_3_00146940(a ? (void *)(*(s32 *)(a + 0x518) + 0x90) : D_001F2160, &pos) < o->x60) {
                    if (o->x90->b1) {
                        e = (Ent *)((s8 *)o->x90 + 0xE80);
                    } else {
                        e = (Ent *)EnemyType_Get_0_001A8360((s32)o->x68);
                        memset(&d, 0, 0x40);
                        if (e) {
                            d.v = ((Src *)e)->v;
                            d.m = ((Src *)e)->m;
                            d.w.w = ((Src *)e)->x4;
                            d.w.f.b1 = 1;
                        }
                        e = (Ent *)&d;
                    }
                    Combat_ProcessHitWrap_0_0013BA60(Sfx_GetOwner_1_001675D0(o->x90), e, a, 0);
                    id = Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_AreaDamage_0_00149810(a);
                    sceVu0CopyVector(tb, o->xB0);
                    for (j = 0; j < 8; j++) {
                        if (tb[j] == 0xFFFF || id == tb[j]) {
                            tb[j] = id;
                            break;
                        }
                    }
                    sceVu0CopyVector(o->xB0, tb);
                }
            next:
                a = ActorList_Next_2_001A5460__as_FxProc_AreaDamage_0_00149810(&it);
            }
        }
    }
}

/* FxProc_AreaDamageWrap_0_00149CB0 */

void FxProc_AreaDamageWrap_0_00149CB0(u16 *arg0, f32 arg1)
{
    FxProc_AreaDamage_0_00149810__as_FxProc_AreaDamageWrap_0_00149CB0(arg0, arg1);
}

/* FxProc_InitAreaDamage_0_00149CC0 */
void FxProc_InitAreaDamage_0_00149CC0(Obj_FxProc_InitChase_0_001493E0 *o)
{
    u16 t[8];
    sceVu0CopyVector(t, o->v);
    t[7] = 0xFFFF;
    t[6] = 0xFFFF;
    t[5] = 0xFFFF;
    t[4] = 0xFFFF;
    t[3] = 0xFFFF;
    t[2] = 0xFFFF;
    t[1] = 0xFFFF;
    t[0] = 0xFFFF;
    sceVu0CopyVector(o->v, t);
    o->a8 = 0;
}

/* FxProc_DropToGround_0_00149D20 */

/* FxProc_DropToGround_0_00149D20 */
/* FxProc_DropToGround_0_00149D20 */
/* FxProc_DropToGround_0_00149D20 */
void FxProc_DropToGround_0_00149D20(O_FxProc_DropToGround_0_00149D20 *o) {
    Vec out;
    Vec lo;
    Vec hi;
    f32 s;
    f32 r;
    f32 h;
    if (5.0f < o->xB0) {
        o->xB0 = 0;
    } else {
        o->xB0 = o->xB0 + 1.0f;
        return;
    }
    h = 1000.0f;
    lo.x = o->p.x;
    lo.y = o->p.y - h;
    lo.z = o->p.z;
    hi.x = o->p.x;
    hi.y = o->p.y + h;
    hi.z = o->p.z;
    hi.w = 1.0f;
    lo.w = 1.0f;
    if (Map_LineTest_1_001470F0__as_FxProc_DropToGround_0_00149D20(&lo, &hi, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
        s = sqrtf(sceVu0InnerProduct(&o->v, &o->v));
        o->v.y = 0;
        r = s / sqrtf(sceVu0InnerProduct(&o->v, &o->v));
        o->v.x *= r;
        o->v.z *= r;
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}

/* FxProc_RandomBounce_0_00149EB0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 jit(f32 a) { f32 t = 0.5f - 0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20(); return t * a; }

void FxProc_RandomBounce_0_00149EB0(O_FxProc_RandomBounce_0_00149EB0 *o) {
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
    if (Map_LineTest_1_001470F0__as_FxProc_DropToGround_0_00149D20(&lo, &hi, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}

/* FxProc_ScatterAround_0_0014A210 */
/* ang < 0.0f | a */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 DEG(f32 a) { return a ? 0.01745f * a : 0.0f; }
inline s32 has(void) {
    return D_002022E4 != NULL && D_002022E4->unk518 != NULL;
}

void FxProc_ScatterAround_0_0014A210(O_FxProc_DropToGround_0_00149D20_ *o) {
    f32 h;
    f32 ang;
    f32 r;
    f32 yr;
    f32 a;
    s8 *b;
    Vec t;
    Vec w;
    Vec d;

    h = o->x60;
    ang = o->x64;
    r = o->x50;
    yr = o->x54;
    a = 6.2831855f * (1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20());
    r *= 1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20();
    d.x = r * cosf(a);
    d.z = r * sinf(a);
    d.y = yr * (1.0f - 2.0f * (1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20()));
    d.w = 0.0f;
    sceVu0AddVector(o, o, &d);
    b = o->x90;
    sceVu0SubVector(&t, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160__as_FxProc_DropToGround_0_00149D20, b + 0x30);
    sceVu0AddVector(o, o, &t);
    o->p.w = 1.0f;
    o->p.y += h;
    Actor_GetDirNormalized_0_00146570(D_002022E4, &w);
    o->p.x += w.x * o->x68;
    o->p.z += w.z * o->x68;
    if (ang < 0.0f) {
        Actor_GetYawPitch_1_00145F40(D_002022E4, &ang, NULL);
        sceVu0RotMatrixY__as_FxProc_ScatterAround_0_0014A210(&o->xC0, &D_001F2170, WRAP(ang));
    } else {
        sceVu0RotMatrixY__as_FxProc_ScatterAround_0_0014A210(&o->xC0, &D_001F2170, WRAP(DEG(ang)));
    }
}

/* FxProc_SplashDamage_0_0014A5F0 */
#define POS(p) ((p) ? (f32 *)(*(s32 *)((p) + 0x518) + 0x90) : D_001F2160__as_FxProc_SplashDamage_0_0014A5F0)

void FxProc_SplashDamage_0_0014A5F0(s8 *a0) {
    f32 *q;
    s32 it;
    s8 *p;
    u32 id;
    s32 n;
    s32 ok;
    f32 *pos;
    double dz;
    s8 *e;
    if (*(s32 *)(a0 + 0xA8) == 0) {
        it = 0;
        p = ActorList_Next_2_001A5460__as_FxProc_DropToGround_0_00149D20(&it);
        id = (u32)*(f32 *)(a0 + 0x60);
        while (p) {
            n = 0;
            if (*(u16 *)p != 0 && !Enemy_IsBusy_0_0013EE40(p)) {
                pos = POS(p);
                q = POS(p);
                dz = pow(fptodp(pos[2] - *(f32 *)(a0 + 8)), 2.0);
                n += sqrtf(dptofp(dpadd(pow(fptodp(q[0] - *(f32 *)(a0 + 0)), 2.0), dz))) < *(f32 *)(a0 + 0x50);
                ok = 0;
                if (*(f32 *)(a0 + 4) + *(f32 *)(a0 + 0x54) <= POS(p)[1] && POS(p)[1] <= *(f32 *)(a0 + 4) + *(f32 *)(a0 + 0x58)) {
                    ok = 1;
                }
                n *= ok;
                if (n) {
                    if (id && (e = Sfx_Spawn_2_00169B50(id, 0, 0, 0))) {
                        Sfx_SetPosition_1_00167710__as_FxProc_DropToGround_0_00149D20(e, POS(p));
                    }
                    Proj_SpawnAttack_0_00146A70__as_FxProc_DropToGround_0_00149D20(*(s32 *)(a0 + 0x90), p, 0, (s32)*(f32 *)(a0 + 0x64));
                }
            }
            p = ActorList_Next_2_001A5460__as_FxProc_DropToGround_0_00149D20(&it);
        }
        *(s32 *)(a0 + 0xA8) = 1;
    }
}

/* FxProc_StopLight_0_0014A860_ */
#define D_002022E4 D_002022E4__as_FxProc_StopLight_0_0014A860_
extern void *D_002022E4__as_FxProc_StopLight_0_0014A860_;

/* FxProc_StopLight_0_0014A860_ */
/* FxProc_StopLight_0_0014A860 */

/* FxProc_StopLight_0_0014A860 */
void FxProc_StopLight_0_0014A860(O_FxProc_StopLight_0_0014A860 *o) {
    if ((s32)o->xB0 != -1) {
        GlowFx_Stop_0_001E0D30(o->x68, (s32)o->xB0);
    }
}

/* FxProc_UpdateLight_0_0014A8A0 */
void FxProc_UpdateLight_0_0014A8A0(O_FxProc_UpdateLight_0_0014A8A0 *o) {
    Vec v;
    Mtx m;
    if (o->x90->x188.f.b2) {
        if ((s32)o->xB0 == -1) {
            o->xB0 = GlowFx_Start_0_001E1050((s32)o->xB0);
        }
    } else {
        if ((s32)o->xB0 != -1) {
            GlowFx_Stop_0_001E0D30(o->x68, (s32)o->xB0);
            o->xB0 = -1.0f;
        }
    }
    if ((s32)o->xB0 != -1) {
        if (o->x114.f.b5) {
            Fx_GetWorldMatrix_1_00163C80__as_FxProc_StopLight_0_0014A860(o, &m);
            sceVu0CopyVector(&v, &m.m[3]);
        } else {
            sceVu0CopyVector(&v, o);
        }
        GlowFx_SetParams_0_001E0F30(o->x60, o->x64, (s32)o->xB0, &v, &o->x50);
    }
}

/* FxProc_InitLight_0_0014A9C0 */

void FxProc_InitLight_0_0014A9C0(O *o) {
    Vec v;
    Mtx m;

    *(s32 *)((u8 *)o + 0x5C) = 0;
    o->xB0 = -1.0f;
    if (o->x90->x188.b2) {
        if ((s32)o->xB0 == -1) {
            o->xB0 = GlowFx_Start_0_001E1050__as_FxProc_InitLight_0_0014A9C0();
        }
    } else {
        if ((s32)o->xB0 != -1) {
            GlowFx_Stop_0_001E0D30(o->x68, o->xB0);
            o->xB0 = -1.0f;
        }
    }
    if ((s32)o->xB0 != -1) {
        if (o->x114.b5) {
            Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitLight_0_0014A9C0(o, &m);
            sceVu0CopyVector__as_FxProc_InitLight_0_0014A9C0(&v, &m.m[3]);
        } else {
            sceVu0CopyVector__as_FxProc_InitLight_0_0014A9C0(&v, &o->v0);
        }
        GlowFx_SetParams_0_001E0F30(o->x60, o->x64, o->xB0, &v, &o->v50);
    }
}

/* FxProc_FollowPlayer_0_0014AAF0 */

void FxProc_FollowPlayer_0_0014AAF0(Obj_FxProc_StopLight_0_0014A860 *o)
{
    s32 k;
    if (0.0f != o->f60) {
        f32 v = o->fb0;
        o->v[2] = v;
        o->v[1] = v;
        o->v[0] = v;
        o->v[3] = 1.0f;
    }
    k = o->f64;
    if (k == 1) {
        f32 *src;
        if (D_002022E4)
            src = Player_GetPosition_1_00145730(k);
        else
            src = D_001F2160;
        sceVu0CopyVector__as_FxProc_FollowPlayer_0_0014AAF0((f32 *)o, src);
    }
}
#undef D_002022E4
