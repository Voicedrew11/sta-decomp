#include "common.h"

typedef struct { f32 v; char pad[8 - sizeof(f32)]; } E;
typedef struct { char pad[0x370]; E e[1][75]; } Obj;

f32 func_00164F60(Obj *o, u8 i, u8 j)
{
    E *row = o->e[i];
    return row[j].v;
}
