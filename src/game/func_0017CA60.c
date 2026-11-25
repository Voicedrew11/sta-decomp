#include "common.h"

typedef struct { char pad[8]; f32 v; } Obj;
f32 *func_00165130(Obj *o, s32 b);
f32 sqrtf(f32 x);

void func_0017CA60(Obj *o)
{
    f32 v = o->v;
    f32 *p = func_00165130(o, 1);
    *p = sqrtf(v);
}
