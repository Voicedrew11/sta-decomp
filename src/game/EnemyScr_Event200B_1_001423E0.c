#include "common.h"

typedef struct { char pad[0x4A4]; s32 *p; } Obj;
s32 Script_SendEvent_2_00166F80(s32 a, s32 b, Obj *o);
void Script_SetArgU8_1_00165070(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10(s32 a, s32 h);
void Enemy_IncCounter6B9_1_0013EF10(Obj *o);

void EnemyScr_Event200B_1_001423E0(Obj *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x200B, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    Enemy_IncCounter6B9_1_0013EF10(o);
}
