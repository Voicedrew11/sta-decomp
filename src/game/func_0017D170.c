#include "common.h"

typedef struct { char pad[8]; s16 h; } Obj;
u8 *func_00165130(Obj *o, s32 b);
u8 *func_001CC3F0(s16 h);

void func_0017D170(Obj *o)
{
    u8 *p = func_00165130(o, 1);
    u8 *t = func_001CC3F0(o->h);
    if (t)
        *p = t[2];
    else
        *p = 0;
}
