#include "m2c.h"
f32 func_00102848(f32 *, f32 *);
void func_001029E8(f32 *, s8 *, s8 *);
void func_00102A60(f32 *, s8 *);
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
    func_001029E8(d, arg0, arg1);
    d[3] = 0;
    func_00102A60(e, arg0 + 0x10);
    e[3] = 0;
    len = func_00102848(e, e);
    if (len <= 0.0f) return 0;
    t = func_00102848(d, e) * func_00102848(d, e) / len;
    return func_00102848(d, d) - t <= r;
}
