#include "common.h"

extern s32 D_00201E10;
void memcpy(void *p, s32 v, s32 n);

void Option_Store_1_001A94E0(void *p)
{
    if (p)
        memcpy(p, D_00201E10, 0x10);
}
