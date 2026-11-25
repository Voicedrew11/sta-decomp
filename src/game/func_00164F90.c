#include "common.h"

typedef struct { s8 v; char pad[8 - sizeof(s8)]; } E;
typedef struct { char pad[0x370]; E e[1][75]; } Obj;

s8 func_00164F90(Obj *o, u8 i, u8 j)
{
    E *row = o->e[i];
    return row[j].v;
}
