#include "common.h"

typedef struct { char pad[0x5B60]; u32 bits[1]; } S;
extern S *D_00201DC0;

void func_001A9B90(s16 i)
{
    D_00201DC0->bits[i / 32] |= 1 << (i % 32);
}
