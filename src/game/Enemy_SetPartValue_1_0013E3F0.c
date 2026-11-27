#include "common.h"

typedef struct { char pad[0x6B4]; s16 v[1]; } S;

void Enemy_SetPartValue_1_0013E3F0(S *s, u8 i, s16 v)
{
    s->v[i] = v;
}
