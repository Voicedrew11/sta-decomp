#include "common.h"

typedef struct { s32 a; s32 b; char pad[0x18]; } E;
extern E D_004B9F20[4];

void func_001D8EC0(s32 i, s32 a, s32 b)
{
    if (i < 0 || i >= 4)
        return;
    if (a) {
        D_004B9F20[i].a = a;
        D_004B9F20[i].b = b;
    }
}
