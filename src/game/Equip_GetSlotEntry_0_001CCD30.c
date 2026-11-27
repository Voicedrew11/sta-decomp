#include "common.h"

typedef struct { char p[4]; } E;
typedef struct { char pad[0x80]; s16 idx[10]; char p94[0xC]; E e[1]; } T;
T *PlayerData_Get_2_001C9BA0(void);

E *Equip_GetSlotEntry_0_001CCD30(s32 i)
{
    T *t = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10) {
        s16 k = t->idx[i];
        if (k != -1)
            return &t->e[k];
    }
    return NULL;
}
