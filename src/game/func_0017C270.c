#include "common.h"

extern s32 D_00201E94;
s32 *func_00165130(s32 a, s32 b);

void func_0017C270(s32 a)
{
    s32 *p = func_00165130(a, 0);
    *p = D_00201E94;
}
