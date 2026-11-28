#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
f32 atan2f(f32, f32);
f32 Vec_YawAngle_2_0013FC10(Vec *v) {
    f32 a = atan2f(v->x, v->z) + 3.1415927f;
    return WRAP(a);
}
