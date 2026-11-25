#include "common.h"

typedef struct { char pad[0x10]; s32 v; } Obj;
s32 *func_00165130(Obj *o, s32 b);
s32 func_001B18D0(s32 *v);

void func_0017DCD0(Obj *o)
{
    s32 *p = func_00165130(o, 0);
    s32 v = o->v;
    *p = func_001B18D0(&v);
}
