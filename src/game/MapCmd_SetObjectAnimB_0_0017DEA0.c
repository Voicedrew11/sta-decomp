#include "common.h"
typedef struct { char pad[8]; s32 a; char pad2[4]; s32 b; } S;
void MapObj_PlayAnim_1_001B7CD0(s64 arg0, s64 arg1);
void MapCmd_SetObjectAnimB_0_0017DEA0(S *s) { MapObj_PlayAnim_1_001B7CD0(s->a, s->b); }
