#include "common.h"

typedef struct { char pad[0x18]; u32 a : 8; u32 b : 24; s32 x1c; void *p20; void *p24; } Obj;

void func_001536F0(s32 x, Obj *o)
{
    o->a = 2;
    o->b = 0;
    o->p20 = o;
    o->p24 = o;
    o->x1c = x;
}
