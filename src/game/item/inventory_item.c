#include "common.h"
#include "m2c.h"
typedef struct { s8 pad[0xA]; u16 xA; s8 pad2[0x29 - 0xC]; u8 type; u8 cnt; s8 pad3[0x90 - 0x2B]; } A_Inventory_Consume_0_001CBA80;
typedef struct { u8 x0, x1, hi, lo; } BE;
typedef struct { s8 pad[0xA0]; BE e[1]; } B_Inventory_Consume_0_001CBA80;
typedef struct { char p0[0xA]; u16 h; char pc[0x1D]; u8 b29; u8 b2a; char rest[0x65]; } E_Inventory_HasItem_0_001CBC20;
typedef struct { u8 b0, b1, b2, b3; } F;
typedef struct { char pad[0xA0]; F f[0x400]; } T_Inventory_HasItem_0_001CBC20;
typedef struct { u8 pad0[0xA]; u16 xA; u8 pad1[0x14]; u16 x20; u8 pad2[0x1A]; u8 x3C; u8 pad3[2]; u8 x3F; u8 pad4[0x50]; } E_Inventory_Give_0_001CBCD0;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { u8 pad0[0xA0]; Col col[1]; } V;
typedef struct { s8 pad[0xA]; u16 xA; s8 pad2[0x90 - 0xC]; } A_Inventory_CanCarry_0_001CBE40;
typedef struct { s8 pad[0xA0]; BE e[1]; } B_Inventory_CanCarry_0_001CBE40;
typedef struct { s8 pad[0xA]; u16 xA; s8 pad2[0x90 - 0xC]; } A_Inventory_ChangeCount_1_001CBED0;
typedef struct { s8 pad[0xC]; u16 xC; s8 padE[0xA0 - 0xE]; BE e[1]; } B_Inventory_ChangeCount_1_001CBED0;
typedef struct { char p[2]; u8 b; char q; } E_Inventory_GetFlag_0_001CC060;
typedef struct { char pad[0xA0]; E_Inventory_GetFlag_0_001CC060 e[0x400]; } T_Inventory_GetFlag_0_001CC060;
typedef struct { u8 pad[0xA]; u16 xA; u8 pad2[0x2B-0xC]; u8 x2B; u8 pad3[0x90-0x2C]; } E_Inventory_CountItem_0_001CC0C0;
typedef struct { u8 a,b,c,d; } T4;
void Inventory_RemoveOne_1_001CBA60(s16 x);
void Inventory_Consume_0_001CBA80(s16 idx, u8 n);
s32 Inventory_HasItem_0_001CBC20(s16 i);
void Inventory_Give_0_001CBCD0(s32 a0);
s32 Inventory_CanCarry_0_001CBE40(s16 i);
void Inventory_ChangeCount_1_001CBED0(s32 idx, s32 n, s32 v);
u8 Inventory_GetFlag_0_001CC060(s16 i);
s32 Inventory_CountItem_0_001CC0C0(s32 arg0, s32 arg1);
A_Inventory_Consume_0_001CBA80* Item_GetTable_1_001AFC90(void);
B_Inventory_Consume_0_001CBA80* PlayerData_Get_2_001C9BA0(void);
void Inventory_Recount_0_001CCE30(void);
void Player_RecalcStats_1_001CEDC0(s32);
void Save_SetItemBit_1_001A9B90(s32);
void memset(void *, s32, s32);
s32 Inventory_GetSlotCount_0_001AA6D0(s16);
s32 Inventory_GetSlotFlag_0_001AA6B0(s16);
s32 Inventory_FindItem_0_001AA650(s16);

/* Inventory_RemoveOne_1_001CBA60 */
#define Inventory_ChangeCount_1_001CBED0 Inventory_ChangeCount_1_001CBED0__as_Inventory_RemoveOne_1_001CBA60
void Inventory_ChangeCount_1_001CBED0__as_Inventory_RemoveOne_1_001CBA60(s32 a, s32 b, s64 c);

void Inventory_RemoveOne_1_001CBA60(s16 x)
{
    Inventory_ChangeCount_1_001CBED0(1, x, 0);
}
#undef Inventory_ChangeCount_1_001CBED0

/* Inventory_Consume_0_001CBA80 */
static inline s32 getVal(s16 idx) {
    A_Inventory_Consume_0_001CBA80 *a = Item_GetTable_1_001AFC90();
    B_Inventory_Consume_0_001CBA80 *b = PlayerData_Get_2_001C9BA0();
    if (idx < 0 || idx >= 0x400) return 0;
    if (a[idx].xA == 0 && a[idx].type == 5) return b->e[idx].lo + b->e[idx].hi * a[idx].cnt;
    return 0;
}

void Inventory_Consume_0_001CBA80(s16 idx, u8 n) {
    A_Inventory_Consume_0_001CBA80 *a = Item_GetTable_1_001AFC90();
    B_Inventory_Consume_0_001CBA80 *b = PlayerData_Get_2_001C9BA0();
    s32 v;
    if (idx < 0 || idx >= 0x400) return;
    if (a[idx].xA == 0 && a[idx].type == 5 && a[idx].cnt > 0) {
        if (n != 0) {
            v = getVal(idx) - n;
            if (v < 0) v = 0;
            b->e[idx].hi = v / a[idx].cnt;
            b->e[idx].lo = v % a[idx].cnt;
            Inventory_Recount_0_001CCE30();
        }
    }
}

