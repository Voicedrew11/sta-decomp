#include "common.h"

typedef struct { f32 m[3][4]; f32 t[4]; } X;
void sceVu0CopyVector(f32 *v0, f32 *v1);
void func_0015EBB0(f32 (*m)[4], f32 *axis, f32 a);
void sceVu0MulMatrix(f32 (*m0)[4], f32 (*m1)[4], f32 (*m2)[4]);

void func_00145FB0(X *out, X *in)
{
    f32 m[4][4];
    f32 t[4];
    sceVu0CopyVector(t, in->t);
    func_0015EBB0(m, in->m[1], 3.1415927f);
    sceVu0MulMatrix((f32 (*)[4])out, m, (f32 (*)[4])in);
    sceVu0CopyVector(out->t, t);
}
