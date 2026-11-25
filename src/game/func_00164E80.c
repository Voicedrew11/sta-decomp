#include "common.h"

typedef struct { s32 v; char rest[0x254]; } E;
typedef struct { char p0[4]; s32 n; char p8[0x28C]; E e[1]; } S;
extern S *D_00201FA4;

void func_00164E80(void)
{
    s32 i;
    for (i = 0; i < D_00201FA4->n; i++)
        D_00201FA4->e[i].v = 0;
}
