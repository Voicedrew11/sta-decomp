#include "common.h"

typedef struct { char pad[0x2AD]; unsigned int : 2; unsigned int f : 1; } Q;
typedef struct { u16 h; char pad[0x4AE]; Q *q; } Obj;

s32 func_001D2A40(Obj *o)
{
    return o->h != 0 && !o->q->f;
}
