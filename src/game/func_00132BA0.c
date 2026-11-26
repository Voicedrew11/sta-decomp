#include "m2c.h"
u16 func_0013E410(s8 *);
f32 func_0013FCB0(s8 *);
void func_0013C420(s8 *, u8, s16, s32);
void func_0013E920(s8 *, u8);
void func_0013E6D0(s8 *, s32);
static inline u8 cls(f32 f) {
    if (!(f <= 0.5f)) return 2;
    if (!(f <= 0.1f)) return 1;
    return 0;
}

void func_00132BA0(s8 *a0, s32 a1, u8 *a2, u8 *a3, u8 *t0, u8 *t1) {
    u8 c;
    s32 b;
    u16 m;
    b = 0;
    c = 0;
    m = func_0013E410(a0);
    switch (cls(func_0013FCB0(a0))) {
    case 0:
        *a2 = 0;
        *a3 = 0;
        c = 0;
        *t0 = 0;
        b = 0;
        *t1 = 0;
        break;
    case 1:
        if (m & 1) {
            c = 0;
            *a2 = 3;
            b = 0;
            *a3 = 0;
            *t0 = 0;
            *t1 = 2;
        }
        break;
    case 2:
        if (m & 2) {
            *a2 = 3;
            *a3 = 1;
            c = 0;
            b = 0;
            *t0 = 0;
            *t1 = 3;
        } else if (m & 4) {
            *a2 = 3;
            *a3 = 1;
            c = 1;
            b = 0;
            *t0 = 0;
            *t1 = 3;
        } else if (m & 1) {
            c = 0;
            *a2 = 3;
            b = 0;
            *a3 = 0;
            *t0 = 0;
            *t1 = 2;
        }
        break;
    }
    func_0013C420(a0, *a2, *a3, 1);
    func_0013E920(a0, c);
    func_0013E6D0(a0, b);
}
