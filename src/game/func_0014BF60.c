#include "common.h"
s32 func_001470F0(Vec *, Vec *, s32, u8, s32, Vec *);

void func_0014BF60(f32 *o) {
    s32 fl;
    Vec a;
    Vec b;
    f32 z;
    fl = 0;
    if (o[0x19] == 0.0f) fl = 0x80;
    if (o[0x19] == 1.0f) fl = 4;
    if (o[0x19] == 2.0f) fl = 0x84;
    z = 0.0f;
    a.x = o[0];
    a.y = o[1] - z;
    a.z = o[2];
    b.x = o[0];
    b.y = o[1] + (z = 10000.0f);
    b.z = o[2];
    b.w = 1.0f;
    a.w = 1.0f;
    o[0x2F] = func_001470F0(&a, &b, 1, fl, 1, (Vec *)(o + 0x2C));
}
