#include "common.h"

typedef struct { char pad[0x20]; u16 h; char rest[0x6E]; } E;
E *Item_GetTable_1_001AFC90(s16 i);

u16 Item_GetType_0_001CCDE0(s16 i)
{
    E *e = Item_GetTable_1_001AFC90(i);
    if (i == -1)
        return 0;
    return e[i].h;
}
