#include "common.h"
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
f32 func_0015DF50(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);

void func_00150160(Vec *o, Vec *a, Vec *b) {
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
    r = func_0015DF50(&o[1], o);
    sceVu0SubVector(&o[1], &o[1], o);
    sceVu0Normalize(&o[1], &o[1]);
    o[1].w = r;
    o->w = 1.2f * b->w;
}
