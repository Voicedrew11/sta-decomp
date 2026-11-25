#include "common.h"

typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; s32 c; char p2[4]; s32 d; char p3[4]; f32 x; char p4[4]; f32 y; } Obj;
s32 func_001B19A0(s32 a);
s32 func_001B7840(s32 a, s32 b);
void func_001B87C0(s32 a, s32 b, s32 c, s32 d, f32 x, f32 y);

void func_0017DE40(Obj *o)
{
    s32 a = o->a;
    s32 b = func_001B19A0(a);
    func_001B87C0(b, func_001B7840(a, o->b), o->c, o->d, o->x, o->y);
}
