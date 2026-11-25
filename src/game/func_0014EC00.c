#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec p; Vec d; } Seg;
void func_001029E8(Vec *, Seg *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102A60(Vec *, Vec *);
f32 func_0011D850(f32);
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
    func_00102A18(&sc, &c->d, l);
    if (!(func_0011D850(h) <= 1.0f)) {
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
    func_001029E8(&dv, c, v);
    dv.w = 0;
    dv.y = 0;
    func_00102A60(&ax, &c->d);
    ax.w = 0;
    ax.y = 0;
    len = func_00102848(&ax, &ax);
    if (len <= 0.0f) {
        return 0;
    }
    t = func_00102848(&dv, &ax);
    t = t * func_00102848(&dv, &ax) / len;
    return func_00102848(&dv, &dv) - t <= r2;
}
