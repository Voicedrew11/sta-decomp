#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
f32 func_0015DF20(Vec *, Vec *);

s32 func_0014EF40(Vec *a, Vec *b, Vec *s, f32 r) {
    Vec p;
    Vec d;
    f32 len;
    f32 t;
    s32 v;

    func_001029E8(&d, b, a);
    len = func_00102848(&d, &d);
    t = s->w + r;
    r = t * t;
    if (len <= 0.0f) {
        return func_0015DF20(s, a) <= r;
    }
    func_001029E8(&p, s, a);
    t = func_00102848(&p, &d);
    if (!(t < 0.0f) && t <= len) {
        func_00102A18(&p, &d, t / len);
        func_001029D0(&p, &p, a);
        return func_0015DF20(s, &p) <= r;
    }
    if (!(func_0015DF20(s, a) <= r)) {
        return 0;
    }
    v = func_0015DF20(s, b) > r;
    return v ^ 1;
}
