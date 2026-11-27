#include "common.h"

typedef struct { char p[2]; u8 b; char q; } E;
typedef struct { char pad[0xA0]; E e[0x400]; } T;
T *PlayerData_Get_2_001C9BA0(void);

u8 Inventory_GetFlag_0_001CC060(s16 i)
{
    T *t = PlayerData_Get_2_001C9BA0();
    if (i < 0 || i >= 0x400)
        return 0;
    return t->e[i].b;
}
