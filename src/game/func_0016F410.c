#include "common.h"

typedef struct { char pad[0x2C]; s32 v; char p2[0xC]; unsigned char : 3; unsigned char f : 1; } Obj;

void func_0016F410(Obj *o, s32 v, int f)
{
    o->v = v;
    o->f = f;
}
