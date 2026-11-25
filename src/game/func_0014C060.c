#include "common.h"

typedef struct { char pad[0x50]; f32 x, y, z; char p5c[0x64]; f32 m[3][4]; f32 v[4]; } Obj;
extern void *D_002022E4;
extern f32 D_001F2160[4];
void func_00146600(void *a, f32 (*m)[4]);
void sceVu0ApplyMatrix(f32 *out, f32 (*m)[4], f32 *v);
void sceVu0CopyMatrix(f32 (*m0)[4], f32 (*m1)[4]);
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_0014C060(Obj *o)
{
    f32 m[4][4];
    f32 v[4];
    v[0] = o->x;
    v[1] = o->y;
    v[2] = o->z;
    v[3] = 1.0f;
    func_00146600(D_002022E4, m);
    sceVu0ApplyMatrix((f32 *)o, m, v);
    sceVu0CopyMatrix(o->m, m);
    sceVu0CopyVector(o->v, D_001F2160);
}
