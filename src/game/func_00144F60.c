#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
s16 *func_00165130(s32 a, s32 b);
s16 func_0013E110(void *p);

void func_00144F60(s32 a)
{
    void *p = D_00201FA8->p;
    s16 *q = func_00165130(a, 0);
    *q = func_0013E110(p);
}
