#include "m2c.h"
typedef struct { u16 v[6]; f32 xC; } P;
s32 func_001CD450(s32, u8 *, s32, s32);
s32 func_00125538(void);
static inline f32 u2f(u32 x) { return x; }

s32 func_001AB2C0(P *a0, u16 *a1, s32 a2) {
    s32 i;
    f32 s1;
    f32 s2;
    f32 v;
    f32 r;
    u8 b;
    s1 = 0.0f;
    s2 = 0.0f;
    for (i = 0; i < 3; i++) {
        v = u2f(a0->v[i]) * (200.0f - u2f(a1[i + 1])) / 200.0f;
        if (v > 0.0f) s1 += v;
    }
    for (i = 3; i < 6; i++) {
        v = u2f(a0->v[i]) * (200.0f - u2f(a1[i + 2])) / 200.0f;
        if (v > 0.0f) s2 += v;
    }
    if (a2) s1 *= 0.3f;
    else s2 *= 0.3f;
    r = s1 + s2;
    if (!a2) r *= a0->xC;
    if (func_001CD450(0xE, &b, 1, 1)) {
        if (func_00125538() % 100 < b) r *= 1.5f;
    }
    return r;
}
