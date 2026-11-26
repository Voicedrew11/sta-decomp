#include "common.h"
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
f32 func_0015DF20(Vec *, Vec *);

s32 func_0014EF40(Vec *a, Vec *b, Vec *s, f32 r) {
    Vec p;
    Vec d;
    f32 len;
    f32 t;
    s32 v;

    sceVu0SubVector(&d, b, a);
    len = sceVu0InnerProduct(&d, &d);
    t = s->w + r;
    r = t * t;
    if (len <= 0.0f) {
        return func_0015DF20(s, a) <= r;
    }
    sceVu0SubVector(&p, s, a);
    t = sceVu0InnerProduct(&p, &d);
    if (!(t < 0.0f) && t <= len) {
        sceVu0ScaleVector(&p, &d, t / len);
        sceVu0AddVector(&p, &p, a);
        return func_0015DF20(s, &p) <= r;
    }
    if (!(func_0015DF20(s, a) <= r)) {
        return 0;
    }
    v = func_0015DF20(s, b) > r;
    return v ^ 1;
}
