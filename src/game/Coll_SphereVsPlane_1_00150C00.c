#include "common.h"
typedef struct { Vec p; Vec v; } Sph;
f32 fabsf(f32);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);

s32 Coll_SphereVsPlane_1_00150C00(Sph *s, Vec *p, Vec *n, Vec *out, f32 *t, f32 *d) {
    Vec a;
    Vec b;
    Vec c;
    Vec e;
    f32 d0;
    f32 d1;
    f32 pen;
    f32 m;
    f32 dv;

    *d = 0.0f;
    sceVu0CopyVector(&a, &s->p);
    sceVu0SubVector(&c, p, &a);
    sceVu0CopyVector(&b, &s->p);
    b.x += s->v.x * s->v.w;
    b.y += s->v.y * s->v.w;
    b.z += s->v.z * s->v.w;
    sceVu0SubVector(&e, p, &b);
    d0 = n->x * c.x + n->y * c.y + n->z * c.z;
    d1 = n->x * e.x + n->y * e.y + n->z * e.z;
    if (d0 < -s->p.w && d1 < -s->p.w) return 0;
    if (!(d0 <= s->p.w) && !(d1 <= s->p.w)) return 0;
    pen = s->p.w + d1;
    dv = n->x * s->v.x + n->y * s->v.y + n->z * s->v.z;
    pen = pen < 0.0f ? 0.0f : pen;
    if (fabsf(dv) < 0.2f) {
        *t = 0.0f;
        sceVu0ScaleVector(out, n, -s->p.w);
        sceVu0AddVector(out, out, &a);
        *d = pen;
        return 4;
    }
    if (d0 * d1 < 0.0f) {
        if (fabsf(d0 - d1) < 1e-05f) {
            *t = 0.0f;
        } else {
            *t = (fabsf(d0) - s->p.w) / (d1 - d0);
        }
        if (*t < 0.0f) *t = 0.0f;
        if (!(*t <= 1.0f)) *t = 1.0f;
        sceVu0ScaleVector(&b, &s->v, *t * s->v.w);
        sceVu0AddVector(&b, &b, &s->p);
        sceVu0ScaleVector(out, n, -s->p.w);
        sceVu0AddVector(out, out, &b);
        *d = 0.0f;
        return 1;
    }
    m = d1;
    if (fabsf(d0) < fabsf(d1)) m = d0;
    if (fabsf(m) < s->p.w) {
        if (m == d0) {
            d1 = d0 - d1;
            if (fabsf(d1) < 1e-05f) {
                *t = 0.0f;
            } else {
                *t = (s->p.w - fabsf(d0)) / d1;
            }
            if (*t < 0.0f) *t = 0.0f;
            if (!(*t <= 1.0f)) *t = 1.0f;
            sceVu0ScaleVector(&b, &s->v, *t * s->v.w);
            sceVu0AddVector(&b, &b, &s->p);
            if (d0 < 0.0f) {
                sceVu0ScaleVector(out, n, -s->p.w);
                sceVu0AddVector(out, out, &b);
            } else {
                sceVu0ScaleVector(out, n, s->p.w);
                sceVu0AddVector(out, out, &b);
            }
            *d = pen;
            return 2;
        } else {
            if (fabsf(d0 - d1) < 1e-05f) {
                *t = 0.0f;
            } else {
                *t = (fabsf(d0) - s->p.w) / (d1 - d0);
            }
            if (*t < 0.0f) *t = 0.0f;
            if (!(*t <= 1.0f)) *t = 1.0f;
            sceVu0ScaleVector(&b, &s->v, *t * s->v.w);
            sceVu0AddVector(&b, &b, &s->p);
            if (d0 < 0.0f) {
                sceVu0ScaleVector(out, n, -s->p.w);
                sceVu0AddVector(out, out, &b);
            } else {
                sceVu0ScaleVector(out, n, s->p.w);
                sceVu0AddVector(out, out, &b);
            }
            *d = pen;
            return 3;
        }
    }
    return 0;
}
