#include "common.h"

typedef struct { char pad[0x10]; s32 v; } Obj;
s32 *Script_GetArgPtr_2_00165130(Obj *o, s32 b);
s32 MapObj_GetCountB_0_001B18D0(s32 *v);

void MapCmd_GetObjectVarB_0_0017DCD0(Obj *o)
{
    s32 *p = Script_GetArgPtr_2_00165130(o, 0);
    s32 v = o->v;
    *p = MapObj_GetCountB_0_001B18D0(&v);
}
