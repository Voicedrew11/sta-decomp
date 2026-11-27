#include "m2c.h"
typedef struct { u8 pad0[0x60]; s16 ids[16]; u8 pad80[0x140]; } Grp;
typedef struct { u8 b0, b1, b2, b3, b4, b5, b6, b7; } Slot;
typedef struct { u8 pad0[0x10E0]; Grp grp[0x2A]; u8 pad5A60[0x1A0]; Slot slot[0x400]; } W;
typedef struct { u8 pad0[0xA]; u16 type; u8 padC[0x14]; u16 x20; u8 pad22[0x1A]; u8 x3C; u8 pad3D[2]; u8 x3F; u8 pad40[0x50]; } Item;
Item *Item_GetTable_1_001AFC90(void);
s32 Inventory_GetFlag_0_001CC060(s16);
s32 ItemType_IsWeapon_0_001D1D50(u16);
extern W *D_00201DC0;

void Inventory_AddItem_1_001A95A0(s16 id, u8 n) {
    Item *base;
    Slot *slot;
    Grp *g;
    s32 j;
    s32 k;
    s32 cnt;

    base = Item_GetTable_1_001AFC90();
    if (0 > id || id >= 0x400) {
        slot = NULL;
    } else {
        slot = &D_00201DC0->slot[id];
    }
    if (n == 0 || slot == NULL) {
        return;
    }
    if (base[id].type != 0) {
        if (Inventory_GetFlag_0_001CC060(id) != 0) {
            return;
        }
        if ((D_00201DC0->slot[id].b5 ? D_00201DC0->slot[id].b2 : 0) != 0) {
            return;
        }
        if (D_00201DC0->slot[id].b4 != 0) {
            return;
        }
        cnt = 0;
        g = D_00201DC0->grp;
        for (j = 0; j < 0x2A; j++, g++) {
            for (k = 0; k < 0x10; k++) {
                if (id == g->ids[k]) {
                    cnt++;
                }
            }
        }
        if (cnt != 0) {
            return;
        }
    }
    switch (base[id].type) {
    case 0:
        slot->b2 += n;
        if (slot->b2 > 99) {
            slot->b2 = 99;
        }
        slot->b5 = 3;
        break;
    case 1:
        slot->b0 = base[id].x3C;
        slot->b1 = 0;
        slot->b2 = 1;
        slot->b3 = 0;
        slot->b4 = 0;
        slot->b5 = 3;
        break;
    case 2:
        slot->b0 = base[id].x3C;
        slot->b1 = 0;
        slot->b2 = 1;
        slot->b3 = 0;
        slot->b4 = 0;
        slot->b5 = 3;
        if (ItemType_IsWeapon_0_001D1D50(base[id].x20) == 1) {
            slot->b3 = base[id].x3F;
        }
        break;
    }
}
