#include "m2c.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 pad2[0x2B-0xC]; u8 x2B; u8 pad3[0x90-0x2C]; } E;
s8 *PlayerData_Get_2_001C9BA0(void);
E *Item_GetTable_1_001AFC90(void);
s32 Inventory_GetSlotCount_0_001AA6D0(s16);
s32 Inventory_GetSlotFlag_0_001AA6B0(s16);
s32 Inventory_FindItem_0_001AA650(s16);
typedef struct { u8 a,b,c,d; } T4;
static inline E *gt(E *b, s32 i) { return &b[i]; }

s32 Inventory_CountItem_0_001CC0C0(s32 arg0, s32 arg1) {
    s8 *a;
    E *b;
    E *e;
    s32 sum;
    u8 *lim;

    a = PlayerData_Get_2_001C9BA0();
    b = Item_GetTable_1_001AFC90();
    sum = 0;
    if (arg0 <= 0 || !(arg0 < 0x400)) {
        return 0;
    }
    e = &b[arg0];
    if (b[arg0].xA == 0) {
        lim = &b[arg0].x2B;
        if (*lim == 0) {
            return 1;
        }
        sum += ((T4 *)(a + 0xA0))[arg0].c;
        sum += Inventory_GetSlotCount_0_001AA6D0(arg0);
        sum += Inventory_GetSlotFlag_0_001AA6B0(arg0);
        if (arg1) {
            sum += Inventory_FindItem_0_001AA650(arg0);
        }
        if (sum < *lim) {
            return 1;
        }
        return 0;
    }
    if (((T4 *)(a + 0xA0))[arg0].c > 0) {
        return 0;
    }
    if (Inventory_GetSlotCount_0_001AA6D0(arg0)) {
        return 0;
    }
    if (Inventory_GetSlotFlag_0_001AA6B0(arg0)) {
        return 0;
    }
    if (arg1 && Inventory_FindItem_0_001AA650(arg0)) {
        return 0;
    }
    return 1;
}
