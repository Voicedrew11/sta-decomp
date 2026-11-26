#include "actor.h"
extern s8 D_001F2160[];
extern f32 D_001F2170[];
void func_00146310(f32 *, f32 *, s8 *, f32 *, f32 *);
f32 fabsf(f32);
void sceVu0RotMatrixX(f32 (*)[4], f32 *, f32);
void sceVu0RotMatrixY(f32 (*)[4], f32 (*)[4], f32);
void sceVu0CopyMatrix(f32 (*)[4], f32 *);
void sceVu0CopyVector(f32 *, f32 *);
void sceVu0MulMatrix(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
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
        x = fabsf(x) < mx ? x : mx * sgn(x);
        y = b;
        y = fabsf(y) < my ? y : my * sgn(y);
        sceVu0RotMatrixX(r, D_001F2170, WRAP(y));
        sceVu0RotMatrixY(r, r, WRAP(x));
        sceVu0CopyMatrix(t, m);
        sceVu0CopyVector(t[3], (f32 *)D_001F2160);
        sceVu0MulMatrix(t, t, r);
        sceVu0CopyVector(m, t[0]);
        sceVu0CopyVector(m + 4, t[1]);
        sceVu0CopyVector(m + 8, t[2]);
    }
}
