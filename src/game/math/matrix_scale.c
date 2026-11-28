#include "common.h"
typedef struct { char pad[0x50]; f32 v[5][4]; } Obj;
void Mtx_ScaleRotation_0_0015CC40(void *arg0, f32 fparg0);
void Mtx_LerpRows_0_0015CC80(Obj *o, f32 *b, f32 t);
void sceVu0InterVector(f32 *v0, f32 *v1, f32 *v2, f32 t);

/* Mtx_ScaleRotation_0_0015CC40 */
void Mtx_ScaleRotation_0_0015CC40(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) (M2C_FIELD(arg0, f32 *, 0x5C) * fparg0);
    M2C_FIELD(arg0, f32 *, 0x6C) = (f32) (M2C_FIELD(arg0, f32 *, 0x6C) * fparg0);
    M2C_FIELD(arg0, f32 *, 0x7C) = (f32) (M2C_FIELD(arg0, f32 *, 0x7C) * fparg0);
    M2C_FIELD(arg0, f32 *, 0x8C) = (f32) (M2C_FIELD(arg0, f32 *, 0x8C) * fparg0);
    M2C_FIELD(arg0, f32 *, 0x9C) = (f32) (M2C_FIELD(arg0, f32 *, 0x9C) * fparg0);
}

/* Mtx_LerpRows_0_0015CC80 */
void Mtx_LerpRows_0_0015CC80(Obj *o, f32 *b, f32 t)
{
    s32 i;
    f32 w;
    for (i = 0; i < 4; i++) {
        w = o->v[i][3];
        sceVu0InterVector(o->v[i], b, o->v[i], t);
        o->v[i][3] = w;
    }
    w = o->v[4][3];
    sceVu0InterVector(o->v[4], b, o->v[4], t);
    o->v[4][3] = w;
}
