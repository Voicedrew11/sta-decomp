#include "common.h"

typedef struct { s32 a, b; } P;
typedef struct { P p[8]; } Q;
typedef struct { char pad[0x18A]; unsigned char : 1; unsigned char f : 1; char p[0xCF5]; Q q; } Obj;

s32 func_001672B0(Obj *o, Q *q)
{
    if (!o)
        return 0;
    o->q = *q;
    o->f = 1;
    return 1;
}
