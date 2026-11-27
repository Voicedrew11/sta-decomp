#include "common.h"

typedef struct { char pad[8]; s16 h; } Obj;
u8 *Script_GetArgPtr_2_00165130(Obj *o, s32 b);
u8 *Inventory_GetEntry_1_001CC3F0(s16 h);

void MapCmd_GetEffectState_0_0017D170(Obj *o)
{
    u8 *p = Script_GetArgPtr_2_00165130(o, 1);
    u8 *t = Inventory_GetEntry_1_001CC3F0(o->h);
    if (t)
        *p = t[2];
    else
        *p = 0;
}
