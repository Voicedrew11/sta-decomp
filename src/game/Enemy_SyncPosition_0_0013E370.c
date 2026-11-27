#include "common.h"

typedef struct { char pad[4]; f32 v; } C;
typedef struct { char pad[0x198]; C *c; } B;
typedef struct { char pad[0x518]; B *b; } Q;
typedef struct { char pad[0x5B2]; unsigned int : 5; unsigned int on : 1; unsigned int mode : 2; char p[0x29]; f32 v; } Obj;

void Enemy_SyncPosition_0_0013E370(Obj *o)
{
    if (o->mode < 2) {
        if (o->on)
            o->v = ((Q *)o)->b->c->v;
    } else {
        o->v = ((Q *)o)->b->c->v;
    }
}
