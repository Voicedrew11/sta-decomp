#include "common.h"
typedef struct C C;
extern C **D_00201E80[2];
#define CC (((C ***)&D_00201E80)[2])
#define DD (((C ***)&D_00201E80)[3])
s32 Inventory_CountItem_0_001CC0C0(s16, s32);
void Map_DecodeTransform_0_001B59E0(void *, Vec *, Vec *, Vec *);
void ItemObj_SpawnFromMap_0_001AEE80(C **, s32, Vec *, Vec *, u16);

void MapObj_SpawnContainedItem_0_001BB760(C *c, s32 f, s32 id, void *m, s32 lift) {
    s32 k;
    Vec a;
    Vec b;
    Vec d;
    k = -1;
    if ((s16)id <= 0 || !((s16)id < 0x400)) return;
    if (CC && *CC && *CC == c) k = 0;
    if (DD && *DD && *DD == c) k = 1;
    if (k == -1) return;
    if (!Inventory_CountItem_0_001CC0C0(id, 0)) return;
    Map_DecodeTransform_0_001B59E0(m, &a, &b, &d);
    if (lift) a.y -= 20.0f;
    ItemObj_SpawnFromMap_0_001AEE80(D_00201E80[k + 2], id, &a, &b, f);
}
