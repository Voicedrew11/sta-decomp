#include "m2c.h"
typedef struct { s32 *p; } O;
extern O *D_00201E80[2];
s32 Inventory_CountItem_0_001CC0C0(s32, s32);
void ItemObj_Drop_0_001AE900(O *, s16, s32, s32, s32, s32);

void MapObj_SpawnItem_0_001B0990(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, u16 id, s32 t2) {
    O *o;
    O *p;
    o = 0;
    p = D_00201E80[2];
    if (p && p->p && *p->p == id) o = p;
    p = D_00201E80[3];
    if (p && p->p && *p->p == id) o = p;
    if (o && (u32)a0 < 0x400 && id < 200 && Inventory_CountItem_0_001CC0C0(a0, 1)) {
        ItemObj_Drop_0_001AE900(o, a0, a1, a2, t2, 0);
    }
}
