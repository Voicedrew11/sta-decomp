#include "common.h"

typedef struct { char pad[0x4A4]; s32 *p; } Obj;
s32 Script_SendEvent_2_00166F80(s32 a, s32 b, Obj *o);
void Script_SetArgU8_1_00165070(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10(s32 a, s32 h);
s32 Script_GetResultU8_1_00164FC0(s32 a, u8 h, u8 c);

u8 EnemyScr_Event2002_1_00142780(Obj *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2002, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0(*o->p, h, 0);
}
