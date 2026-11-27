#include "common.h"

typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; f32 x; char p2[4]; f32 y; char p3[4]; f32 z; } Obj;
typedef struct { f32 x, y, z, w; } V;
void Snd_PlaySeAt_2_001315A0(s32 a, s32 b, V *v);

void MapCmd_PlaySeAtXYZ_1_0017BC00(Obj *o)
{
    V v;
    v.x = o->x;
    v.y = o->y;
    v.z = o->z;
    v.w = 1.0f;
    Snd_PlaySeAt_2_001315A0(o->a, o->b, &v);
}
