#include "common.h"
typedef struct O { Mtx m0; u8 p40[0x50]; Mtx *x90; u8 p94[0xC]; u16 xA0; u8 pA2[2]; f32 xA4; u8 pA8[0x18]; Mtx xC0; u8 p100[0x14]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 p115[0xB]; } O;
extern O *D_00201FC0;
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0CopyVector(Vec *, Vec *);
void Mtx_AxisAngle_2_0015EBB0(f32, Mtx *, Vec *);
void sceVu0MulMatrix(Mtx *, Mtx *, Mtx *);
static inline O *get(u16 id) {
    if (id == 0xFFFF) return 0;
    return &D_00201FC0[id];
}

void Fx_GetWorldMatrix_1_00163C80(O *o, Mtx *out) {
    Vec v;
    Mtx r;
    Mtx p;
    O *q;
    sceVu0CopyMatrix(out, &o->xC0);
    sceVu0CopyVector(&out->m[3], &o->m0.m[0]);
    out->m[3].w = 1.0f;
    if (o->xA4 != 0.0f) {
        sceVu0CopyVector(&v, &o->m0.m[3]);
        v.w = 0.0f;
        Mtx_AxisAngle_2_0015EBB0(o->xA4, &r, &v);
        sceVu0MulMatrix(out, out, &r);
    }
    if (o->b5) {
        q = get(o->xA0);
        if (q != 0) {
            Fx_GetWorldMatrix_1_00163C80(q, &p);
        } else {
            sceVu0CopyMatrix(&p, o->x90);
        }
        sceVu0MulMatrix(out, &p, out);
    }
}