/* Inventory_HasItem_0_001CBC20 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Inventory_HasItem_0_001CBC20
E_Inventory_HasItem_0_001CBC20 *Item_GetTable_1_001AFC90__as_Inventory_HasItem_0_001CBC20(s16 i);
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Inventory_HasItem_0_001CBC20
T_Inventory_HasItem_0_001CBC20 *PlayerData_Get_2_001C9BA0__as_Inventory_HasItem_0_001CBC20(void);

s32 Inventory_HasItem_0_001CBC20(s16 i)
{
    E_Inventory_HasItem_0_001CBC20 *e = Item_GetTable_1_001AFC90(i);
    T_Inventory_HasItem_0_001CBC20 *t = PlayerData_Get_2_001C9BA0();
    if (i < 0 || i >= 0x400)
        return 0;
    if (e[i].h == 0 && e[i].b29 == 5)
        return t->f[i].b3 + t->f[i].b2 * e[i].b2a;
    return 0;
}
#undef Item_GetTable_1_001AFC90
#undef PlayerData_Get_2_001C9BA0

/* Inventory_Give_0_001CBCD0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Inventory_Give_0_001CBCD0
V *PlayerData_Get_2_001C9BA0__as_Inventory_Give_0_001CBCD0(void);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Inventory_Give_0_001CBCD0
E_Inventory_Give_0_001CBCD0 *Item_GetTable_1_001AFC90__as_Inventory_Give_0_001CBCD0(void);
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
    E_Inventory_Give_0_001CBCD0 *t = Item_GetTable_1_001AFC90();
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
#undef PlayerData_Get_2_001C9BA0
#undef Item_GetTable_1_001AFC90

/* Inventory_CanCarry_0_001CBE40 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Inventory_CanCarry_0_001CBE40
A_Inventory_CanCarry_0_001CBE40 *Item_GetTable_1_001AFC90__as_Inventory_CanCarry_0_001CBE40(void);
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Inventory_CanCarry_0_001CBE40
B_Inventory_CanCarry_0_001CBE40 *PlayerData_Get_2_001C9BA0__as_Inventory_CanCarry_0_001CBE40(void);
static inline s32 get(s16 i) {
    B_Inventory_CanCarry_0_001CBE40 *b = PlayerData_Get_2_001C9BA0();
    s32 t;
    if (i < 0 || i >= 0x400) return 0;
    t = b->e[i].hi + 1;
    return !(t < 0) && t < 100;
}
s32 Inventory_CanCarry_0_001CBE40(s16 i) {
    A_Inventory_CanCarry_0_001CBE40 *a = Item_GetTable_1_001AFC90();
    if (i < 0 || i >= 0x400) return 0;
    return get(i);
}
#undef Item_GetTable_1_001AFC90
#undef PlayerData_Get_2_001C9BA0

/* Inventory_ChangeCount_1_001CBED0 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Inventory_ChangeCount_1_001CBED0
A_Inventory_ChangeCount_1_001CBED0 *Item_GetTable_1_001AFC90__as_Inventory_ChangeCount_1_001CBED0(void);
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Inventory_ChangeCount_1_001CBED0
B_Inventory_ChangeCount_1_001CBED0 *PlayerData_Get_2_001C9BA0__as_Inventory_ChangeCount_1_001CBED0(void);

void Inventory_ChangeCount_1_001CBED0(s32 idx, s32 n, s32 v) {
    B_Inventory_ChangeCount_1_001CBED0 *b; A_Inventory_ChangeCount_1_001CBED0 *a; s16 i;
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
#undef Item_GetTable_1_001AFC90
#undef PlayerData_Get_2_001C9BA0

/* Inventory_GetFlag_0_001CC060 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Inventory_GetFlag_0_001CC060
T_Inventory_GetFlag_0_001CC060 *PlayerData_Get_2_001C9BA0__as_Inventory_GetFlag_0_001CC060(void);

u8 Inventory_GetFlag_0_001CC060(s16 i)
{
    T_Inventory_GetFlag_0_001CC060 *t = PlayerData_Get_2_001C9BA0();
    if (i < 0 || i >= 0x400)
        return 0;
    return t->e[i].b;
}
#undef PlayerData_Get_2_001C9BA0

/* Inventory_CountItem_0_001CC0C0 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Inventory_CountItem_0_001CC0C0
s8 *PlayerData_Get_2_001C9BA0__as_Inventory_CountItem_0_001CC0C0(void);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Inventory_CountItem_0_001CC0C0
E_Inventory_CountItem_0_001CC0C0 *Item_GetTable_1_001AFC90__as_Inventory_CountItem_0_001CC0C0(void);
static inline E_Inventory_CountItem_0_001CC0C0 *gt(E_Inventory_CountItem_0_001CC0C0 *b, s32 i) { return &b[i]; }

s32 Inventory_CountItem_0_001CC0C0(s32 arg0, s32 arg1) {
    s8 *a;
    E_Inventory_CountItem_0_001CC0C0 *b;
    E_Inventory_CountItem_0_001CC0C0 *e;
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
#undef PlayerData_Get_2_001C9BA0
#undef Item_GetTable_1_001AFC90
