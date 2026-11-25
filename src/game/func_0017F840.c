#include "common.h"

typedef struct { char b[0x4C]; } E;
extern E D_00486990[24];

void func_0017F840(s32 i, E **out)
{
    i %= 24;
    if (out)
        *out = &D_00486990[i];
}
