#include "common.h"
void Coll_ClosestPointA_0_00150020(Vec *o, Vec *p, Vec *q);
void Coll_ClosestPointB_0_00150160(Vec *o, Vec *a, Vec *b);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 Vec_DistB_3_0015DF50(Vec *, Vec *);

/* Coll_ClosestPointA_0_00150020 */
void Coll_ClosestPointA_0_00150020(Vec *o, Vec *p, Vec *q) {
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
    f = Vec_DistB_3_0015DF50(&o[1], o);
    sceVu0SubVector(&o[1], &o[1], o);
    sceVu0Normalize(&o[1], &o[1]);
    o[1].w = f;
    o[0].w = 1.2f * q[0].w;
}

/* Coll_ClosestPointB_0_00150160 */
void Coll_ClosestPointB_0_00150160(Vec *o, Vec *a, Vec *b) {
    Vec t;
    Vec u;
    Vec w;
    f32 r;
    sceVu0SubVector(&t, b, a);
    sceVu0ScaleVector(&t, &t, 0.5f);
    sceVu0AddVector(o, a, &t);
    sceVu0ScaleVector(&u, &a[1], a[1].w);
    sceVu0AddVector(&u, &u, a);
    sceVu0ScaleVector(&w, &b[1], b[1].w);
    sceVu0AddVector(&w, &w, b);
    sceVu0SubVector(&t, &w, &u);
    sceVu0ScaleVector(&t, &t, 0.5f);
    sceVu0AddVector(&o[1], &u, &t);
    r = Vec_DistB_3_0015DF50(&o[1], o);
    sceVu0SubVector(&o[1], &o[1], o);
    sceVu0Normalize(&o[1], &o[1]);
    o[1].w = r;
    o->w = 1.2f * b->w;
}
