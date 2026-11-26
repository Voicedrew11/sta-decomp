#include "common.h"

typedef struct {
    s32 state; char pad[0x2C];
    s32 x30; s32 x34; s32 x38; s32 x3c; s32 x40;
    s32 buf; s32 size; s32 pos; s32 x50; s32 x54;
} S;
s32 func_00116360(s32, s32, s32, ...);
s32 func_001EB540(s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_001EB8B0(S *s)
{
    s32 r;
    s32 src, n1, src2, n2;
    s32 b, t, d, m1, m2, q;
    r = 0;
    switch (s->state) {
    case 0:
        return 0;
    case 1:
        src = s->buf + s->x54 % s->size;
        n1 = s->size - s->x54;
        src2 = 0;
        n2 = 0;
        break;
    case 2:
        b = s->buf;
        t = func_00116360(1, 0x8100, 0, 0) & 0xFFFFFF;
        src = s->size;
        t -= b;
        t = (t + src - s->pos - 0x400) % src;
        t = t / 1024 * 1024;
        n1 = src - s->pos;
        if (!(n1 < t)) {
            src = b + s->pos;
            n1 = t;
            src2 = 0;
            n2 = 0;
        } else {
            src2 = s->buf;
            n2 = t - n1;
            src = src2 + s->pos;
        }
        break;
    case 3:
        return 0;
    }
    d = s->x30 + (s->x3c + (s->x34 - s->x38)) % s->x3c;
    q = s->x38 / 1024 * 1024;
    m1 = s->x30 + s->x3c - d;
    if (q < m1) m1 = q;
    m2 = q - m1;
    if (n1 + n2 >= 0x400 && m1 + m2 >= 0x400)
        r = func_001EB540(src, n1, src2, n2, d, m1, s->x30, m2);
    s->x38 -= r;
    s->x54 += r;
    s->pos = (s->pos + r) % s->size;
    return r;
}
