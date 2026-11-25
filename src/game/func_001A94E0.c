#include "common.h"

extern s32 D_00201E10;
void func_00123A88(void *p, s32 v, s32 n);

void func_001A94E0(void *p)
{
    if (p)
        func_00123A88(p, D_00201E10, 0x10);
}
