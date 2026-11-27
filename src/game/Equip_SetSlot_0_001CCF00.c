#include "common.h"

typedef struct { char pad[0x80]; char sub[1]; } T;
T *PlayerData_Get_2_001C9BA0(void);
void Equip_Assign_1_001CCF50(void *p, s32 a, s32 b);
void Player_RecalcStats_1_001CEDC0(s32 v);

void Equip_SetSlot_0_001CCF00(s32 a, s32 b)
{
    T *t = PlayerData_Get_2_001C9BA0();
    Equip_Assign_1_001CCF50(t->sub, a, b);
    Player_RecalcStats_1_001CEDC0(3);
}
