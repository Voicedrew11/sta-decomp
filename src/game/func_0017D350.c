#include "common.h"

f32 *func_00165130(void *o, s32 b);
void func_001C9490(f32 *v);

void func_0017D350(void *o)
{
    f32 *x = func_00165130(o, 0);
    f32 *y = func_00165130(o, 1);
    f32 *z = func_00165130(o, 2);
    f32 v[4];
    func_001C9490(v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}
