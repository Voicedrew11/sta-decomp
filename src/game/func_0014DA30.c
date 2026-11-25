#include "common.h"

typedef struct { char pad[0xA8]; s32 a8; char pac[4]; f32 v[4]; } Obj;
extern f32 D_003139A0[4];
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_0014DA30(Obj *o)
{
    sceVu0CopyVector(o->v, D_003139A0);
    o->a8 = 0;
}
