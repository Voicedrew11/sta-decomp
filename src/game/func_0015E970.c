#include "common.h"
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0InterVector(Vec *, Vec *, Vec *, f32);
void sceVu0ScaleVector(Vec *, Vec *, f32);
float sqrtf(float);

void func_0015E970(Vec *out, Vec *a, Vec *b, f32 t) {
    Vec la, lb, ls;
    la.x = sqrtf(sceVu0InnerProduct(&a[0], &a[0]));
    la.y = sqrtf(sceVu0InnerProduct(&a[1], &a[1]));
    la.z = sqrtf(sceVu0InnerProduct(&a[2], &a[2]));
    lb.x = sqrtf(sceVu0InnerProduct(&b[0], &b[0]));
    lb.y = sqrtf(sceVu0InnerProduct(&b[1], &b[1]));
    lb.z = sqrtf(sceVu0InnerProduct(&b[2], &b[2]));
    sceVu0InterVector(&ls, &la, &lb, t);
    sceVu0InterVector(&out[0], &a[0], &b[0], t);
    sceVu0InterVector(&out[1], &a[1], &b[1], t);
    sceVu0InterVector(&out[2], &a[2], &b[2], t);
    sceVu0InterVector(&out[3], &a[3], &b[3], t);
    out[3].w = 1.0f;
    sceVu0Normalize(&out[0], &out[0]);
    sceVu0Normalize(&out[1], &out[1]);
    sceVu0Normalize(&out[2], &out[2]);
    sceVu0ScaleVector(&out[0], &out[0], ls.x);
    sceVu0ScaleVector(&out[1], &out[1], ls.y);
    sceVu0ScaleVector(&out[2], &out[2], ls.z);
}
