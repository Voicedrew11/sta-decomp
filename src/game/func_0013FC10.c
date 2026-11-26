#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
f32 func_0011DBC0(f32, f32);
f32 func_0013FC10(Vec *v) {
    f32 a = func_0011DBC0(v->x, v->z) + 3.1415927f;
    return WRAP(a);
}
