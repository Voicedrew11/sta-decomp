#include "common.h"

f32 *func_00165130(u8 *o, s32 b);
void *func_00179E50(u8 a, u8 b);
void func_00140470(void *p, f32 *v);

void func_0017C620(u8 *o)
{
    f32 *x = func_00165130(o, 2);
    f32 *y = func_00165130(o, 3);
    f32 *z = func_00165130(o, 4);
    void *p;
    f32 v[4];
    if (!(p = func_00179E50(o[8], o[0x10]))) {
        *x = 0.0f;
        *y = 0.0f;
        *z = 0.0f;
        return;
    }
    func_00140470(p, v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}
