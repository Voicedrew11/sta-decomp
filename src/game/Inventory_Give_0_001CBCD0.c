/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#include "m2c.h"
typedef struct { u8 pad0[0xA]; u16 xA; u8 pad1[0x14]; u16 x20; u8 pad2[0x1A]; u8 x3C; u8 pad3[2]; u8 x3F; u8 pad4[0x50]; } E;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { u8 pad0[0xA0]; Col col[1]; } V;
V *PlayerData_Get_2_001C9BA0(void);
E *Item_GetTable_1_001AFC90(void);
void Inventory_ChangeCount_1_001CBED0(s32, s32, s32);
static inline s32 cls(s32 x) {
    switch (x) {
    case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    case 9: case 19:
        return 2;
    }
    return 0;
}
static inline Col *getcol(s16 idx) {
    V *v = PlayerData_Get_2_001C9BA0();
    if (idx >= 0 && idx < 0x400) return &v->col[idx];
    return NULL;
}

void Inventory_Give_0_001CBCD0(s32 a0) {
    E *t = Item_GetTable_1_001AFC90();
    s16 idx = a0;
    s32 v = 0;
    if (idx < 0 || idx >= 0x400) return;
    switch (t[idx].xA) {
    case 0:
        break;
    case 1:
        v = t[idx].x3C;
        break;
    case 2:
        v = t[idx].x3C;
        break;
    }
    Inventory_ChangeCount_1_001CBED0(a0, 1, v);
    if (t[idx].xA != 2) return;
    if (cls(t[idx].x20) == 1) {
        Col *p = getcol(idx);
        p->a = t[idx].x3F;
    }
}

