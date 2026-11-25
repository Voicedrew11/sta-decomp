#include "actor.h"
extern s8 D_001F2160[];
extern f32 D_001F2170[];
void func_00146310(f32 *, f32 *, s8 *, f32 *, f32 *);
f32 func_0011D850(f32);
void func_00102C20(f32 (*)[4], f32 *, f32);
void func_00102CC8(f32 (*)[4], f32 (*)[4], f32);
void func_00102A70(f32 (*)[4], f32 *);
void func_00102A60(f32 *, f32 *);
void func_001027E0(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

inline s32 has(void) {
    s32 r = 0;
    if (D_002022E4 != NULL && D_002022E4->unk518 != NULL) {
        r = 1;
    }
    return r;
}

inline s32 sgn(f32 v) {
    s32 s = 1;
    if (v < 0.0f) {
        s = -1;
    }
    return s;
}

void func_00167310(f32 *m, f32 mx, f32 my) {
    f32 a;
    f32 b;
    f32 t[4][4] __attribute__((aligned(16)));
    f32 r[4][4] __attribute__((aligned(16)));
    f32 x;
    f32 y;
    s32 s;

    if (m != NULL) {
        func_00146310(m + 12, m + 8, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160, &a, &b);
        x = a;
        x = func_0011D850(x) < mx ? x : mx * sgn(x);
        y = b;
        y = func_0011D850(y) < my ? y : my * sgn(y);
        func_00102C20(r, D_001F2170, WRAP(y));
        func_00102CC8(r, r, WRAP(x));
        func_00102A70(t, m);
        func_00102A60(t[3], (f32 *)D_001F2160);
        func_001027E0(t, t, r);
        func_00102A60(m, t[0]);
        func_00102A60(m + 4, t[1]);
        func_00102A60(m + 8, t[2]);
    }
}
