#include "m2c.h"
f32 *func_00165130(s8 *, s32);
f32 *func_00157620(void);

void func_0017CBA0(s8 *arg0) {
    s32 mode;
    f32 x, y, z;
    f32 *a;
    f32 *b;
    f32 *c;
    f32 *p;
    mode = *(s32 *)(arg0 + 8);
    x = *(f32 *)(arg0 + 0x10);
    y = *(f32 *)(arg0 + 0x18);
    z = *(f32 *)(arg0 + 0x20);
    a = func_00165130(arg0, 4);
    b = func_00165130(arg0, 5);
    c = func_00165130(arg0, 6);
    p = func_00157620();
    if (p != NULL) {
        if (mode == 0) {
            p[0] = x;
            p[1] = y;
            p[2] = z;
        } else if (a != NULL && b != NULL && c != NULL) {
            *a = p[0];
            *b = p[1];
            *c = p[2];
        }
    }
}
