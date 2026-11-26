#include "m2c.h"
typedef struct { s32 i; s32 pad; } W;
typedef struct { f32 f; s32 pad; } F;
typedef struct { W x0; W x8; W x10; F v[15]; } Arg;
s16 func_001B0BC0(s32, s32);
f32 *func_0015B900(s32);

void func_0017ADE0(Arg *a) {
    f32 v3 = a->v[3].f;
    f32 v7 = a->v[7].f;
    f32 v8 = a->v[8].f;
    f32 v9 = a->v[9].f;
    f32 v10 = a->v[10].f;
    f32 v11 = a->v[11].f;
    f32 v12 = a->v[12].f;
    f32 v13 = a->v[13].f;
    f32 v0 = a->v[0].f;
    f32 v1 = a->v[1].f;
    f32 v2 = a->v[2].f;
    f32 v4 = a->v[4].f / 255.0f;
    f32 v5 = a->v[5].f / 255.0f;
    f32 v6 = a->v[6].f / 255.0f;
    s32 o = ((volatile Arg *)a)->x8.i;
    s32 b = ((volatile Arg *)a)->x10.i;
    f32 *d = func_0015B900(func_001B0BC0(o, b));
    if (d) {
        d[0] = v0;
        d[1] = v1;
        d[2] = v2;
        d[3] = v3;
        d[4] = v4;
        d[5] = v5;
        d[6] = v6;
        d[7] = v7;
        d[8] = v8;
        d[9] = v9;
        d[10] = v10;
        d[11] = v11;
        d[12] = v12;
        d[13] = v13;
    }
}
