#include "common.h"

typedef struct { char p0[0xA]; u16 h; char pc[0x1D]; u8 b29; u8 b2a; char rest[0x65]; } E;
typedef struct { u8 b0, b1, b2, b3; } F;
typedef struct { char pad[0xA0]; F f[0x400]; } T;
E *Item_GetTable_1_001AFC90(s16 i);
T *PlayerData_Get_2_001C9BA0(void);

s32 Inventory_HasItem_0_001CBC20(s16 i)
{
    E *e = Item_GetTable_1_001AFC90(i);
    T *t = PlayerData_Get_2_001C9BA0();
    if (i < 0 || i >= 0x400)
        return 0;
    if (e[i].h == 0 && e[i].b29 == 5)
        return t->f[i].b3 + t->f[i].b2 * e[i].b2a;
    return 0;
}
