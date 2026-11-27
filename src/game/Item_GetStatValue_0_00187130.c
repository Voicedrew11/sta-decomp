#include "m2c.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x30]; u8 x3C; u8 pad3D[0x53]; } E;
E *Item_GetTable_1_001AFC90(void);
u8 *Inventory_GetEntry_1_001CC3F0(s16);
u8 *Inventory_GetSlot_1_001A97D0(s16);

s32 Item_GetStatValue_0_00187130(s32 idx, s32 flag) {
    E *e = &Item_GetTable_1_001AFC90()[idx];
    f32 r;

    if (flag == 0) {
        if (e->xA == 1) {
            r = (f32)*Inventory_GetEntry_1_001CC3F0(idx) / (f32)e->x3C;
        } else if (e->xA == 2) {
            r = (f32)*Inventory_GetEntry_1_001CC3F0(idx) / (f32)e->x3C;
        } else {
            return 0;
        }
        if (r <= 0.2f || *Inventory_GetEntry_1_001CC3F0(idx) < 5) {
            return 1;
        }
    } else {
        if (e->xA == 1) {
            r = (f32)*Inventory_GetSlot_1_001A97D0(idx) / (f32)e->x3C;
        } else if (e->xA == 2) {
            r = (f32)*Inventory_GetSlot_1_001A97D0(idx) / (f32)e->x3C;
        } else {
            return 0;
        }
        if (r <= 0.2f || *Inventory_GetSlot_1_001A97D0(idx) < 5) {
            return 1;
        }
    }
    return 0;
}
