#include "common.h"
typedef struct { u8 pad[0x60]; s16 v[16]; u8 pad2[0x1C0-0x80]; } G;
typedef struct { u8 b; char pad[7]; } E_Inventory_GetSlotFlag_0_001AA6B0;
typedef struct { char pad[0x5C04]; E_Inventory_GetSlotFlag_0_001AA6B0 e[1]; } S_Inventory_GetSlotFlag_0_001AA6B0;
typedef struct { char p0[2]; u8 b2; char p3[2]; u8 b5; char p6[2]; } E_Inventory_GetSlotCount_0_001AA6D0;
typedef struct { char pad[0x5C00]; E_Inventory_GetSlotCount_0_001AA6D0 e[1]; } S_Inventory_GetSlotCount_0_001AA6D0;
extern u8 *D_00201DC0;
s32 Inventory_FindItem_0_001AA650(s16 arg0);
u8 Inventory_GetSlotFlag_0_001AA6B0(s16 i);
u8 Inventory_GetSlotCount_0_001AA6D0(s16 i);

/* Inventory_FindItem_0_001AA650 */
s32 Inventory_FindItem_0_001AA650(s16 arg0) {
    s16 *p;
    G *g;
    s32 j;
    s32 i;
    s32 n;
    n = 0;
    g = (G *)(D_00201DC0 + 0x10E0);
    for (j = 0; j < 0x2A; j++) {
        for (i = 0; i < 0x10; i++) {
            if (arg0 == g[j].v[i]) n++;
        }
    }
    return n;
}

/* Inventory_GetSlotFlag_0_001AA6B0 */
#define D_00201DC0 D_00201DC0__as_Inventory_GetSlotFlag_0_001AA6B0
extern S_Inventory_GetSlotFlag_0_001AA6B0 *D_00201DC0__as_Inventory_GetSlotFlag_0_001AA6B0;

u8 Inventory_GetSlotFlag_0_001AA6B0(s16 i)
{
    return D_00201DC0->e[i].b;
}
#undef D_00201DC0

/* Inventory_GetSlotCount_0_001AA6D0 */
#define D_00201DC0 D_00201DC0__as_Inventory_GetSlotCount_0_001AA6D0
extern S_Inventory_GetSlotCount_0_001AA6D0 *D_00201DC0__as_Inventory_GetSlotCount_0_001AA6D0;
u8 Inventory_GetSlotCount_0_001AA6D0(s16 i) { if (D_00201DC0->e[i].b5) return D_00201DC0->e[i].b2; return 0; }
#undef D_00201DC0
