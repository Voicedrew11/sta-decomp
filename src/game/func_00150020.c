#include "common.h"
void func_00102A18(Vec *, Vec *, f32);
void func_001029E8(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102870(Vec *, Vec *);
f32 func_0015DF50(Vec *, Vec *);

void func_00150020(Vec *o, Vec *p, Vec *q) {
    Vec m;
    Vec a;
    Vec b;
    f32 f;
    func_001029E8(&m, q, p);
    func_00102A18(&m, &m, 0.5f);
    func_001029D0(o, p, &m);
    func_00102A18(&a, &p[1], p[1].w);
    func_001029D0(&a, &a, p);
    func_00102A18(&b, &q[1], q[1].w);
    func_001029D0(&b, &b, q);
    func_001029E8(&m, &b, &a);
    func_00102A18(&m, &m, 0.5f);
    func_001029D0(&o[1], &a, &m);
    f = func_0015DF50(&o[1], o);
    func_001029E8(&o[1], &o[1], o);
    func_00102870(&o[1], &o[1]);
    o[1].w = f;
    o[0].w = 1.2f * q[0].w;
}
