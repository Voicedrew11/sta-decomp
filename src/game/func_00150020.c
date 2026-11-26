#include "common.h"
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void func_00102870(Vec *, Vec *);
f32 func_0015DF50(Vec *, Vec *);

void func_00150020(Vec *o, Vec *p, Vec *q) {
    Vec m;
    Vec a;
    Vec b;
    f32 f;
    sceVu0SubVector(&m, q, p);
    sceVu0ScaleVector(&m, &m, 0.5f);
    sceVu0AddVector(o, p, &m);
    sceVu0ScaleVector(&a, &p[1], p[1].w);
    sceVu0AddVector(&a, &a, p);
    sceVu0ScaleVector(&b, &q[1], q[1].w);
    sceVu0AddVector(&b, &b, q);
    sceVu0SubVector(&m, &b, &a);
    sceVu0ScaleVector(&m, &m, 0.5f);
    sceVu0AddVector(&o[1], &a, &m);
    f = func_0015DF50(&o[1], o);
    sceVu0SubVector(&o[1], &o[1], o);
    func_00102870(&o[1], &o[1]);
    o[1].w = f;
    o[0].w = 1.2f * q[0].w;
}
