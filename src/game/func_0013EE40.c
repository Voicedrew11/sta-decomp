#include "common.h"

typedef struct { char pad[0x120]; unsigned int f : 1; } C;
typedef struct { char pad[0x190]; C *c; } B;
typedef struct { char pad[0x518]; B *b; } Q;
typedef struct {
    char pad[0x5A1]; unsigned int : 5; unsigned int a : 1;
    char p2[0x14]; unsigned int : 3; unsigned int s : 1;
} Obj;

u8 func_0013EE40(Obj *o)
{
    u8 r = 0;
    r |= ((Q *)o)->b->c->f;
    r |= o->a;
    r |= o->s;
    return r;
}
