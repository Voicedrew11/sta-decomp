#include "common.h"

typedef struct { char pad[8]; f32 x; char p0[4]; f32 y; char p1[4]; f32 z; } Obj;
typedef struct { f32 x, y, z, w; } V;
void func_001C9490(V *v);
void func_001C94F0(V *v);

void func_0017CFB0(Obj *o)
{
    V v;
    func_001C9490(&v);
    v.x = o->x;
    v.y = o->y;
    v.z = o->z;
    v.w = 1.0f;
    func_001C94F0(&v);
}
