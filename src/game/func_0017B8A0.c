#include "common.h"

typedef struct { char pad[0x52]; unsigned char : 7; unsigned char f : 1; char rest[0x2D]; } E;
typedef struct { char pad[0x180]; E *e; } T;
typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; s32 f; } Obj;
s32 func_001B7840(s32 a, s32 b);
T *func_001B19A0(s32 a);

void func_0017B8A0(Obj *o)
{
    s32 a = o->a;
    s32 f = o->f;
    s32 k = func_001B7840(a, o->b);
    T *t;
    E *e;
    if (k < 0)
        return;
    t = func_001B19A0(a);
    if (!t)
        return;
    e = &t->e[k];
    if (e)
        e->f = f;
}
