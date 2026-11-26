#include "common.h"
void func_001029E8(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
f32 func_0015DF50(Vec *, Vec *);
void func_00102870(Vec *, Vec *);

void func_00150160(Vec *o, Vec *a, Vec *b) {
    Vec t;
    Vec u;
    Vec w;
    f32 r;
    func_001029E8(&t, b, a);
    func_00102A18(&t, &t, 0.5f);
    func_001029D0(o, a, &t);
    func_00102A18(&u, &a[1], a[1].w);
    func_001029D0(&u, &u, a);
    func_00102A18(&w, &b[1], b[1].w);
    func_001029D0(&w, &w, b);
    func_001029E8(&t, &w, &u);
    func_00102A18(&t, &t, 0.5f);
    func_001029D0(&o[1], &u, &t);
    r = func_0015DF50(&o[1], o);
    func_001029E8(&o[1], &o[1], o);
    func_00102870(&o[1], &o[1]);
    o[1].w = r;
    o->w = 1.2f * b->w;
}
