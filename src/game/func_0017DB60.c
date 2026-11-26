#include "common.h"
typedef struct { char p[8]; f32 x8; char p2[4]; f32 x10; char p3[4]; f32 x18; char p4[4]; f32 x20; char p5[4]; f32 x28; char p6[4]; s32 x30; } A;
void func_0015FD90(f32, f32, f32, f32, f32);
void func_0015FE20(f32, f32, f32, f32, f32);
void func_0017DB60(A *a) {
    s32 m = a->x30;
    f32 f = a->x8;
    f32 e = a->x10;
    f32 d = a->x18;
    f32 c = a->x20;
    f32 b = a->x28;
    if (m == 0) func_0015FE20(f, e, d, c, b);
    if (m == 1) func_0015FD90(f, e, d, c, b);
}
