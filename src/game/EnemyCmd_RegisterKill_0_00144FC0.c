#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u8 Ent_GetTypeByte_1_0013E220(void *p);
void Bestiary_IsSeen_2_001A9EC0(s16 i);
void Bestiary_SetSeen_1_001A9F10(s16 i);
void Bestiary_SetKilled_1_001A9FA0(s16 i);

void EnemyCmd_RegisterKill_0_00144FC0(void)
{
    s16 i = Ent_GetTypeByte_1_0013E220(D_00201FA8->p);
    Bestiary_SetKilled_1_001A9FA0(i);
    Bestiary_IsSeen_2_001A9EC0(i);
    Bestiary_SetSeen_1_001A9F10(i);
}
