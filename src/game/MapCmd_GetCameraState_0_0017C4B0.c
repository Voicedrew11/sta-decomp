#include "common.h"

typedef struct { char pad[8]; s32 a; } Obj;
void *Script_GetArgPtr_2_00165130(Obj *o, s32 b);
void MapObj_GetCamera_0_001B1560(s32 a, void *p, void *q, void *r, void *s);

void MapCmd_GetCameraState_0_0017C4B0(Obj *o)
{
    s32 a = o->a;
    void *p = Script_GetArgPtr_2_00165130(o, 1);
    void *q = Script_GetArgPtr_2_00165130(o, 2);
    void *r = Script_GetArgPtr_2_00165130(o, 3);
    MapObj_GetCamera_0_001B1560(a, p, q, r, Script_GetArgPtr_2_00165130(o, 4));
}
