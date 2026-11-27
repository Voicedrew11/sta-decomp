#include "common.h"

typedef struct { char pad[8]; f32 x; char p1[4]; f32 y; char p2[4]; f32 z; char p3[4]; f32 w; } S;
void Camera_SetParams_0_001C8F30(f32 a, f32 b, f32 c, f32 d);

void MapCmd_SetCameraTarget_0_0017DB40(S *s)
{
    Camera_SetParams_0_001C8F30(s->x, s->y, s->z, s->w);
}
