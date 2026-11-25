#include "common.h"

typedef struct { char pad[0x2D]; unsigned char : 1; unsigned int f : 1; } Ent;
typedef struct { char pad[0x4B4]; Ent *ents[1]; } Obj;

u32 func_0013EC60(Obj *o, u8 i)
{
    return o->ents[i]->f;
}
