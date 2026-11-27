#include "common.h"

typedef struct { char pad[8]; f32 x; char p0[4]; f32 y; char p1[4]; f32 z; } Obj;
typedef struct { f32 x, y, z, w; } V;
void Player_GetPosB_0_001C9490(V *v);
void Player_SetPosAndGround_0_001C94F0(V *v);

void MapCmd_SetPlayerPosVec_0_0017CFB0(Obj *o)
{
    V v;
    Player_GetPosB_0_001C9490(&v);
    v.x = o->x;
    v.y = o->y;
    v.z = o->z;
    v.w = 1.0f;
    Player_SetPosAndGround_0_001C94F0(&v);
}
