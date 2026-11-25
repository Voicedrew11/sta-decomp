#include "common.h"

typedef struct { char pad[0x4A4]; s32 *p; } Obj;
s32 func_00166F80(s32 a, s32 b, Obj *o);
s32 func_00166C10(s32 a, s32 h);

void func_00141DA0(Obj *o)
{
    s32 h = func_00166F80(*o->p, 0x2010, o);
    while ((s8)func_00166C10(*o->p, h)) {
    }
}
