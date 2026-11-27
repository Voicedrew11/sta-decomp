#include "common.h"

typedef struct { char pad[8]; u32 a; char p0[4]; f32 x; char p1[4]; f32 y; char p2[4]; f32 z; char p3[4]; f32 w; } S;
void MapObj_SetCamera_0_001B13B0(u32 a, f32 x, f32 y, f32 z, f32 w);

void MapCmd_SetCameraPath_0_0017C490(S *s)
{
    MapObj_SetCamera_0_001B13B0(s->a, s->x, s->y, s->z, s->w);
}
