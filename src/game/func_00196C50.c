#include "common.h"

extern char D_001FD358[];
s32 func_001A9EC0(s16 i);
char *func_00195970(s32 i);

char *func_00196C50(s32 i)
{
    if (i < 0)
        return D_001FD358;
    if (func_001A9EC0(i))
        return func_00195970(i);
    return D_001FD358;
}
