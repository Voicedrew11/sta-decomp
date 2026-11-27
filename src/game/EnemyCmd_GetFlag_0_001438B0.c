#include "common.h"

typedef struct { char pad[8]; u16 h; } Obj;
s8 *Script_GetArgPtr_2_00165130(Obj *o, s32 b);
s8 Save_TestItemBit_1_001A9B40(s16 v);

void EnemyCmd_GetFlag_0_001438B0(Obj *o)
{
    u16 v = o->h;
    s8 *q = Script_GetArgPtr_2_00165130(o, 1);
    *q = Save_TestItemBit_1_001A9B40(v);
}
