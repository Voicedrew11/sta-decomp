#include "common.h"

typedef struct { char pad[0x1A4]; s32 v; } B;
typedef struct { char pad[0x518]; B *b; } Obj;
Obj *func_001A5460(s32 *it);
void func_00171610(s32 v);

void func_0013BB70(void)
{
    s32 it = 0;
    Obj *o;
    for (o = func_001A5460(&it); o; o = func_001A5460(&it))
        func_00171610(o->b->v);
}
