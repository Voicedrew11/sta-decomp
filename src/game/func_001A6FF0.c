#include "common.h"

typedef struct { char pad[0x2D]; s8 v; char rest[0x26]; } E;
typedef struct { char pad[0x13C]; E *tbl; } T;
typedef struct { T *t; } B;
typedef struct { char pad[0x4A8]; B *b; u16 i; s16 v; } Obj;

void func_001A6FF0(Obj *o, B *b, u16 i)
{
    E *e = &b->t->tbl[i];
    o->b = b;
    o->i = i;
    o->v = e->v;
}
