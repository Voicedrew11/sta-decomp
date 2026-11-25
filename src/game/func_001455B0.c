#include "common.h"

typedef struct { u8 b[12]; f32 v; } T;
typedef struct { char pad[8]; f32 f; } Obj;
void func_00189F00(T *t);

void func_001455B0(Obj *o)
{
    T t = { 0 };
    t.v = 256.0f * o->f;
    func_00189F00(&t);
}
