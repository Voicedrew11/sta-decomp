#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
s8 *func_00165130(s32 a, s32 b);
s8 func_0013EC50(void *p);

void func_001451A0(s32 a)
{
    void *p = D_00201FA8->p;
    s8 *q = func_00165130(a, 0);
    *q = func_0013EC50(p);
}
