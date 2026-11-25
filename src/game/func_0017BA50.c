#include "common.h"

typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[0xC]; f32 x; char p2[4]; f32 y; char p3[4]; f32 z; } Obj;
typedef struct { f32 x, y, z, w; } V;
s32 *func_00165130(Obj *o, s32 b);
s32 func_001315A0(s32 a, s32 b, V *v);

void func_0017BA50(Obj *o)
{
    s32 *p = func_00165130(o, 2);
    V v;
    v.x = o->x;
    v.y = o->y;
    v.z = o->z;
    v.w = 1.0f;
    *p = func_001315A0(o->a, o->b, &v);
}
