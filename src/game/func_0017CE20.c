#include "common.h"
typedef struct { char pad[8]; f32 x; char p0[4]; f32 y; char p1[4]; f32 z; } Obj;
typedef struct { f32 x, y, z, w; } V;
void func_001C92C0(V *v);
void func_0017CE20(Obj *o) { V v; f32 y = o->y; f32 z = o->z; v.x = o->x; v.y = y; v.z = z; v.w = 1.0f; func_001C92C0(&v); }
