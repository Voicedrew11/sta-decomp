#include "m2c.h"
extern s32 Rand_Next_3_0015ED20(void);
extern f32 cosf(f32);
extern f32 sinf(f32);
extern void sceVu0AddVector(f32 *, f32 *, f32 *);

void FxProc_RandomRingPos_0_0014AD90(f32 *a0) {
    f32 v[4];
    f32 r = a0[0x50 / 4];
    f32 h = a0[0x54 / 4];
    f32 ang = 6.2831855f * (0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20() & 0xFFFF));
    r *= 0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20() & 0xFFFF);
    v[0] = r * cosf(ang);
    v[2] = r * sinf(ang);
    v[1] = h * (1.0f - 2.0f * (0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20() & 0xFFFF)));
    v[3] = 0.0f;
    sceVu0AddVector(a0, a0, v);
}
