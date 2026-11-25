#include "common.h"

s8 *func_00165130(s32 a, s32 b);
s8 func_00145620(void);

void func_00143B60(s32 a)
{
    s8 *p = func_00165130(a, 0);
    *p = func_00145620();
}
