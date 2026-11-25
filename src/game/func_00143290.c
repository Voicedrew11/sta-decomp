#include "common.h"

void sceVu0SubVector(f32 *v0, f32 *v1, f32 *v2);
void func_001432F0(void *a, f32 *v, s32 c, s32 d);

void func_00143290(void *a, f32 *b, f32 *c, s32 d, s32 e)
{
    f32 v[4];
    sceVu0SubVector(v, c, b);
    func_001432F0(a, v, d, e);
}
