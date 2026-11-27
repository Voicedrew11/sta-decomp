#include "common.h"

typedef struct { char pad[0x188]; unsigned char : 2; unsigned char f : 1; } Obj;

void Sfx_SetFlag_0_00167640(Obj *o, int v)
{
    if (o)
        o->f = v;
}
