#include "common.h"

typedef struct { char pad[0x40]; char sub[0x210]; } E;
extern E D_0049F8A0[];

void *func_00189020(s32 i)
{
    return D_0049F8A0[i].sub;
}
