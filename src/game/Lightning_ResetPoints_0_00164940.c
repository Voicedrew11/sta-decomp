#include "common.h"
f32 sqrtf(f32);
extern Vec D_0033E500[];

void Lightning_ResetPoints_0_00164940(void) {
    s16 i;
    Vec *p;
    s16 j;
    f32 x;
    f32 z;
    f32 y;
    f32 zz;
    f32 d;
    f32 xx;
    f32 nx;
    f32 l;
    f32 s;

    p = D_0033E500;
    for (i = 0; i < 16; i++) {
        x = 2.0f * ((f32)i / 16.0f) - 1.0f;
        xx = x * x;
        for (j = 0; j < 16; j++) {
            z = 2.0f * ((f32)j / 16.0f) - 1.0f;
            zz = z * z;
            d = 1.0f - zz - xx;
            if (!(d <= 0.0f)) {
                y = sqrtf(d);
                nx = x;
            } else {
                l = sqrtf(zz + xx);
                z = z / l;
                nx = x / l;
                y = 0.0f;
            }
            s = 2.0f * y;
            p->x = -(s * z);
            p->y = -(s * nx);
            p->z = -(s * y - 1.0f);
            *(s32 *)&p->w = 0;
            p++;
        }
    }
}
