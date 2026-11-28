#include "common.h"
void sceVu0SubVector(Vec *, f32 *, f32 *);
void sceVu0Normalize(Vec *, Vec *);
f32 atan2f(f32, f32);
f32 asinf(f32);

void Vec_GetYawPitchBetween_1_00146310(f32 *p0, f32 *p1, f32 *p2, f32 *o1, f32 *o2) {
    Vec r;
    f32 a, c, b, e, d, w;

    sceVu0SubVector(&r, p2, p0);
    sceVu0Normalize(&r, &r);
    a = atan2f(p1[0], p1[2]);
    c = -asinf(p1[1]);
    b = atan2f(r.x, r.z);
    e = -asinf(r.y);
    if (o1 != NULL) {
        d = b - a;
        w = d - 6.2831855f * (s32)(d / 6.2831855f);
        if (w > 3.1415927f) {
            w -= 6.2831855f;
        } else if (w < -3.1415927f) {
            w += 6.2831855f;
        }
        *o1 = w;
    }
    if (o2 != NULL) {
        d = e - c;
        w = d - 6.2831855f * (s32)(d / 6.2831855f);
        if (w > 3.1415927f) {
            w -= 6.2831855f;
        } else if (w < -3.1415927f) {
            w += 6.2831855f;
        }
        *o2 = w;
    }
}
