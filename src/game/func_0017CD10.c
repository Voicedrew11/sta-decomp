#include "common.h"

typedef struct { char pad[8]; s32 v; } Obj;
s32 *func_00165130(Obj *o, s32 b);
s32 func_001CE200(s32 v);

void func_0017CD10(Obj *o)
{
    s32 v = o->v;
    s32 *p = func_00165130(o, 1);
    *p = func_001CE200(v);
}
