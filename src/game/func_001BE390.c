#include "m2c.h"
typedef struct { f32 a[4]; f32 b[4]; } Ray;
typedef struct { s32 w[16]; } Res;
void sceVu0CopyVector(f32 *, s8 *);
void memset(void *, s32, s32);
s32 func_001B2800(s8 *, Res *, Ray *, u16, s32, s32);
s32 func_001B3240(s32, Res *, Ray *, s32, s32);
extern s32 D_00201E80;

s32 func_001BE390(s8 *a0) {
    Ray ray;
    Res res;
    s32 j;
    s8 *o;
    s32 i;
    s8 ***pp;
    s32 **q;
    s8 *p;

    p = *(s8 **)(a0 + 0x518) + 0x180;
    sceVu0CopyVector(ray.a, p + 0x40);
    ray.a[3] = 1.0f;
    sceVu0CopyVector(ray.b, p + 0x40);
    ray.b[3] = 1.0f;
    ray.a[1] = *(f32 *)(*(s8 **)(p + 0x10) + 0x14);
    ray.b[1] += 220.0f;
    memset(&res, 0, 0x40);
    for (i = 0, q = (s32 **)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && func_001B3240(**q, &res, &ray, 8, 1) != 0) {
            return 1;
        }
    }
    for (i = 0, pp = (s8 ***)(&D_00201E80 + 2); i < 2; i++, pp++) {
        if (*pp != 0) {
            o = **pp;
            if (o != 0) {
                for (j = 0; j < *(u16 *)(o + 0x6E); j++) {
                    if (!func_001B2800(o, &res, &ray, j, 8, 1) == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
