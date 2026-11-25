#include "common.h"

typedef struct { void (*a)(s32); void (*b)(s32); void (*c)(s32); } E;
extern E D_001F1EA0[];

s32 func_0014D8E0(u16 i, s32 v)
{
    if (i >= 29)
        return 0;
    D_001F1EA0[i].c(v);
    return 1;
}
