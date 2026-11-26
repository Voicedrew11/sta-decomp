#include "common.h"
typedef struct { Vec p; Vec d; } Seg;
void sceVu0SubVector(Vec *, Seg *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(Vec *, Vec *);
f32 fabsf(f32);
f32 func_0015DEB0(Vec *, Seg *);

s32 func_0014EC00(Seg *c, Vec *v, f32 r, f32 h) {
    Vec sc;
    Vec dv;
    Vec ax;
    f32 t;
    f32 l;
    f32 r2;
    f32 len;
    f32 lo;
    f32 hi;
    f32 a;
    f32 b;

    l = c->d.w;
    t = c->p.w + r;
    r2 = t * t;
    if (l <= 0.0f) {
        return func_0015DEB0(v, c) <= r2;
    }
    sceVu0ScaleVector(&sc, &c->d, l);
    if (!(fabsf(h) <= 1.0f)) {
        if (!(sc.y < 0.0f)) {
            lo = c->p.y - c->p.w;
            hi = c->p.w + (c->p.y + sc.y);
        } else {
            lo = (c->p.y + sc.y) - c->p.w;
            hi = c->p.y + c->p.w;
        }
        if (!(h < 0.0f)) {
            b = v->y;
            a = b - h;
        } else {
            a = v->y;
            b = a - h;
        }
        if ((a < lo && b < lo) || (!(a <= hi) && !(b <= hi))) {
            return 0;
        }
    }
    sceVu0SubVector(&dv, c, v);
    dv.w = 0;
    dv.y = 0;
    sceVu0CopyVector(&ax, &c->d);
    ax.w = 0;
    ax.y = 0;
    len = sceVu0InnerProduct(&ax, &ax);
    if (len <= 0.0f) {
        return 0;
    }
    t = sceVu0InnerProduct(&dv, &ax);
    t = t * sceVu0InnerProduct(&dv, &ax) / len;
    return sceVu0InnerProduct(&dv, &dv) - t <= r2;
}
