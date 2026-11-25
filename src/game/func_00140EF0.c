#include "common.h"

typedef struct { char pad[0x4A4]; s32 *p; } Obj;
s32 func_00166F80(s32 a, s32 b, Obj *o);
void func_00165070(s32 a, u8 h, s32 c, s32 d);
s32 func_00166C10(s32 a, s32 h);
s32 func_00164FC0(s32 a, u8 h, u8 c);

u8 func_00140EF0(Obj *o)
{
    s32 h = func_00166F80(*o->p, 0x2020, o);
    func_00165070(*o->p, h, 0, 0);
    while ((s8)func_00166C10(*o->p, h)) {
    }
    return (u8)func_00164FC0(*o->p, h, 0);
}
