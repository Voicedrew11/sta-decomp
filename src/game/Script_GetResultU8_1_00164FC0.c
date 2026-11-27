#include "common.h"

typedef struct { u8 v; char pad[8 - sizeof(u8)]; } E;
typedef struct { char pad[0x370]; E e[1][75]; } Obj;

u8 Script_GetResultU8_1_00164FC0(Obj *o, u8 i, u8 j)
{
    E *row = o->e[i];
    return row[j].v;
}
