#include "common.h"

typedef struct { char pad[0x5B60]; u32 bits[1]; } S;
extern S *D_00201DC0;

s32 func_001A9B40(s16 i)
{
    return (D_00201DC0->bits[i / 32] & (1 << (i % 32))) != 0;
}
