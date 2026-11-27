#include "common.h"

typedef struct { char pad[0x94]; unsigned char : 3; unsigned char f : 1; } T;
typedef struct { char pad[0x210]; T *t; } Obj;

void Sfx_SetOwnerFlag_0_0016B200(Obj *o, int v)
{
    o->t->f = v;
}
