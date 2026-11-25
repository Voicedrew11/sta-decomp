#include "common.h"

typedef struct { char pad[0x5B0]; u8 sel : 1; char pad2[0x103]; u16 v[2]; } S;

u16 func_0013E410(S *s)
{
    return s->v[s->sel];
}
