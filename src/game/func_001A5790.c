#include "common.h"
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, Mtx *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
f32 sqrtf(f32);

void func_001A5790(Vec *o1, Vec *o2, Mtx *m, Vec *p, Vec *d) {
    Vec a;
    Vec b;
    f32 *wa;
    f32 *wb;
    f32 len;

    func_00102A60(&a, p);
    wa = &a.w;
    *wa = 1.0f;
    func_00102A60(&b, d);
    wb = &b.w;
    *wb = 0.0f;
    func_001027B0(&a, m, &a);
    func_001027B0(&b, m, &b);
    len = sqrtf(func_00102848(&b, &b));
    func_00102870(&b, &b);
    *wa = p->w * len;
    *wb = d->w * len;
    func_00102A60(o1, &a);
    func_00102A60(o2, &b);
}
