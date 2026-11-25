#include "common.h"

extern struct { unsigned char : 2; unsigned char f : 1; char pad[15]; } D_002F2078;

void func_001595F0(int v)
{
    D_002F2078.f = v != 0;
}
