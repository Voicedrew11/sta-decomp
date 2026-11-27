#include "common.h"

void Inventory_ChangeCount_1_001CBED0(s32 a, s32 b, s64 c);

void Inventory_RemoveOne_1_001CBA60(s16 x)
{
    Inventory_ChangeCount_1_001CBED0(1, x, 0);
}
