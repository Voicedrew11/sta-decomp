#include "common.h"

typedef struct { char pad[0x160]; u8 flags; } S;

u8 Actor_IsFlag1Clear_1_0013BA70(s32 arg0, s32 arg1, S *s)
{
    return !(s->flags & 1);
}
