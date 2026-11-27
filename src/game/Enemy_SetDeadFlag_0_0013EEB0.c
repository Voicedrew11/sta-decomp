#include "common.h"

typedef struct { char pad[0x120]; unsigned char : 1; unsigned char f : 1; } C;
typedef struct { char pad[0x190]; C *c; } B;
typedef struct { char pad[0x518]; B *b; } Obj;

void Enemy_SetDeadFlag_0_0013EEB0(Obj *o, int v)
{
    o->b->c->f = v;
}
