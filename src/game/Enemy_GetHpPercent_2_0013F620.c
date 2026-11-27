#include "common.h"
static inline f32 u2f(u32 x) { return x; }

u32 Enemy_GetHpPercent_2_0013F620(s8 *a0) {
    f32 a = u2f(*(u16 *)(*(s8 **)(a0 + 0x518) + 0x16C));
    f32 b = u2f(**(u16 **)(a0 + 0x4B0));
    return 0.5f + 100.0f * (a / b);
}
