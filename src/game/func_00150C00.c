#include "common.h"
typedef struct { Vec p; Vec v; } Sph;
f32 func_0011D850(f32);
void func_00102A60(Vec *, Vec *);
void func_001029E8(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);

s32 func_00150C00(Sph *s, Vec *p, Vec *n, Vec *out, f32 *t, f32 *d) {
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
    func_00102A60(&a, &s->p);
    func_001029E8(&c, p, &a);
    func_00102A60(&b, &s->p);
    b.x += s->v.x * s->v.w;
    b.y += s->v.y * s->v.w;
    b.z += s->v.z * s->v.w;
    func_001029E8(&e, p, &b);
    d0 = n->x * c.x + n->y * c.y + n->z * c.z;
    d1 = n->x * e.x + n->y * e.y + n->z * e.z;
    if (d0 < -s->p.w && d1 < -s->p.w) return 0;
    if (!(d0 <= s->p.w) && !(d1 <= s->p.w)) return 0;
    pen = s->p.w + d1;
    dv = n->x * s->v.x + n->y * s->v.y + n->z * s->v.z;
    pen = pen < 0.0f ? 0.0f : pen;
    if (func_0011D850(dv) < 0.2f) {
        *t = 0.0f;
        func_00102A18(out, n, -s->p.w);
        func_001029D0(out, out, &a);
        *d = pen;
        return 4;
    }
    if (d0 * d1 < 0.0f) {
        if (func_0011D850(d0 - d1) < 1e-05f) {
            *t = 0.0f;
        } else {
            *t = (func_0011D850(d0) - s->p.w) / (d1 - d0);
        }
        if (*t < 0.0f) *t = 0.0f;
        if (!(*t <= 1.0f)) *t = 1.0f;
        func_00102A18(&b, &s->v, *t * s->v.w);
        func_001029D0(&b, &b, &s->p);
        func_00102A18(out, n, -s->p.w);
        func_001029D0(out, out, &b);
        *d = 0.0f;
        return 1;
    }
    m = d1;
    if (func_0011D850(d0) < func_0011D850(d1)) m = d0;
    if (func_0011D850(m) < s->p.w) {
        if (m == d0) {
            d1 = d0 - d1;
            if (func_0011D850(d1) < 1e-05f) {
                *t = 0.0f;
            } else {
                *t = (s->p.w - func_0011D850(d0)) / d1;
            }
            if (*t < 0.0f) *t = 0.0f;
            if (!(*t <= 1.0f)) *t = 1.0f;
            func_00102A18(&b, &s->v, *t * s->v.w);
            func_001029D0(&b, &b, &s->p);
            if (d0 < 0.0f) {
                func_00102A18(out, n, -s->p.w);
                func_001029D0(out, out, &b);
            } else {
                func_00102A18(out, n, s->p.w);
                func_001029D0(out, out, &b);
            }
            *d = pen;
            return 2;
        } else {
            if (func_0011D850(d0 - d1) < 1e-05f) {
                *t = 0.0f;
            } else {
                *t = (func_0011D850(d0) - s->p.w) / (d1 - d0);
            }
            if (*t < 0.0f) *t = 0.0f;
            if (!(*t <= 1.0f)) *t = 1.0f;
            func_00102A18(&b, &s->v, *t * s->v.w);
            func_001029D0(&b, &b, &s->p);
            if (d0 < 0.0f) {
                func_00102A18(out, n, -s->p.w);
                func_001029D0(out, out, &b);
            } else {
                func_00102A18(out, n, s->p.w);
                func_001029D0(out, out, &b);
            }
            *d = pen;
            return 3;
        }
    }
    return 0;
}
