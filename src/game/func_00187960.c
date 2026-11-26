#include "common.h"
f32 fabsf(f32);
f32 sinf(f32);
void func_00187960(u8 *p, f32 f) {
    s32 v = 96.0f + fabsf(128.0f * sinf(0.05f * f));
    p[0] = p[0] * v / 128;
    p[1] = p[1] * v / 128;
    p[2] = p[2] * v / 128;
}
