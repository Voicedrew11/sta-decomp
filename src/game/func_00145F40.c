#include "common.h"

void func_001465C0(void *a, f32 *v);
f32 atan2f(f32 y, f32 x);
f32 asinf(f32 x);

void func_00145F40(void *a, f32 *yaw, f32 *pitch)
{
    f32 v[4];
    func_001465C0(a, v);
    if (yaw)
        *yaw = atan2f(v[0], v[2]);
    if (pitch)
        *pitch = -asinf(v[1]);
}
