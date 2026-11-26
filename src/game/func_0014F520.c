#include "common.h"
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
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
    sceVu0SubVector(&d, q, p);
    d.w = 0.0f;
    if (two == 0) {
        func_00102870(&h, &d);
        if (!(sceVu0InnerProduct(&h, n) < 0.0f)) {
            return 0;
        }
    }
    num = -sceVu0InnerProduct(v0, n);
    den = sceVu0InnerProduct(n, &d);
    if (den == 0.0f) {
        return 0;
    }
    t = -(num + sceVu0InnerProduct(n, p)) / den;
    if (!(t <= 1.0f) || t < 0.0f) {
        return 0;
    }
    sceVu0ScaleVector(&d, &d, t);
    sceVu0AddVector(&h, p, &d);
    sceVu0AddVector(&hn, &h, n);
    sceVu0SubVector(&a1, v0, &h);
    a1.w = 0.0f;
    sceVu0SubVector(&b1, v1, v0);
    b1.w = 0.0f;
    sceVu0OuterProduct(&c1, &a1, &b1);
    c1.w = 0.0f;
    e1 = sceVu0InnerProduct(&c1, &hn) - sceVu0InnerProduct(&c1, &h);
    sceVu0SubVector(&a2, v1, &h);
    a2.w = 0.0f;
    sceVu0SubVector(&b2, v2, v1);
    b2.w = 0.0f;
    sceVu0OuterProduct(&c2, &a2, &b2);
    c2.w = 0.0f;
    e2 = sceVu0InnerProduct(&c2, &hn) - sceVu0InnerProduct(&c2, &h);
    sceVu0SubVector(&a3, v2, &h);
    a3.w = 0.0f;
    sceVu0SubVector(&b3, v0, v2);
    b3.w = 0.0f;
    sceVu0OuterProduct(&c3, &a3, &b3);
    c3.w = 0.0f;
    e3 = sceVu0InnerProduct(&c3, &hn) - sceVu0InnerProduct(&c3, &h);
    if (!(e1 < 0.0f || e2 < 0.0f || e3 < 0.0f) || (e1 < 0.0f && e2 < 0.0f && e3 < 0.0f)) {
        sceVu0CopyVector(out, &h);
        *(s32 *)&out->w = 0x3F800000;
        sceVu0CopyVector(out + 1, n);
        if (dist) {
            sceVu0SubVector(&h, p, out);
            h.w = 0.0f;
            *dist = sqrtf(sceVu0InnerProduct(&h, &h));
        }
        return 1;
    }
    return 0;
}
