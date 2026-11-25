#include "common.h"

typedef struct { char pad[8]; s32 a; } Obj;
void *func_00165130(Obj *o, s32 b);
void func_001B1560(s32 a, void *p, void *q, void *r, void *s);

void func_0017C4B0(Obj *o)
{
    s32 a = o->a;
    void *p = func_00165130(o, 1);
    void *q = func_00165130(o, 2);
    void *r = func_00165130(o, 3);
    func_001B1560(a, p, q, r, func_00165130(o, 4));
}
