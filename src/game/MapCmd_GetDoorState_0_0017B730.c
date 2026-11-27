#include "common.h"

typedef struct { char pad[8]; s32 a; char p[4]; s32 b; } Obj;
s32 *Script_GetArgPtr_2_00165130(Obj *o, s32 b);
u16 MapObj_GetAnimState_0_001B7D80(s32 a, s32 b);

void MapCmd_GetDoorState_0_0017B730(Obj *o)
{
    s32 a = o->a;
    s32 b = o->b;
    s32 *p = Script_GetArgPtr_2_00165130(o, 2);
    *p = MapObj_GetAnimState_0_001B7D80(a, b);
}
