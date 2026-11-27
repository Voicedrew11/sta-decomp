#include "common.h"

typedef struct { char pad[0x4A4]; s32 *p; } Obj;
s32 Script_SendEvent_2_00166F80(s32 a, s32 b, Obj *o);
s32 Script_RunEvent_2_00166C10(s32 a, s32 h);

void EnemyScr_Event2022_1_00140DE0(Obj *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2022, o);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
}
