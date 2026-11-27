#include "common.h"
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
float sqrtf(float);

s32 Coll_SphereVsTriangle_1_0014F210(Vec *out, Vec *sph, Vec *tri, Vec *n, s32 a4, s32 a5, f32 *dist) {
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
    sceVu0SubVector(&d, tri, sph);
    dot = sceVu0InnerProduct(&d, n);
    if (dot < -r || !(dot <= 0.0f)) {
        return 0;
    }
    sceVu0ScaleVector(&d, n, dot);
    sceVu0AddVector(&p, sph, &d);
    sceVu0SubVector(&e0, tri, &p);
    sceVu0SubVector(&e1, tri + 1, &p);
    sceVu0SubVector(&e2, tri + 2, &p);
    sceVu0OuterProduct(&c, &e0, &e1);
    sceVu0OuterProduct(&e1, &e1, &e2);
    if (sceVu0InnerProduct(&c, &e1) > 0.0f) {
        sceVu0OuterProduct(&c, &e2, &e0);
        if (sceVu0InnerProduct(&e1, &c) > 0.0f) {
            sceVu0CopyVector(out, &p);
            *(s32 *)&out->w = 0x3F800000;
            sceVu0CopyVector(out + 1, n);
            *dist = -dot;
            return 1;
        }
    }
    r2 = sph->w * sph->w;
    for (i = 0; i < 3; i++) {
        v = &tri[i % 3];
        sceVu0SubVector(&ed, &tri[(i + 1) % 3], v);
        len = sceVu0InnerProduct(&ed, &ed);
        if (len > 0.0f) {
            sceVu0SubVector(&w, sph, v);
            t = sceVu0InnerProduct(&w, &ed);
            if (!(t < 0.0f) && t <= len) {
                sceVu0ScaleVector(out, &ed, t / len);
                sceVu0AddVector(out, out, v);
                out->w = 1.0f;
                sceVu0SubVector(out + 1, sph, out);
                d2 = sceVu0InnerProduct(out + 1, out + 1);
                *dist = d2;
                if (d2 <= r2) {
                    *dist = sqrtf(d2);
                    sceVu0ScaleVector(out + 1, out + 1, 1.0f / *dist);
                    return 1;
                }
            }
        }
    }
    return 0;
}
