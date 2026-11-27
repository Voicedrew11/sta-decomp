#include "m2c.h"
extern s32 Rand_Next_3_0015ED20(void);
extern f32 func_0011DBF0(f32, f32);
static inline f32 sq(f32 v) { f32 r; asm("sqrt.s %0, %1" : "=f"(r) : "f"(v)); return r; }
#define R (0.000015259022f * (f32)(u32)(RND & 0xFFFF) - 0.5f)
#define RND (Rand_Next_3_0015ED20)()

void Fx_RandomInSphere_0_00163A10(f32 *out, f32 a, f32 b) {
    f32 x, y, z, d, s;
    f32 aa = a * a; f32 a2 = 2.0f * a; do { x = a2 * R; y = a2 * R; z = a2 * R; d = x * x + y * y + z * z; } while (d > aa + 0.01f);

    if (b != 1.0f && !(a <= 0.01f)) {
        s = func_0011DBF0(sq(d) / a, b);
        x *= s; y *= s; z *= s;
    }
    out[0] = x; out[1] = y; out[2] = z; out[3] = 0.0f;
}
