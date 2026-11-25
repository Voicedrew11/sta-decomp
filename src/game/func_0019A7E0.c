#include "common.h"

extern s32 D_002021D8, D_002021DC, D_002021CC, D_002021C4, D_002021C8;
extern struct { unsigned char f : 1; char pad[15]; } D_001F306C, D_001F307C;

void func_0019A7E0(void)
{
    D_002021D8 = -1;
    D_002021DC = -1;
    D_002021CC = 1;
    D_002021C4 = 0;
    D_002021C8 = 0;
    D_001F306C.f = 1;
    D_001F307C.f = 1;
}
