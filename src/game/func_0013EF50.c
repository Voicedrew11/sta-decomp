#include "common.h"

typedef struct { char pad[0x6B8]; u8 c; } Obj;

void func_0013EF50(Obj *o)
{
    o->c++;
    if (o->c > 0x80)
        o->c = 0x80;
}
