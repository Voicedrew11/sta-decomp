#include "common.h"

void sceVu0CopyMatrix(f32 (*m0)[4], f32 (*m1)[4]);

void Sfx_GetMatrix_1_001676E0(void *src, f32 (*dst)[4])
{
    f32 (*m)[4] = src;
    if (src)
        sceVu0CopyMatrix(dst, m);
}
