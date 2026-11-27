#include "common.h"

typedef struct { char p[4]; u16 h; char rest[0x8A]; } E;
E *Item_GetTable_1_001AFC90(void);

u16 Item_GetMotionId_0_001CC390(s16 i)
{
    E *e = Item_GetTable_1_001AFC90();
    if (i >= 0 && i <= 0x3FF)
        return e[i].h;
    return 0;
}
