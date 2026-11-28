#include "actor.h"
#include "common.h"
typedef struct { u8 pad[0x10]; Vec v10; u8 pad20[0x40]; f32 x60; u8 pad64[0x58]; f32 xBC; } O_FxProc_MoveToward_0_0014D310;
typedef struct { Vec v; char p[0xAC]; f32 xBC; } O_FxProc_InitTowardEnemy_0_0014D410;
typedef union { u32 w; struct { u16 id; u8 f2; u8 f3; } s; } K;
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x40];
    f32 x60;
    u8 pad64[0x44];
    K xA8;
    u8 padAC[4];
    Vec xB0;
} O_FxProc_MoveToward_0_0014D310_;
typedef struct { u8 pad[0x20]; Vec a; Vec b; } M;
typedef struct { u8 m[0x40]; } MtxB;
typedef struct {
    u8 pad0[0x50];
    Vec x50;
    u8 pad60[0x30];
    M *x90;
    u8 pad94[0x14];
    K xA8;
    u8 padAC[4];
    Vec xB0;
} O_FxProc_InitSeekCone_0_0014D700;
extern s8 D_001F2160[];
extern s32 D_002022E4__as_FxProc_InitTowardEnemy_0_0014D410;
extern f32 D_001FB738[];
inline s32 has(void);
void FxProc_MoveToward_0_0014D310(O_FxProc_MoveToward_0_0014D310 *o);
void FxProc_InitTowardEnemy_0_0014D410(O_FxProc_InitTowardEnemy_0_0014D410 *arg0);
void FxProc_SeekEnemyInCone_0_0014D4A0(O_FxProc_MoveToward_0_0014D310_ *o);
void FxProc_InitSeekCone_0_0014D700(O_FxProc_InitSeekCone_0_0014D700 *o);
void sceVu0SubVector(Vec*, void *, void*);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
f32 sqrtf(f32);
s32 Enemy_Ptr6F0_1_0013FFA0(s32);
void sceVu0CopyVector(Vec *, s32);
void sceVu0SubVector__as_FxProc_MoveToward_0_0014D310(Vec *, s8 *, O_FxProc_MoveToward_0_0014D310 *);
void sceVu0SubVector__as_FxProc_InitTowardEnemy_0_0014D410(Vec *, Vec *, Vec *);
s8* ActorList_Next_2_001A5460(s32 *);
u16 Enemy_GetCurrentParamIdx_0_0013E110(s8 *);
s32 Enemy_IsBusy_0_0013EE40(s8 *);
void Fx_GetWorldMatrix_1_00163C80(O_FxProc_MoveToward_0_0014D310_ *, M *);
s8* Proj_FindEnemyInCone_0_00146EF0(f32, Vec *, f32, Vec *, f32, s32);
Vec* Enemy_Ptr6F0_1_0013FFA0__as_FxProc_SeekEnemyInCone_0_0014D4A0(s8 *);
void sceVu0CopyVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(Vec *, Vec *);
void sceVu0SubVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(Vec *, Vec *, void *);
void Actor_BuildRotMatrix_0_00146600(Actor *, MtxB *);
void sceVu0ApplyMatrix(Vec *, MtxB *, Vec *);

/* FxProc_MoveToward_0_0014D310_ */
/* FxProc_MoveToward_0_0014D310_ */
/* FxProc_MoveToward_0_0014D310 */
inline s32 has(void) {
    return D_002022E4 != NULL && D_002022E4->unk518 != NULL;
}

void FxProc_MoveToward_0_0014D310(O_FxProc_MoveToward_0_0014D310 *o) {
    Vec t;
    Vec u;
    f32 d;
    f32 r;
    f32 len;

    d = o->x60;
    r = o->xBC;
    sceVu0SubVector__as_FxProc_MoveToward_0_0014D310(&t, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160, o);
    len = sqrtf(sceVu0InnerProduct(&o->v10, &o->v10));
    sceVu0Normalize(&u, &t);
    sceVu0ScaleVector(&u, &u, -1.0f * r);
    sceVu0AddVector(&o->v10, &o->v10, &u);
    sceVu0Normalize(&o->v10, &o->v10);
    sceVu0ScaleVector(&o->v10, &o->v10, len);
    o->xBC -= d;
}

/* FxProc_InitTowardEnemy_0_0014D410 */
void FxProc_InitTowardEnemy_0_0014D410(O_FxProc_InitTowardEnemy_0_0014D410 *arg0) {
    Vec sp30;
    Vec sp20;
    f32 d;
    sceVu0CopyVector(&sp20, Enemy_Ptr6F0_1_0013FFA0(D_002022E4__as_FxProc_InitTowardEnemy_0_0014D410));
    sceVu0SubVector__as_FxProc_InitTowardEnemy_0_0014D410(&sp30, &sp20, &arg0->v);
    d = sqrtf(sp30.x * sp30.x + sp30.z * sp30.z);
    d = (0.05f - d) / 0.1f; d *= 0.001f; arg0->xBC = d;
}

