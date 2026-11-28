#include "common.h"
typedef struct { char pad[0x5B60]; u32 bits[1]; } S;
extern S *D_00201DC0;
s32 Save_TestItemBit_1_001A9B40(s16 i);
void Save_SetItemBit_1_001A9B90(s16 i);

/* Save_TestItemBit_1_001A9B40 */
s32 Save_TestItemBit_1_001A9B40(s16 i)
{
    return (D_00201DC0->bits[i / 32] & (1 << (i % 32))) != 0;
}

/* Save_SetItemBit_1_001A9B90 */
void Save_SetItemBit_1_001A9B90(s16 i)
{
    D_00201DC0->bits[i / 32] |= 1 << (i % 32);
}
