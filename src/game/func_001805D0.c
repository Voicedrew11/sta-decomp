#include "m2c.h"
typedef struct { u8 pad[0x6C]; s8 *p; } O;
void func_00182080(f32, s32, f32 *, s8 *, s32 *, s32);
void func_00187B20(s32);
O *func_00189020(s32);
extern f32 D_00202050;

void func_001805D0(f32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 col;
    f32 c[4];
    f32 b[4];
    f32 a[4];
    f32 inv, h, step, d;
    O *s0;
    s32 n;

    s0 = func_00189020(0);
    col = 0x80404040;
    inv = 1.0f / (f32)(arg2 - (arg1 - 1));
    d = arg0[3] - arg0[1];
    h = inv * d;
    if (arg1 == arg2) {
        D_00202050 = 0.0f;
    } else {
        step = h;
        if (h < 10.0f) {
            step = inv * (d - 10.0f);
            h = 10.0f;
        }
        if (arg2 < arg3 + arg1) {
            D_00202050 = step * (f32)(arg2 - arg1);
        } else {
            if (arg3 < 0) arg3 = 0;
            D_00202050 = (f32)arg3 * step;
        }
    }
    b[0] = arg0[0];
    b[1] = (f32)(s32)D_00202050 + arg0[1];
    b[2] = arg0[2];
    b[3] = 4.0f + ((f32)(s32)D_00202050 + arg0[1]);
    c[0] = arg0[0];
    c[1] = 4.0f + ((f32)(s32)D_00202050 + arg0[1]);
    c[2] = arg0[2];
    c[3] = (f32)(s32)h + ((f32)(s32)D_00202050 + arg0[1]);
    a[0] = arg0[0];
    a[1] = (f32)(s32)h + ((f32)(s32)D_00202050 + arg0[1]);
    a[2] = arg0[2];
    a[3] = (f32)(s32)h + (4.0f + ((f32)(s32)D_00202050 + arg0[1]));
    func_00187B20(0);
    n = M2C_FIELD(s0->p, s32 *, 4);
    func_00182080(0.0f, n, b, s0->p + 0x20, &col, 0);
    func_00182080(0.0f, n, c, s0->p + 0x50, &col, 0);
    func_00182080(0.0f, n, a, s0->p + 0x80, &col, 0);
}
