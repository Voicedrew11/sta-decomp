#include "common.h"

typedef struct { s32 *p; } P;
typedef struct { char pad[0x4A8]; P *p; char p1[0xF5]; unsigned char : 3; unsigned char f : 1; char p2[0x170]; u16 h; } Obj;

s32 Enemy_GetTargetHandle_0_0013EDE0(Obj *o)
{
    s32 r;
    if (o->f)
        r = o->h;
    else if (o->p)
        r = *o->p->p;
    else
        r = 0;
    return r;
}
