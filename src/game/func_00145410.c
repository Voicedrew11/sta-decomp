#include "common.h"
f32 *func_00165130(s32, s32);
Vec *func_0013DCE0(s32);
void sceVu0CopyVector(Vec *, Vec *);
extern s8 *D_00201FA8;

void func_00145410(s32 a0) {
    s32 o;
    f32 *x, *y, *z;
    Vec *s;
    o = *(s32 *)(D_00201FA8 + 0x154);
    x = func_00165130(a0, 0);
    y = func_00165130(a0, 1);
    z = func_00165130(a0, 2);
    {
        Vec v = {0};
        s = func_0013DCE0(o);
        if (s) sceVu0CopyVector(&v, s);
        *x = v.x;
        *y = v.y;
        *z = v.z;
    }
}
