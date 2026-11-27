#include "common.h"

typedef struct { u8 b[12]; f32 v; } T;
typedef struct { char pad[8]; f32 f; } Obj;
void Camera_SetShake_0_00189F00(T *t);

void EnemyCmd_ShakeCamera_0_001455B0(Obj *o)
{
    T t = { 0 };
    t.v = 256.0f * o->f;
    Camera_SetShake_0_00189F00(&t);
}
