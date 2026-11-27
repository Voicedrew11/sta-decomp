#include "common.h"

typedef struct { char pad[0x5B3]; unsigned char : 2; unsigned char f : 1; char p[0xC]; f32 t; } Obj;

void Enemy_SetStateResetTimer_1_0013E7E0(Obj *o, u8 v)
{
    if (o->f != v) {
        o->f = v;
        o->t = 1.0f;
    }
}
