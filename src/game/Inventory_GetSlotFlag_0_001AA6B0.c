#include "common.h"

typedef struct { u8 b; char pad[7]; } E;
typedef struct { char pad[0x5C04]; E e[1]; } S;
extern S *D_00201DC0;

u8 Inventory_GetSlotFlag_0_001AA6B0(s16 i)
{
    return D_00201DC0->e[i].b;
}
