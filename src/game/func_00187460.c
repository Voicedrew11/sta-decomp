#include "common.h"

f32 func_0011D4A8(f32 x);

f32 func_00187460(f32 *a, f32 *b)
{
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 r;
    if (0.0f == dx)
        r = 0.0f;
    else
        r = func_0011D4A8(dx / dy);
    if (dy < 0.0f)
        r += 3.141592f;
    return r;
}
