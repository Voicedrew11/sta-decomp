#include "common.h"

typedef struct { f32 a[6]; } M2;
f32 func_0011DA18(f32 x);
f32 func_0011D778(f32 x);

M2 *func_00182860(M2 *o, f32 x)
{
    M2 t;
    f32 s = func_0011DA18(x);
    f32 c = func_0011D778(x);
    t.a[0] = c;
    t.a[1] = -s;
    t.a[2] = s;
    t.a[3] = c;
    *o = t;
    return o;
}
