#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u8 Ent_GetTypeByte_1_0013E220(void *p);
void Bestiary_IsKilled_1_001A9F60(s16 i);
void Bestiary_SetKilled_1_001A9FA0(s16 i);

void EnemyCmd_RegisterSeen_0_00145010(void)
{
    s16 i = Ent_GetTypeByte_1_0013E220(D_00201FA8->p);
    Bestiary_IsKilled_1_001A9F60(i);
    Bestiary_SetKilled_1_001A9FA0(i);
}
