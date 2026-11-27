#include "common.h"

typedef struct { char pad[8]; s32 v; } Obj;
u8 *Script_GetArgPtr_2_00165130(Obj *o, s32 b);
void *MapObj_FindById_0_00179DB0(s32 a, s32 b);
s32 Msg_ShowWrap_1_0018AC90(void *p, s32 b);

void MapCmd_GetObjectName_0_0017ED20(Obj *o)
{
    u8 *p = Script_GetArgPtr_2_00165130(o, 1);
    s32 v = o->v;
    void *x = MapObj_FindById_0_00179DB0(v / 1000, v % 1000);
    s32 r = 5;
    if (x)
        r = Msg_ShowWrap_1_0018AC90(x, 0);
    *p = r;
}
