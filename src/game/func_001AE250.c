#include "m2c.h"
typedef struct { f32 p0[4]; f32 p1[4]; } Ray;
typedef struct { f32 x0; f32 x4; s32 pad8[7]; s32 hit; s32 pad28[6]; } Res;
void sceVu0CopyVector(f32 *, f32 *);
void memset(void *, s32, s32);
void func_001B2180(s32, Res *, Ray *, s32, s32);
extern s32 D_00201E80;

s32 func_001AE250(s32 arg0, f32 *pos, f32 *out) {
    Res res;
    Ray ray;
    s32 i;
    s32 side;

    side = 0;
    sceVu0CopyVector(ray.p0, pos);
    ray.p0[3] = 1.0f;
    sceVu0CopyVector(ray.p1, ray.p0);
    ray.p1[1] += 60000.0f;
    memset(&res, 0, 0x40);
    if (arg0 == (&D_00201E80)[2]) {
        side = 0;
    }
    if (arg0 == (&D_00201E80)[3]) {
        side = 1;
    }
    for (i = 0; i < 2; i++) {
        s32 *p = ((s32 **)(&D_00201E80 + 2))[side];
        if (p != 0) {
            func_001B2180(*p, &res, &ray, 6, 3);
            if (res.hit != 0) {
                *out = res.x4;
                return 1;
            }
        }
        side = !side;
    }
    return 0;
}
