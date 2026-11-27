#include "common.h"

typedef struct { char pad[0x2A]; u8 idx; } Ent;
typedef struct { char pad[0x39A]; u8 b[0x11A]; Ent *ents[1]; } Obj;
void Enemy_InitPartState_1_001A8510(Obj *o, u8 i);
void Enemy_ResetPartAnim_1_001A8670(Obj *o, u8 i);
void Enemy_UpdatePartStat_0_0013F0C0(Obj *o, u8 v);

void Enemy_InitPart_1_0013F1B0(Obj *o, u8 i)
{
    Enemy_InitPartState_1_001A8510(o, i);
    Enemy_ResetPartAnim_1_001A8670(o, i);
    Enemy_UpdatePartStat_0_0013F0C0(o, o->b[o->ents[i]->idx]);
}
