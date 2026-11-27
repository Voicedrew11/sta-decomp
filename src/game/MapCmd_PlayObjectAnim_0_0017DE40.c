#include "common.h"

typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; s32 c; char p2[4]; s32 d; char p3[4]; f32 x; char p4[4]; f32 y; } Obj;
s32 MapObj_Find_1_001B19A0(s32 a);
s32 MapObj_GetNodeIndex_0_001B7840(s32 a, s32 b);
void MapObj_SetAnimFrame_0_001B87C0(s32 a, s32 b, s32 c, s32 d, f32 x, f32 y);

void MapCmd_PlayObjectAnim_0_0017DE40(Obj *o)
{
    s32 a = o->a;
    s32 b = MapObj_Find_1_001B19A0(a);
    MapObj_SetAnimFrame_0_001B87C0(b, MapObj_GetNodeIndex_0_001B7840(a, o->b), o->c, o->d, o->x, o->y);
}
