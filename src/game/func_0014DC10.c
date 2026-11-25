#include "common.h"

typedef struct { char pad[0x1C]; void *p; } Obj;
void func_0015AB80(void *p);

s32 func_0014DC10(Obj *o)
{
    if (o->p)
        func_0015AB80(o->p);
    o->p = NULL;
    return 1;
}
