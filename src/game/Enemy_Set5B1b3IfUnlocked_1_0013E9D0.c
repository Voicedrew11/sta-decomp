#include "common.h"

typedef struct { char pad[0x5B1]; unsigned char : 3; unsigned char f : 1; unsigned char : 1; unsigned char lock : 1; } Obj;

void Enemy_Set5B1b3IfUnlocked_1_0013E9D0(Obj *o, int v)
{
    if (!o->lock)
        o->f = v;
}
