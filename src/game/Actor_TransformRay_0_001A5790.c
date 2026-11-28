#include "common.h"
void Actor_TransformRay_0_001A5790(Vec *o1, Vec *o2, Mtx *m, Vec *p, Vec *d);
void Actor_ClosestOnSegment_0_001A58A0(Vec *a, Vec *b, Vec *o1, Vec *o2, f32 f);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sqrtf(f32);
void sceVu0SubVector(Vec *, Vec *, Vec *);

/* Actor_TransformRay_0_001A5790 */
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

/* Actor_ClosestOnSegment_0_001A58A0 */
void Actor_ClosestOnSegment_0_001A58A0(Vec *a, Vec *b, Vec *o1, Vec *o2, f32 f) {
    Vec p;
    Vec q;
    Vec d;
    f32 l;
    p.x = a->x; p.y = a->y; p.z = a->z; p.w = 0.0f;
    q.x = b->x; q.y = b->y; q.z = b->z; q.w = 0.0f;
    sceVu0SubVector(&d, &q, &p);
    l = sqrtf(sceVu0InnerProduct(&d, &d));
    sceVu0CopyVector(o1, &p);
    sceVu0Normalize(o2, &d);
    o2->w = l;
    o1->w = f;
}
