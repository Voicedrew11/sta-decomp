#include "common.h"

extern struct { unsigned char f : 1; char pad[15]; } D_002F2078;
extern s32 D_002F19C0[];

s32 *func_00159650(int v)
{
    D_002F2078.f = v != 0;
    return D_002F19C0;
}
