#include "common.h"
void func_001029E8(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102828(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
float sqrtf(float);

s32 func_0014F210(Vec *out, Vec *sph, Vec *tri, Vec *n, s32 a4, s32 a5, f32 *dist) {
    Vec p;
    Vec d;
    Vec e0;
    Vec e1;
    Vec e2;
    Vec c;
    Vec ed;
    Vec w;
    f32 dot;
    f32 r;
    f32 r2;
    f32 len;
    u8 i;
    Vec *v;
    f32 t;
    f32 d2;

    r = sph->w;
    func_001029E8(&d, tri, sph);
    dot = func_00102848(&d, n);
    if (dot < -r || !(dot <= 0.0f)) {
        return 0;
    }
    func_00102A18(&d, n, dot);
    func_001029D0(&p, sph, &d);
    func_001029E8(&e0, tri, &p);
    func_001029E8(&e1, tri + 1, &p);
    func_001029E8(&e2, tri + 2, &p);
    func_00102828(&c, &e0, &e1);
    func_00102828(&e1, &e1, &e2);
    if (func_00102848(&c, &e1) > 0.0f) {
        func_00102828(&c, &e2, &e0);
        if (func_00102848(&e1, &c) > 0.0f) {
            func_00102A60(out, &p);
            *(s32 *)&out->w = 0x3F800000;
            func_00102A60(out + 1, n);
            *dist = -dot;
            return 1;
        }
    }
    r2 = sph->w * sph->w;
    for (i = 0; i < 3; i++) {
        v = &tri[i % 3];
        func_001029E8(&ed, &tri[(i + 1) % 3], v);
        len = func_00102848(&ed, &ed);
        if (len > 0.0f) {
            func_001029E8(&w, sph, v);
            t = func_00102848(&w, &ed);
            if (!(t < 0.0f) && t <= len) {
                func_00102A18(out, &ed, t / len);
                func_001029D0(out, out, v);
                out->w = 1.0f;
                func_001029E8(out + 1, sph, out);
                d2 = func_00102848(out + 1, out + 1);
                *dist = d2;
                if (d2 <= r2) {
                    *dist = sqrtf(d2);
                    func_00102A18(out + 1, out + 1, 1.0f / *dist);
                    return 1;
                }
            }
        }
    }
    return 0;
}
