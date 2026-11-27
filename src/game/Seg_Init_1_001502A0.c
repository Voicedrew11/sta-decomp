#include "common.h"

typedef struct { f32 a[4]; f32 b[4]; } R;
void sceVu0CopyVector(f32 *v0, f32 *v1);
void sceVu0SubVector(f32 *v0, f32 *v1, f32 *v2);
f32 sceVu0InnerProduct(f32 *v0, f32 *v1);
void sceVu0ScaleVector(f32 *v0, f32 *v1, f32 s);
f32 sqrtf(f32 x);

void Seg_Init_1_001502A0(R *r, f32 *from, f32 *to, f32 w)
{
    f32 len;
    sceVu0CopyVector(r->a, from);
    sceVu0SubVector(r->b, to, from);
    len = sqrtf(sceVu0InnerProduct(r->b, r->b));
    sceVu0ScaleVector(r->b, r->b, 1.0f / len);
    r->a[3] = w;
    r->b[3] = len;
}
