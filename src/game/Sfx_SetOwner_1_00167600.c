#include "common.h"
typedef struct { char pad[0x170]; s32 v; } Obj;
s32 ActorList_FromHandle_1_001A5970(void *p);
void Sfx_SetOwner_1_00167600(void *a, void *p) { Obj *o = a; if (a && p) o->v = ActorList_FromHandle_1_001A5970(p); }
