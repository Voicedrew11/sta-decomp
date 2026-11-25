#include "common.h"

typedef struct { s32 v; char pad[0x1C]; } E;
extern struct { char pad[0x380]; E e[5]; } D_004BA500;
void FlushCache(s32 mode);

s32 func_001DA7D0(s32 i)
{
    E *e;
    if (i < 0 || i > 4)
        return -1;
    e = &D_004BA500.e[i];
    if (e->v == -1)
        return -1;
    e->v = -1;
    FlushCache(0);
    return 0;
}
