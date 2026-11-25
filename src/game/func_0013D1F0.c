#include "common.h"

typedef struct { char pad[0x198]; f32 *v; } B;
typedef struct { char pad[0x518]; B *q; char p[0x660 - 0x51C]; f32 a[4]; f32 b[4]; } Obj;
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_0013D1F0(Obj *o)
{
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 d[4];
    sceVu0CopyVector(a, o->a);
    sceVu0CopyVector(b, o->b);
    sceVu0CopyVector(c, o->q->v);
    sceVu0CopyVector(d, o->q->v + 8);
}
