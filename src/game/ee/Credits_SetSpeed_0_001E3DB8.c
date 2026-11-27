#include "common.h"

extern struct { u32 n; u32 pad[2]; } D_004BC368;

void Credits_SetSpeed_0_001E3DB8(u32 n)
{
    if (n > 8)
        n = 8;
    D_004BC368.n = n;
}
