#include "common.h"

typedef struct { char pad[8]; u16 a, b, c, d; } S;

u16 func_001D10B0(S *s)
{
    u16 v = s->a * 4 + 500 + (s->d + (s->b + s->c)) * 2;
    if ((s16)v < 0)
        v = 0;
    if ((s16)v > 9999)
        v = 9999;
    return v;
}
