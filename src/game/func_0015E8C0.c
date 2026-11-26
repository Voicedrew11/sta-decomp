#include "common.h"
void sceVu0Normalize(Vec *, Vec *);
void sceVu0InterVector(Vec *, Vec *, Vec *, f32);
void func_0015E8C0(Mtx *d, Mtx *a, Mtx *b, f32 t) {
    sceVu0InterVector(&d->m[0], &a->m[0], &b->m[0], t);
    sceVu0InterVector(&d->m[1], &a->m[1], &b->m[1], t);
    sceVu0InterVector(&d->m[2], &a->m[2], &b->m[2], t);
    sceVu0InterVector(&d->m[3], &a->m[3], &b->m[3], t);
    sceVu0Normalize(&d->m[0], &d->m[0]);
    sceVu0Normalize(&d->m[1], &d->m[1]);
    sceVu0Normalize(&d->m[2], &d->m[2]);
    d->m[3].w = 1.0f;
}
