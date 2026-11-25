#include "common.h"

typedef struct { char pad[8]; s32 a; char p[4]; s32 b; } Obj;
s32 *func_00165130(Obj *o, s32 b);
u16 func_001B7D80(s32 a, s32 b);

void func_0017B730(Obj *o)
{
    s32 a = o->a;
    s32 b = o->b;
    s32 *p = func_00165130(o, 2);
    *p = func_001B7D80(a, b);
}
