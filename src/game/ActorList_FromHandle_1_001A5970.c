#include "common.h"

extern s32 D_004A4570[];

s32 ActorList_FromHandle_1_001A5970(u16 *p)
{
    return D_004A4570[p[1]];
}
