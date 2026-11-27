#include "common.h"

typedef struct { char pad[0x5B0]; unsigned char : 3; unsigned char a : 3; char p[2]; unsigned char : 4; unsigned char b : 2; } Obj;

void Enemy_SetMode_0_0013EBA0(Obj *o, u8 v)
{
    o->a = v;
    if (v < 4)
        o->b = v;
}
