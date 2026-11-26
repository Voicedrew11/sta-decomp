#include "common.h"
void sceVu0SubVector(Vec *, Vec *, void *);
void sceVu0Normalize(Vec *, Vec *);
f32 atan2f(f32, f32);
f32 asinf(f32);
void sceVu0RotMatrixY(s32, void *, f32);
extern f32 D_001F2150[];
extern f32 D_001F2154[];
extern f32 D_001F2158[];
extern s8 D_001F2160[];
extern s8 D_001F2170[];

void func_00146140(s32 arg0, f32 x, f32 z) {
    volatile f32 d2;
    Vec v;
    Vec r;
    f32 a;
    f32 b;
    f32 d;
    f32 e;

    v.x = x;
    v.w = 1.0f;
    v.z = z;
    v.y = 0.0f;
    sceVu0SubVector(&r, &v, D_001F2160);
    sceVu0Normalize(&r, &r);
    a = atan2f(D_001F2150[0], D_001F2158[0]);
    asinf(D_001F2154[0]);
    b = atan2f(r.x, r.z);
    asinf(r.y);
    d = b - a;
    d = d - 6.2831855f * (s32)(d / 6.2831855f);
    if (d > 3.1415927f) {
        d -= 6.2831855f;
    } else if (d < -3.1415927f) {
        d += 6.2831855f;
    }
    d2 = d;
    e = 3.1415927f + d;
    sceVu0RotMatrixY(arg0, D_001F2170, (e - 6.2831855f * (s32)(0.15915494f * e)) + (e < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f);
}
