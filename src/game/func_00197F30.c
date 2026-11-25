#include "common.h"

extern char D_001FD388[];
s32 func_001A9B40(s16 i);
char *func_0019D510(s32 i);

char *func_00197F30(s32 i)
{
    if (i < 0)
        return D_001FD388;
    if (func_001A9B40(i))
        return func_0019D510(i);
    return D_001FD388;
}
