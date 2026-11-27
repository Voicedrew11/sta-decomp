#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec m[4]; } Mtx;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    Vec pos;
    u8 pad10[0x54];
    f32 x64;
    u8 pad68[0x50];
    f32 xB8;
    f32 xBC;
    u8 padC0[0x54];
    Bits f114;
} Obj;
u16 *ActorList_Next_2_001A5460(s32 *);
u32 Enemy_GetCurrentParamIdx_0_0013E110(u16 *);
Vec *Enemy_Ptr6F0_1_0013FFA0(u16 *);
void sceVu0CopyVector(void *, void *);
void Fx_GetWorldMatrix_1_00163C80(Obj *, Mtx *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
float sqrtf(float);
static inline f32 u2f(u32 x) { return x; }

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
        a->xB8 = u2f(Enemy_GetCurrentParamIdx_0_0013E110(p));
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

