#include "common.h"

typedef struct { char pad[0x5B1]; unsigned char : 4; unsigned char f : 1; unsigned char lock : 1; } Obj;

void func_0013E980(Obj *o, int v)
{
    if (!o->lock)
        o->f = v;
}
