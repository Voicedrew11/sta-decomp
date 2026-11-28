#include "common.h"
#include "m2c.h"
typedef struct { u8 pad[0x1C]; u16 x1C; u8 p[0xA]; } T;
typedef struct { s32 x0; s32 x4; } U;
typedef struct { s32 id; u8 pad[0x6E]; u16 x72; u8 p74[0xCC]; T *x140; u8 p144[0x40]; U *x184; } O_MapObj_DropItem_0_001B0880;
typedef struct { s32 *p; } O_MapObj_SpawnItem_0_001B0990;
extern O_MapObj_DropItem_0_001B0880 **D_00201E80[2];
void MapObj_DropItem_0_001B0880(u16 a0, u16 a1);
void MapObj_SpawnItem_0_001B0990(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, u16 id, s32 t2);
void MapObj_SendEvent_1_001B0A80(void *arg0, s32 arg1);
void ItemObj_DropToGround_0_001AE0E0(O_MapObj_DropItem_0_001B0880 **, s32, O_MapObj_DropItem_0_001B0880 *);
s32 Inventory_CountItem_0_001CC0C0(s32, s32);
void ItemObj_Drop_0_001AE900(O_MapObj_SpawnItem_0_001B0990 *, s16, s32, s32, s32, s32);
void Script_SendEvent_2_00166F80(s32, s32, s32);

/* MapObj_DropItem_0_001B0880 */
#define C (D_00201E80[2])
#define D (D_00201E80[3])

void MapObj_DropItem_0_001B0880(u16 a0, u16 a1) {
    O_MapObj_DropItem_0_001B0880 **h;
    s32 i;
    O_MapObj_DropItem_0_001B0880 *o;
    h = 0;
    if (C) { O_MapObj_DropItem_0_001B0880 *t = *C; if (t && t->id == a0) h = C; }
    if (D) { O_MapObj_DropItem_0_001B0880 *t = *D; if (t && t->id == a0) h = D; }
    if (h == 0) return;
    i = 0;
    if (0 < (*h)->x72) {
        do {
            U *u;
            T *t;
            t = &(*h)->x140[i];
            u = &(*h)->x184[i];
            if (t->x1C == a1) ItemObj_DropToGround_0_001AE0E0(h, u->x0, *h);
            i++;
        } while (i < (*h)->x72);
    }
}
#undef C
#undef D

/* MapObj_SpawnItem_0_001B0990 */
#define D_00201E80 D_00201E80__as_MapObj_SpawnItem_0_001B0990
extern O_MapObj_SpawnItem_0_001B0990 *D_00201E80__as_MapObj_SpawnItem_0_001B0990[2];

void MapObj_SpawnItem_0_001B0990(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, u16 id, s32 t2) {
    O_MapObj_SpawnItem_0_001B0990 *o;
    O_MapObj_SpawnItem_0_001B0990 *p;
    o = 0;
    p = D_00201E80[2];
    if (p && p->p && *p->p == id) o = p;
    p = D_00201E80[3];
    if (p && p->p && *p->p == id) o = p;
    if (o && (u32)a0 < 0x400 && id < 200 && Inventory_CountItem_0_001CC0C0(a0, 1)) {
        ItemObj_Drop_0_001AE900(o, a0, a1, a2, t2, 0);
    }
}
#undef D_00201E80

/* MapObj_SendEvent_1_001B0A80 */
void MapObj_SendEvent_1_001B0A80(void *arg0, s32 arg1) {
    s32 *temp_6;

    if (arg0 != NULL) {
        temp_6 = M2C_FIELD(arg0, s32 **, 0xC);
        if ((temp_6 != NULL) && (M2C_FIELD(arg0, u8 *, 0x1D8) & 1)) {
            Script_SendEvent_2_00166F80(*temp_6, (arg1 != 0) ? 0x7FFE : 0x7FFD, 0);
        }
    }
}
