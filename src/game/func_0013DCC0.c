#include "common.h"

typedef struct { char pad[0x2A]; u8 idx; } Ent;
typedef struct { char pad[0x39A]; u8 b[0x11A]; Ent *ents[1]; } Obj;

u8 func_0013DCC0(Obj *o, u8 i)
{
    return o->b[o->ents[i]->idx];
}
