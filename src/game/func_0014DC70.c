#include "common.h"

typedef struct { s32 x0; s32 x4; s32 x8; char pc[0x10]; s32 x1c; char x20[0x14]; s32 x34; } Obj;
extern s32 D_00201E94;
s32 func_00159D10(s32 a);
s32 func_0015ABD0(s32 a);
s32 func_0015A350(s32 a);
void func_0015A2F0(s32 a, void *b);

s32 func_0014DC70(Obj *o, s32 a)
{
    s32 h = func_0015ABD0(func_00159D10(a));
    o->x1c = h;
    o->x4 = func_0015A350(h);
    o->x8 = o->x4;
    o->x34 = D_00201E94;
    func_0015A2F0(o->x1c, o->x20);
    return 1;
}
