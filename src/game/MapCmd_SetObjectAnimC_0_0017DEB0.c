#include "common.h"

typedef struct { char pad[8]; s32 a; char pad2[4]; s32 b; } S;
void MapObj_StopAnim_1_001B7C10(u32 arg0, u64 arg1);

void MapCmd_SetObjectAnimC_0_0017DEB0(S *s)
{
    MapObj_StopAnim_1_001B7C10(s->a, s->b);
}
