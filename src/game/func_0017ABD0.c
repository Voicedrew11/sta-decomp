#include "m2c.h"
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; } Arg;
f32 *func_00165130(Arg *, s32);
s16 func_001B0BC0(s32, s32);
f32 *func_0015B900(s32);

void func_0017ABD0(Arg *a) {
    s32 o = a->x8;
    s32 b = a->x10;
    f32 *p2 = func_00165130(a, 2);
    f32 *p3 = func_00165130(a, 3);
    f32 *p4 = func_00165130(a, 4);
    f32 *p5 = func_00165130(a, 5);
    f32 *p6 = func_00165130(a, 6);
    f32 *p7 = func_00165130(a, 7);
    f32 *p8 = func_00165130(a, 8);
    f32 *p9 = func_00165130(a, 9);
    f32 *p10 = func_00165130(a, 10);
    f32 *p11 = func_00165130(a, 11);
    f32 *p12 = func_00165130(a, 12);
    f32 *p13 = func_00165130(a, 13);
    f32 *p14 = func_00165130(a, 14);
    f32 *p15 = func_00165130(a, 15);
    f32 *d = func_0015B900(func_001B0BC0(o, b));
    if (d) {
        *p2 = d[0];
        *p3 = d[1];
        *p4 = d[2];
        *p5 = d[3];
        *p6 = 255.0f * d[4];
        *p7 = 255.0f * d[5];
        *p8 = 255.0f * d[6];
        *p9 = d[7];
        *p10 = d[8];
        *p11 = d[9];
        *p12 = d[10];
        *p13 = d[11];
        *p14 = d[12];
        *p15 = d[13];
    }
}
