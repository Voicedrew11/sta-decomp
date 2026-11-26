#include "common.h"

f32 sinf(f32 x);
f32 fabsf(f32 x);

void func_00187A20(u8 *c, f32 t)
{
    s32 k = fabsf(128.0f * sinf(0.05f * t));
    c[3] = c[3] * k / 128;
}
