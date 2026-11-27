#include "common.h"

typedef struct { f32 a[6]; } M2;

M2 *Mtx2_Mul_1_001828F0(M2 *o, M2 *a, M2 *b)
{
    M2 t;
    t.a[0] = a->a[0] * b->a[0] + a->a[1] * b->a[2];
    t.a[2] = a->a[2] * b->a[0] + a->a[3] * b->a[2];
    t.a[1] = a->a[0] * b->a[1] + a->a[1] * b->a[3];
    t.a[3] = a->a[2] * b->a[1] + a->a[3] * b->a[3];
    *o = t;
    return o;
}
