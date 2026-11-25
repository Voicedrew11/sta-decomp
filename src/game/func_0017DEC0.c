#include "common.h"

typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; s32 c; } Obj;
f32 *func_00165130(Obj *o, s32 b);
f32 func_001B7610(s32 a, s32 b, s32 c);

void func_0017DEC0(Obj *o)
{
    s32 a = o->a;
    s32 b = o->b;
    s32 c = o->c;
    f32 *p = func_00165130(o, 3);
    *p = func_001B7610(a, b, c);
}
