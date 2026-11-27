#include "common.h"

typedef struct { char pad[0x24]; s16 h; } Ent;
typedef struct { char pad[0x4B4]; Ent *ents[1]; } Obj;

s32 Enemy_GetPartAngle_1_0013E0C0(Obj *o, u8 i)
{
    s16 v;
    if (i == 0xFF)
        return 0x40;
    v = o->ents[i]->h;
    if (v == -1)
        return 0x40;
    return v;
}
