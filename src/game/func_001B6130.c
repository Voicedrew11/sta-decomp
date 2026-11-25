#include "common.h"

typedef struct { s32 v; s32 x; } E;
typedef struct { char pad[0x70]; u16 n; char p72[0x1E]; s32 a[7]; char pac[0xD0]; E *e; } Obj;

void func_001B6130(Obj *o)
{
    u32 i;
    o->a[0] = 0;
    o->a[1] = 0;
    o->a[2] = 0;
    o->a[3] = 0;
    o->a[4] = 0;
    o->a[5] = 0;
    o->a[6] = 0;
    for (i = 0; i < o->n; i++)
        o->e[i].v = 0;
}
