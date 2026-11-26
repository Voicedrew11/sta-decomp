#include "actor.h"
u8 func_0013FC00(Actor *);
s32 func_0013FB90(Actor *, u8, Vec **, Vec **);
s32 func_0013EE30(Actor *);
Vec *func_00140460(Actor *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void func_00102870(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(f32);
static inline s32 hit(f32 g) { return g <= 0.0f; }
static inline f32 u2f(u32 x) { return x; }

s32 func_00138460(Actor *a, Actor *b, Vec *out) {
    Vec *p[4];
    Vec *p2[4];
    Vec *q[4];
    Vec *q2[4];
    Vec d;
    Vec e;
    Vec c;
    Vec m;
    Vec h;
    u8 n0;
    u8 n1;
    u8 i;
    u8 k;
    u32 steps;
    u32 j;
    f32 len;
    f32 t;
    f32 r;
    f32 g;
    f32 f;
    Vec *pa;
    Vec *pb;

    n0 = func_0013FC00(a);
    n1 = func_0013FC00(b);
    for (i = 0; i < n0; i++) {
        func_0013FB90(a, i, p, q);
        sceVu0SubVector(&d, p[0], q[0]);
        len = sqrtf(sceVu0InnerProduct(&d, &d));
        t = 0.9f * p[0]->w;
        if (!(len <= t)) {
            steps = (u32)(len / t) + 1;
            if (steps > 6) {
                func_0013EE30(a);
                steps = 6;
            }
            for (k = 0; k < n1; k++) {
                func_0013FB90(b, k, p2, q2);
                r = p[0]->w + p2[0]->w;
                for (j = 0; j < steps; j = (u8)(j + 1)) {
                    f = u2f(j) / u2f(steps);
                    sceVu0ScaleVector(&c, &d, f);
                    sceVu0AddVector(&c, &c, q[0]);
                    sceVu0SubVector(&e, p2[0], &c);
                    g = sqrtf(sceVu0InnerProduct(&e, &e)) - r;
                    if (!(g <= 0.0f) == 0) {
                        pa = func_00140460(a);
                        pb = func_00140460(b);
                        sceVu0ScaleVector(&m, &d, f - 1.0f);
                        sceVu0AddVector(out, pa, &m);
                        sceVu0SubVector(out, pb, out);
                        func_00102870(out, out);
                        sceVu0ScaleVector(out, out, g * p[0]->w / r);
                        sceVu0AddVector(out, out, &m);
                        *(s32 *)&out->w = 0;
                        return 1;
                    }
                }
            }
        } else {
            for (k = 0; k < n1; k++) {
                func_0013FB90(b, k, p2, q2);
                r = p[0]->w + p2[0]->w;
                sceVu0SubVector(&h, p2[0], p[0]);
                t = sqrtf(sceVu0InnerProduct(&h, &h)) - r;
                if (!(t <= 0.0f) == 0) {
                    pa = func_00140460(a);
                    pb = func_00140460(b);
                    sceVu0SubVector(out, pb, pa);
                    func_00102870(out, out);
                    out->x *= t * p[0]->w / r;
                    out->y *= t * p[0]->w / r;
                    out->z *= t * p[0]->w / r;
                    *(s32 *)&out->w = 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}
