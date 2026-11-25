#include "common.h"

s32 *func_00165130(s32 a, s32 b);
s32 func_0015ED20(void);

void func_0017CB50(s32 a)
{
    s32 *p = func_00165130(a, 0);
    s32 v = func_0015ED20();
    if (v < 0)
        v = -v;
    *p = v;
}
