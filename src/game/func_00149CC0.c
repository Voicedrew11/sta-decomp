#include "common.h"

typedef struct { char pad[0xA8]; s32 a8; char pac[4]; f32 v[4]; } Obj;
void sceVu0CopyVector(void *v0, void *v1);

void func_00149CC0(Obj *o)
{
    u16 t[8];
    sceVu0CopyVector(t, o->v);
    t[7] = 0xFFFF;
    t[6] = 0xFFFF;
    t[5] = 0xFFFF;
    t[4] = 0xFFFF;
    t[3] = 0xFFFF;
    t[2] = 0xFFFF;
    t[1] = 0xFFFF;
    t[0] = 0xFFFF;
    sceVu0CopyVector(o->v, t);
    o->a8 = 0;
}
