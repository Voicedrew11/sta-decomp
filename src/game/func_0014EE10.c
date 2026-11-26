#include "m2c.h"
f32 sceVu0InnerProduct(f32 *, f32 *);
void sceVu0SubVector(f32 *, s8 *, s8 *);
void sceVu0CopyVector(f32 *, s8 *);
f32 func_0015DF20(s8 *, s8 *);

s32 func_0014EE10(s8 *arg0, s8 *arg1) {
    f32 d[4];
    f32 e[4];
    f32 r;
    f32 len;
    f32 t;

    t = M2C_FIELD(arg0, f32 *, 0xC) + M2C_FIELD(arg1, f32 *, 0xC);
    r = t * t;
    if (M2C_FIELD(arg0, f32 *, 0x1C) <= 0.0f) {
        return func_0015DF20(arg1, arg0) <= r;
    }
    sceVu0SubVector(d, arg0, arg1);
    d[3] = 0;
    sceVu0CopyVector(e, arg0 + 0x10);
    e[3] = 0;
    len = sceVu0InnerProduct(e, e);
    if (len <= 0.0f) return 0;
    t = sceVu0InnerProduct(d, e) * sceVu0InnerProduct(d, e) / len;
    return sceVu0InnerProduct(d, d) - t <= r;
}
