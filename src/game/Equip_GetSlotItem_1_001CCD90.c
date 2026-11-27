#include "common.h"

typedef struct { char pad[0x80]; s16 v[10]; } T;
T *PlayerData_Get_2_001C9BA0(void);

s16 Equip_GetSlotItem_1_001CCD90(s32 i)
{
    T *t = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10)
        return t->v[i];
    return -1;
}
