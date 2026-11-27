#include "common.h"

typedef struct { char pad[0x1A4]; s32 v; } B;
typedef struct { char pad[0x518]; B *b; } Obj;
Obj *ActorList_Next_2_001A5460(s32 *it);
void Mdl_ResetBones_0_00171610(s32 v);

void Actor_UpdateAllVisibility_0_0013BB70(void)
{
    s32 it = 0;
    Obj *o;
    for (o = ActorList_Next_2_001A5460(&it); o; o = ActorList_Next_2_001A5460(&it))
        Mdl_ResetBones_0_00171610(o->b->v);
}
