#include "common.h"

typedef struct { char pad[8]; s16 h; } Obj;
s32 *Script_GetArgPtr_2_00165130(Obj *o, s32 b);
s16 Equip_GetSlotItem_1_001CCD90(s16 v);

void MapCmd_GetEquip_0_0017D130(Obj *o)
{
    s32 *p = Script_GetArgPtr_2_00165130(o, 1);
    *p = Equip_GetSlotItem_1_001CCD90(o->h);
}
