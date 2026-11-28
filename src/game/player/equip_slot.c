#include "common.h"
#include "m2c.h"
#include "game/player.h"
typedef struct { char pad[0x80]; char sub[1]; } T;
typedef struct { u8 pad[0x20]; u16 x20; u8 pad22[0x6E]; } E_Equip_Assign_1_001CCF50;
typedef struct { u8 pad0[0xA]; u16 xA; u8 pad1[0x1A]; u8 s[6]; u8 pad2[0x90-0x2C]; } E_Equip_FindSlot_0_001CD2D0;
void Equip_Assign_1_001CCF50(s16 *slots, s32 idx, s16 id);
T* PlayerData_Get_2_001C9BA0(void);
void Player_RecalcStats_1_001CEDC0(s32 v);
E_Equip_Assign_1_001CCF50* Item_GetTable_1_001AFC90(void);

/* Equip_SetSlot_0_001CCF00 */
#define Equip_Assign_1_001CCF50 Equip_Assign_1_001CCF50__as_Equip_SetSlot_0_001CCF00
void Equip_Assign_1_001CCF50__as_Equip_SetSlot_0_001CCF00(void *p, s32 a, s32 b);

void Equip_SetSlot_0_001CCF00(s32 a, s32 b)
{
    T *t = PlayerData_Get_2_001C9BA0();
    Equip_Assign_1_001CCF50(t->sub, a, b);
    Player_RecalcStats_1_001CEDC0(3);
}
#undef Equip_Assign_1_001CCF50

/* Equip_Assign_1_001CCF50 */
static inline s32 two(E_Equip_Assign_1_001CCF50 *e) {
    switch (e->x20) {
    case 2:
    case 4:
    case 6:
    case 9:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
        return 1;
    }
    return 0;
}

void Equip_Assign_1_001CCF50(s16 *slots, s32 idx, s16 id) {
    E_Equip_Assign_1_001CCF50 *base = Item_GetTable_1_001AFC90();
    s32 cur;

    if (idx < 0 || idx >= 10) {
        return;
    }
    if (slots == NULL) {
        return;
    }
    if (idx >= 2) {
        if (id == slots[idx]) {
            slots[idx] = -1;
        } else {
            slots[idx] = id;
        }
        return;
    }
    cur = slots[idx];
    if (id == -1 || id == cur) {
        if (cur <= 0) {
            return;
        }
        if (two(&base[cur])) {
            slots[idx] = -1;
            slots[!idx] = -1;
        } else {
            slots[idx] = -1;
        }
        return;
    }
    if (two(&base[id])) {
        slots[idx] = id;
        slots[!idx] = id;
        return;
    }
    if (cur > 0 && two(&base[cur])) {
        slots[idx] = -1;
        slots[!idx] = -1;
    }
    slots[idx] = id;
    if (slots[!idx] == id) {
        slots[!idx] = -1;
    }
}

/* Equip_FindSlot_0_001CD2D0 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Equip_FindSlot_0_001CD2D0
u8 *Item_GetTable_1_001AFC90__as_Equip_FindSlot_0_001CD2D0(void);
static inline s16 slot(s32 arg0) {
    s8 *v = PlayerData_Get_2_001C9BA0();
    if (arg0 >= 0 && arg0 < 10) {
        return *(s16 *)(v + 0x80 + arg0 * 2);
    }
    return -1;
}

s32 Equip_FindSlot_0_001CD2D0(s32 a0) {
    E_Equip_FindSlot_0_001CD2D0 *base = (E_Equip_FindSlot_0_001CD2D0 *)Item_GetTable_1_001AFC90();
    s32 i;
    s16 idx;
    for (i = 2; i <= 8; i++) {
        idx = slot(i);
        if (idx > 0 && base[idx].xA == 1) {
            switch (a0) {
            case 0: if (base[idx].s[0] >= 100) return 1; break;
            case 1: if (base[idx].s[1] >= 100) return 1; break;
            case 2: if (base[idx].s[2] >= 100) return 1; break;
            case 3: if (base[idx].s[4] >= 100) return 1; break;
            case 4: if (base[idx].s[3] >= 100) return 1; break;
            case 5: if (base[idx].s[5] >= 100) return 1; break;
            }
        }
    }
    return 0;
}
#undef Item_GetTable_1_001AFC90
