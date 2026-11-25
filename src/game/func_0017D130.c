#include "common.h"

typedef struct { char pad[8]; s16 h; } Obj;
s32 *func_00165130(Obj *o, s32 b);
s16 func_001CCD90(s16 v);

void func_0017D130(Obj *o)
{
    s32 *p = func_00165130(o, 1);
    *p = func_001CCD90(o->h);
}
