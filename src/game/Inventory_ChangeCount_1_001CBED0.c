#include "m2c.h"
typedef struct { s8 pad[0xA]; u16 xA; s8 pad2[0x90 - 0xC]; } A;
typedef struct { u8 x0, x1, hi, lo; } BE;
typedef struct { s8 pad[0xC]; u16 xC; s8 padE[0xA0 - 0xE]; BE e[1]; } B;
A *Item_GetTable_1_001AFC90(void);
B *PlayerData_Get_2_001C9BA0(void);
void Inventory_Recount_0_001CCE30(void);
void Player_RecalcStats_1_001CEDC0(s32);
void Save_SetItemBit_1_001A9B90(s32);
void memset(void *, s32, s32);

void Inventory_ChangeCount_1_001CBED0(s32 idx, s32 n, s32 v) {
    B *b; A *a; s16 i;
    b = PlayerData_Get_2_001C9BA0(); a = Item_GetTable_1_001AFC90(); i = idx;
    if (i < 0 || i >= 0x400) return;
    Save_SetItemBit_1_001A9B90(idx);
    b->e[i].x0 = v;
    b->e[i].hi += (u8)n;
    if (b->e[i].hi <= 0) b->e[i].hi = 0;
    if (b->e[i].hi > 99) b->e[i].hi = 99;
    if (b->e[i].hi == 0) {
        memset(&b->e[i], 0, 4);
        b->e[i].x0 = 0;
        b->e[i].x1 = 0;
        if (a[i].xA != 0) b->e[i].lo = 0;
    }
    if (a[i].xA == 1 || a[i].xA == 2) {
        if (b->e[i].hi > 1) b->e[i].hi = 1;
    }
    Inventory_Recount_0_001CCE30();
    Player_RecalcStats_1_001CEDC0(3);
    if (i == 1) b->xC = ((u8 *)b)[0xA6];
}
