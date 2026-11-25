#include "common.h"

s32 func_001AB500(u16 *a, u16 *b) {
    f32 sum = 0.0f;
    f32 v;
    s32 i;
    for (i = 0; i < 3; i++) {
        v = (f32)a[i] * (200.0f - (f32)b[i + 1]) / 200.0f;
        if (v > 0.0f) sum += v;
    }
    for (i = 3; i < 6; i++) {
        v = (f32)a[i] * (200.0f - (f32)b[i + 2]) / 200.0f;
        if (v > 0.0f) sum += v;
    }
    return sum;
}
