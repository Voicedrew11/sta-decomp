#include "common.h"
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sqrtf(f32);

void Actor_TransformRay_0_001A5790(Vec *o1, Vec *o2, Mtx *m, Vec *p, Vec *d) {
    Vec a;
    Vec b;
    f32 *wa;
    f32 *wb;
    f32 len;

    sceVu0CopyVector(&a, p);
    wa = &a.w;
    *wa = 1.0f;
    sceVu0CopyVector(&b, d);
    wb = &b.w;
    *wb = 0.0f;
    sceVu0ApplyMatrix(&a, m, &a);
    sceVu0ApplyMatrix(&b, m, &b);
    len = sqrtf(sceVu0InnerProduct(&b, &b));
    sceVu0Normalize(&b, &b);
    *wa = p->w * len;
    *wb = d->w * len;
    sceVu0CopyVector(o1, &a);
    sceVu0CopyVector(o2, &b);
}
