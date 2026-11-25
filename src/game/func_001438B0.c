#include "common.h"

typedef struct { char pad[8]; u16 h; } Obj;
s8 *func_00165130(Obj *o, s32 b);
s8 func_001A9B40(s16 v);

void func_001438B0(Obj *o)
{
    u16 v = o->h;
    s8 *q = func_00165130(o, 1);
    *q = func_001A9B40(v);
}
