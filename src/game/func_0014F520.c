#include "common.h"
void func_001029E8(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102828(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
float sqrtf(float);

s32 func_0014F520(Vec *out, Vec *p, Vec *q, Vec *v, Vec *n, s32 i, s32 two, f32 *dist) {
    Vec h;
    Vec hn;
    Vec d;
    Vec a1;
    Vec b1;
    Vec c1;
    Vec a2;
    Vec b2;
    Vec c2;
    Vec a3;
    Vec b3;
    Vec c3;
    Vec *v0;
    Vec *v1;
    Vec *v2;
    f32 num;
    f32 den;
    f32 t;
    f32 e1;
    f32 e2;
    f32 e3;

    v0 = &v[i % 3];
    v1 = &v[(i + 1) % 3];
    v2 = &v[(i + 2) % 3];
    func_001029E8(&d, q, p);
    d.w = 0.0f;
    if (two == 0) {
        func_00102870(&h, &d);
        if (!(func_00102848(&h, n) < 0.0f)) {
            return 0;
        }
    }
    num = -func_00102848(v0, n);
    den = func_00102848(n, &d);
    if (den == 0.0f) {
        return 0;
    }
    t = -(num + func_00102848(n, p)) / den;
    if (!(t <= 1.0f) || t < 0.0f) {
        return 0;
    }
    func_00102A18(&d, &d, t);
    func_001029D0(&h, p, &d);
    func_001029D0(&hn, &h, n);
    func_001029E8(&a1, v0, &h);
    a1.w = 0.0f;
    func_001029E8(&b1, v1, v0);
    b1.w = 0.0f;
    func_00102828(&c1, &a1, &b1);
    c1.w = 0.0f;
    e1 = func_00102848(&c1, &hn) - func_00102848(&c1, &h);
    func_001029E8(&a2, v1, &h);
    a2.w = 0.0f;
    func_001029E8(&b2, v2, v1);
    b2.w = 0.0f;
    func_00102828(&c2, &a2, &b2);
    c2.w = 0.0f;
    e2 = func_00102848(&c2, &hn) - func_00102848(&c2, &h);
    func_001029E8(&a3, v2, &h);
    a3.w = 0.0f;
    func_001029E8(&b3, v0, v2);
    b3.w = 0.0f;
    func_00102828(&c3, &a3, &b3);
    c3.w = 0.0f;
    e3 = func_00102848(&c3, &hn) - func_00102848(&c3, &h);
    if (!(e1 < 0.0f || e2 < 0.0f || e3 < 0.0f) || (e1 < 0.0f && e2 < 0.0f && e3 < 0.0f)) {
        func_00102A60(out, &h);
        *(s32 *)&out->w = 0x3F800000;
        func_00102A60(out + 1, n);
        if (dist) {
            func_001029E8(&h, p, out);
            h.w = 0.0f;
            *dist = sqrtf(func_00102848(&h, &h));
        }
        return 1;
    }
    return 0;
}
