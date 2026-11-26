#include "common.h"
typedef struct { f32 a; f32 b; } P;
typedef struct { char p[0x154]; s32 x154; } S;
typedef struct { char p[8]; u16 x8; char p2[6]; u8 x10; } A;
s32 func_001315A0(s32 a, s32 b, f32 *v);
f32 *func_0013FFA0(s32, S *);
void sceVu0CopyVector(f32 *, f32 *);
void func_00131180(s32, P *);
extern P D_00201C50;
extern S *D_00201FA8;
void func_001453A0(A *a) {
    S *s;
    u16 h;
    u8 b;
    f32 v[4];
    P p;
    s32 k;
    s = D_00201FA8;
    k = s->x154;
    h = a->x8;
    b = a->x10;
    p = D_00201C50;
    sceVu0CopyVector(v, func_0013FFA0(k, s));
    func_00131180(func_001315A0(h, b, v), &p);
}

