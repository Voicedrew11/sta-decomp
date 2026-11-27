#include "common.h"
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
} O;
typedef struct { u8 pad[0x20]; Vec a; Vec b; } M;
extern f32 D_001FB738[];
s8 *ActorList_Next_2_001A5460(s32 *);
u16 Enemy_GetCurrentParamIdx_0_0013E110(s8 *);
s32 Enemy_IsBusy_0_0013EE40(s8 *);
void Fx_GetWorldMatrix_1_00163C80(O *, M *);
s8 *Proj_FindEnemyInCone_0_00146EF0(f32, Vec *, f32, Vec *, f32, s32);
Vec *Enemy_Ptr6F0_1_0013FFA0(s8 *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, void *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
float sqrtf(float);
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

void FxProc_SeekEnemyInCone_0_0014D4A0(O *o) {
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
        sceVu0CopyVector(&b0, Enemy_Ptr6F0_1_0013FFA0(p));
    } else if (k.s.f2) {
        sceVu0CopyVector(&b0, &o->xB0);
        b0.w = 1.0f;
    }
    if (p != NULL || k.s.f2) {
        h = o->x60;
        t = o->xB0.w;
        sceVu0SubVector(&v60, &b0, o);
        s = sqrtf(sceVu0InnerProduct(&o->v, &o->v));
        sceVu0Normalize(&v50, &v60);
        sceVu0ScaleVector(&v50, &v50, -1.0f * t);
        sceVu0AddVector(&o->v, &o->v, &v50);
        sceVu0Normalize(&o->v, &o->v);
        sceVu0ScaleVector(&o->v, &o->v, s);
        o->xB0.w = o->xB0.w - h;
    }
}
