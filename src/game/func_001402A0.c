#include "common.h"

typedef struct { char pad[0x198]; f32 *v; } B;
typedef struct { char pad[0x518]; B *b; } Obj;
void func_00145760(f32 *v);
void sceVu0SubVector(f32 *v0, f32 *v1, f32 *v2);
f32 sceVu0InnerProduct(f32 *v0, f32 *v1);
f32 sqrtf(f32 x);

f32 func_001402A0(Obj *o)
{
    f32 v[4];
    func_00145760(v);
    sceVu0SubVector(v, v, o->b->v);
    return sqrtf(sceVu0InnerProduct(v, v));
}
