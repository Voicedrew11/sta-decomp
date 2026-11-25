#include "common.h"

typedef struct { char pad[0x24]; f32 yaw; } C;
typedef struct { char pad[0x198]; C *c; } B;
typedef struct { char pad[0x518]; B *b; } Obj;
f32 func_0011D778(f32 x);
f32 func_0011DA18(f32 x);

void func_00140360(Obj *o, f32 *v)
{
    f32 a = o->b->c->yaw;
    a += 1.5707964f;
    v[0] = -func_0011DA18(a);
    v[1] = 0.0f;
    v[2] = -func_0011D778(a);
}
