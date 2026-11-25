#include "common.h"

typedef struct { char pad[0x2D]; unsigned char : 3; unsigned int f : 1; } Ent;
typedef struct { char pad[0x4B4]; Ent *ents[1]; } Obj;

s32 func_0013EC80(Obj *o, u8 i)
{
    return o->ents[i]->f;
}
