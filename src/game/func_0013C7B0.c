#include "common.h"

typedef struct { char pad[0x5B0]; unsigned int f : 1; char p[2]; unsigned int : 4; unsigned int m : 2; } Obj;
s32 func_00142470(Obj *o, s16 k);
void func_0013C360(Obj *o, s16 k, s32 a, s32 b, s32 c);
void func_0013E920(Obj *o, s32 v);

u8 func_0013C7B0(Obj *o)
{
    u8 r;
    s16 k = (o->m & 3) + (o->f * 32 + 12);
    r = func_00142470(o, k);
    if (!r)
        func_0013C360(o, k, 0, 0, 2);
    func_0013E920(o, 1);
    return r;
}