/* FxProc_SeekEnemyInCone_0_0014D4A0 */
static inline s8 *find(s32 *it, K *k) {
    s8 *p;
    u16 kid;
    *it = 0;
    p = ActorList_Next_2_001A5460(it);
    if (p != NULL) {
    kid = k->s.id;
    do {
        if (*(u16 *)p != 0 && Enemy_GetCurrentParamIdx_0_0013E110(p) == kid) {
            return p;
        }
        p = ActorList_Next_2_001A5460(it);
    } while (p != NULL);
    }
    return NULL;
}

void FxProc_SeekEnemyInCone_0_0014D4A0(O_FxProc_MoveToward_0_0014D310_ *o) {
    K k;
    s32 it;
    K k2;
    Vec b0;
    M m;
    Vec v60;
    Vec v50;
    s8 *p;
    u16 id;
    f32 s;
    f32 h;
    f32 t;

    k.w = o->xA8.w;
    p = NULL;
    if (*(u16 *)&k != 0) {
        p = find(&it, &k);
    }
    if (p == NULL || (p != NULL && Enemy_IsBusy_0_0013EE40(p) != 0)) {
        Fx_GetWorldMatrix_1_00163C80(o, &m);
        p = Proj_FindEnemyInCone_0_00146EF0(D_001FB738[0], &m.b, 1.5707964f, &m.a, 1.5707964f, 1);
        if (p != NULL) {
            s = o->xB0.w;
            id = Enemy_GetCurrentParamIdx_0_0013E110(p);
            k2.w = o->xA8.w;
            k2.s.id = id;
            k2.s.f2 = id == 0 && k2.s.f2 == 1;
            k2.s.f3 = 0;
            o->xA8.w = k2.w;
            o->xB0.w = s;
        }
    }
    if (p != NULL) {
        sceVu0CopyVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(&b0, Enemy_Ptr6F0_1_0013FFA0__as_FxProc_SeekEnemyInCone_0_0014D4A0(p));
    } else if (k.s.f2) {
        sceVu0CopyVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(&b0, &o->xB0);
        b0.w = 1.0f;
    }
    if (p != NULL || k.s.f2) {
        h = o->x60;
        t = o->xB0.w;
        sceVu0SubVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(&v60, &b0, o);
        s = sqrtf(sceVu0InnerProduct(&o->v, &o->v));
        sceVu0Normalize(&v50, &v60);
        sceVu0ScaleVector(&v50, &v50, -1.0f * t);
        sceVu0AddVector(&o->v, &o->v, &v50);
        sceVu0Normalize(&o->v, &o->v);
        sceVu0ScaleVector(&o->v, &o->v, s);
        o->xB0.w = o->xB0.w - h;
    }
}

/* FxProc_InitSeekCone_0_0014D700 */
#define Enemy_Ptr6F0_1_0013FFA0 Enemy_Ptr6F0_1_0013FFA0__as_FxProc_InitSeekCone_0_0014D700
Vec *Enemy_Ptr6F0_1_0013FFA0__as_FxProc_InitSeekCone_0_0014D700(s8 *);
#define sceVu0CopyVector sceVu0CopyVector__as_FxProc_InitSeekCone_0_0014D700
void sceVu0CopyVector__as_FxProc_InitSeekCone_0_0014D700(Vec *, Vec *);
#define sceVu0SubVector sceVu0SubVector__as_FxProc_InitSeekCone_0_0014D700
void sceVu0SubVector__as_FxProc_InitSeekCone_0_0014D700(Vec *, Vec *, void *);

void FxProc_InitSeekCone_0_0014D700(O_FxProc_InitSeekCone_0_0014D700 *o) {
    K k;
    K k2;
    Vec b0;
    Vec a0;
    Vec v90;
    Vec v80;
    MtxB m;
    s8 *p;
    u16 id;
    f32 t;

    k.s.id = 0;
    k.s.f3 = 0;
    k.s.f2 = 1;
    o->xA8.w = k.w;
    sceVu0CopyVector(&b0, &o->x90->b);
    b0.w = 1.0f;
    sceVu0CopyVector(&a0, &o->x90->a);
    p = Proj_FindEnemyInCone_0_00146EF0(D_001FB738[0], &b0, 1.5707964f, &a0, 1.5707964f, 1);
    if (p != NULL) {
        sceVu0CopyVector(&v80, Enemy_Ptr6F0_1_0013FFA0(p));
        sceVu0SubVector(&v90, &v80, o);
        t = (0.05f - sqrtf(v90.x * v90.x + v90.z * v90.z)) / 0.1f;
        t *= 0.001f;
        id = Enemy_GetCurrentParamIdx_0_0013E110(p);
    } else {
        o->x50.w = 1.0f;
        Actor_BuildRotMatrix_0_00146600(D_002022E4, &m);
        sceVu0ApplyMatrix(&o->xB0, &m, &o->x50);
        t = 0.0f;
        id = 0;
    }
    k2.w = o->xA8.w;
    k2.s.id = id;
    k2.s.f2 = id == 0 && k2.s.f2 == 1;
    k2.s.f3 = 0;
    o->xA8.w = k2.w;
    o->xB0.w = t;
}
#undef Enemy_Ptr6F0_1_0013FFA0
#undef sceVu0CopyVector
#undef sceVu0SubVector
