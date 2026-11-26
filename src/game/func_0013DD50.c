#include "common.h"
f32 cosf(f32);
static inline f32 u2f(u32 x) { return x; }

void func_0013DD50(s8 *a0, f32 *a1, f32 *a2) {
    s8 *p = *(s8 **)(a0 + 0x4B0) + 0x270;
    if (a1) {
        *a1 = u2f(*(u16 *)(p + 0x10));
    }
    if (a2) {
        *a2 = cosf(3.1415927f * (u2f(*(u16 *)(p + 0x12)) / 180.0f));
    }
}
