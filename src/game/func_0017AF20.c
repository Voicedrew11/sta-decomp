#include "common.h"
f32 *func_00165130(void *, s32);
s32 func_001B0C70(s32, s32);
void func_0015D760(u16, Vec *, Vec *, f32 *, f32 *);

void func_0017AF20(s32 *a0) {
    s32 x8 = a0[2];
    s32 x10 = a0[4];
    f32 *p2 = func_00165130(a0, 2);
    f32 *p3 = func_00165130(a0, 3);
    f32 *p4 = func_00165130(a0, 4);
    f32 *p5 = func_00165130(a0, 5);
    f32 *p6 = func_00165130(a0, 6);
    f32 *p7 = func_00165130(a0, 7);
    f32 *p8 = func_00165130(a0, 8);
    f32 *p9 = func_00165130(a0, 9);
    Vec a;
    Vec b;
    func_0015D760(func_001B0C70(x8, x10), &a, &b, p8, p9);
    *p2 = a.x;
    *p3 = a.y;
    *p4 = a.z;
    *p5 = b.x;
    *p6 = b.y;
    *p7 = b.z;
}
