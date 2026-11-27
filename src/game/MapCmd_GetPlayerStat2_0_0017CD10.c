#include "common.h"

typedef struct { char pad[8]; s32 v; } Obj;
s32 *Script_GetArgPtr_2_00165130(Obj *o, s32 b);
s32 PlayerData_GetStatusTimer_0_001CE200(s32 v);

void MapCmd_GetPlayerStat2_0_0017CD10(Obj *o)
{
    s32 v = o->v;
    s32 *p = Script_GetArgPtr_2_00165130(o, 1);
    *p = PlayerData_GetStatusTimer_0_001CE200(v);
}
