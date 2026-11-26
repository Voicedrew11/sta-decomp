#include "m2c.h"
s8 *func_001B19A0(s32);
s8 *func_001B7300(s8 *, s32);

void func_0017BD70(s8 *arg0) {
    f32 t = *(f32 *)(arg0 + 0x28);
    s32 b = *(s32 *)(arg0 + 0x18);
    s32 c = *(s32 *)(arg0 + 0x20);
    s32 h = *(s32 *)(arg0 + 0x8);
    f32 u = 1.0f - t;
    f32 *d, *p, *q;
    d = (f32 *)func_001B7300(func_001B19A0(h), *(s32 *)(arg0 + 0x10));
    p = (f32 *)func_001B7300(func_001B19A0(h), b);
    q = (f32 *)func_001B7300(func_001B19A0(h), c);
    if (d != 0 && p != 0 && q != 0) {
        d[0] = p[0] * u + q[0] * t;
        d[1] = p[1] * u + q[1] * t;
        d[2] = p[2] * u + q[2] * t;
        d[3] = p[3] * u + q[3] * t;
        d[4] = p[4] * u + q[4] * t;
        d[5] = p[5] * u + q[5] * t;
        d[6] = p[6] * u + q[6] * t;
        d[7] = p[7] * u + q[7] * t;
        d[8] = p[8] * u + q[8] * t;
        d[9] = p[9] * u + q[9] * t;
        d[10] = p[10] * u + q[10] * t;
        d[11] = p[11] * u + q[11] * t;
        d[12] = p[12] * u + q[12] * t;
        d[13] = p[13] * u + q[13] * t;
    }
}
