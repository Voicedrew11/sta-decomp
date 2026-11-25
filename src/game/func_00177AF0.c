#include "common.h"

void *func_00177BB0(s32 a, s32 b, s32 c);

void *func_00177AF0(s32 a, s32 b)
{
    void *p = func_00177BB0(a, b, -1);
    if (p)
        return p;
    return NULL;
}
