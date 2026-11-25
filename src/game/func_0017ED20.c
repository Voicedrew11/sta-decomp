#include "common.h"

typedef struct { char pad[8]; s32 v; } Obj;
u8 *func_00165130(Obj *o, s32 b);
void *func_00179DB0(s32 a, s32 b);
s32 func_0018AC90(void *p, s32 b);

void func_0017ED20(Obj *o)
{
    u8 *p = func_00165130(o, 1);
    s32 v = o->v;
    void *x = func_00179DB0(v / 1000, v % 1000);
    s32 r = 5;
    if (x)
        r = func_0018AC90(x, 0);
    *p = r;
}
