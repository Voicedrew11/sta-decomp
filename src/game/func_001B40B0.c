#include "common.h"

typedef struct { char pad[0xBA]; u16 h; } T;
typedef struct { char pad[0x158]; T *t; } Obj;
void func_001541E0(f32 v);

void func_001B40B0(Obj *o)
{
    u32 v = o->t->h;
    func_001541E0(v);
}
