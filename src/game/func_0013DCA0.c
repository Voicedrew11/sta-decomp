#include "common.h"

typedef struct { char pad[0x4B4]; s32 v[1]; } S;

s32 func_0013DCA0(S *s, u8 i)
{
    return s->v[i];
}
