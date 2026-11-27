#include "common.h"

void sceVu0SubVector(f32 *v0, f32 *v1, f32 *v2);
void Enemy_PickRandomWaypoint_1_001431A0(void *a, f32 *v);

void Enemy_PickWaypointToward_1_00143150(void *a, f32 *b, f32 *c)
{
    f32 v[4];
    sceVu0SubVector(v, c, b);
    Enemy_PickRandomWaypoint_1_001431A0(a, c);
}
