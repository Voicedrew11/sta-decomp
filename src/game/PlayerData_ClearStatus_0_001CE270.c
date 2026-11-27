#include "common.h"

typedef struct { char pad[0x30]; s32 a[8]; s32 b[7]; } T;
T *PlayerData_Get_2_001C9BA0(void);

void PlayerData_ClearStatus_0_001CE270(s32 i)
{
    T *t = PlayerData_Get_2_001C9BA0();
    if (i < 0 || i >= 7)
        return;
    t->b[i] = 150;
    t->a[i] = 0;
}
