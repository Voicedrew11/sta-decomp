#include "common.h"

s8 *func_00165130(void *a, s32 b);
s8 func_0013D500(u8 v);

void func_00145100(u8 *a)
{
    s8 *p = func_00165130(a, 0);
    *p = func_0013D500(a[0x10]);
}
