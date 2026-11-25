#include "common.h"

extern struct { unsigned char : 7; unsigned char f : 1; char pad[15]; } D_002F2078;

void func_00159310(int v)
{
    D_002F2078.f = v;
}
