#include "common.h"

typedef struct { char pad[0x3A1]; unsigned int : 5; unsigned int f : 1; } T;
u8 *func_00165130(s32 a, s32 b);
T *func_001C9B60(void);

void func_0017D0E0(s32 a)
{
    u8 *p = func_00165130(a, 0);
    T *t = func_001C9B60();
    if (t)
        *p = t->f;
    else
        *p = 0;
}
