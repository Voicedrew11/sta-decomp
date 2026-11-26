#include "common.h"

typedef struct { f32 a[8]; f32 v[4]; f32 b[4]; } T;
void func_00146600(void *a, T *t);
void sceVu0CopyVector(f32 *v0, f32 *v1);
void sceVu0Normalize(f32 *v0, f32 *v1);

void func_00146570(void *a, f32 *v)
{
    T t;
    func_00146600(a, &t);
    sceVu0CopyVector(v, t.v);
    v[1] = 0.0f;
    sceVu0Normalize(v, v);
}
