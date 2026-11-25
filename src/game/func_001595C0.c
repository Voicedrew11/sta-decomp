#include "common.h"

extern struct { unsigned char : 4; unsigned char f : 1; char pad[15]; } D_002F2078;
extern s32 D_002F1A60[];

s32 *func_001595C0(int v)
{
    D_002F2078.f = v != 0;
    return D_002F1A60;
}
