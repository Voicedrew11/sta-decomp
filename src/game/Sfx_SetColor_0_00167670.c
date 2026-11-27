#include "common.h"

typedef struct { u128 a, b; } Q;
typedef struct { char pad[0x150]; Q q; char p170[0x19]; unsigned char : 7; unsigned char f : 1; } Obj;

void Sfx_SetColor_0_00167670(Obj *o, Q *q)
{
    if (o) {
        if (q) {
            o->q = *q;
            o->f = 1;
            return;
        }
        {
            int v = 0;
            o->f = v;
        }
    }
}
