#include "common.h"

typedef struct { char pad[0x250]; } E;
extern E D_0049F8A0[];

E *func_00189050(s32 i)
{
    return &D_0049F8A0[i];
}
