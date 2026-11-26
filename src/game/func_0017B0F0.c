#include "m2c.h"
typedef struct { s32 x0, x4, h, xc, a, x14, b, x1c, c, x24; f32 t; s32 x2c, fl; } S;
f32 *func_001B19A0(s32);
f32 *func_001B40F0(f32 *, s32);
void func_001B4100(f32 *);

void func_0017B0F0(S *s) {
    f32 t = s->t;
    s32 b = s->b;
    s32 c = s->c;
    s32 fl = s->fl;
    f32 *d;
    f32 *q, *p;
    s32 h = s->h;
    f32 u = 1.0f - t;

    d = func_001B40F0(func_001B19A0(h), s->a);
    p = func_001B40F0(func_001B19A0(h), b);
    q = func_001B40F0(func_001B19A0(h), c);
    if (d != 0 && p != 0 && q != 0) {
        if (fl & 0x1) {
            d[16] = p[16] * u + q[16] * t;
            d[17] = p[17] * u + q[17] * t;
            d[18] = p[18] * u + q[18] * t;
            d[19] = p[19] * u + q[19] * t;
        }
        if (fl & 0x2) {
            d[4] = p[4] * u + q[4] * t;
            d[5] = p[5] * u + q[5] * t;
            d[6] = p[6] * u + q[6] * t;
            d[7] = p[7] * u + q[7] * t;
            d[0] = p[0] * u + q[0] * t;
            d[1] = p[1] * u + q[1] * t;
            d[2] = p[2] * u + q[2] * t;
            d[3] = p[3] * u + q[3] * t;
        }
        if (fl & 0x4) {
            d[12] = p[12] * u + q[12] * t;
            d[13] = p[13] * u + q[13] * t;
            d[14] = p[14] * u + q[14] * t;
            d[15] = p[15] * u + q[15] * t;
            d[8] = p[8] * u + q[8] * t;
            d[9] = p[9] * u + q[9] * t;
            d[10] = p[10] * u + q[10] * t;
            d[11] = p[11] * u + q[11] * t;
        }
        if (fl & 0x8) {
            d[20] = p[20] * u + q[20] * t;
        }
        if (fl & 0x10) {
            d[21] = p[21] * u + q[21] * t;
        }
        if (fl & 0x20) {
            d[22] = p[22] * u + q[22] * t;
        }
        if (fl & 0x40) {
            d[23] = p[23] * u + q[23] * t;
        }
        func_001B4100(func_001B19A0(h));
    }
}
