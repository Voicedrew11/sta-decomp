#include "m2c.h"
#include "common.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { u32 id; s32 x; s32 y; } Ent;
typedef struct { s32 h0; u32 n; s32 h8; s32 hC; Ent e[1]; } Tbl;
extern Q2 D_001F2F40;
extern s32 D_00201D38;
extern s32 D_00201D3C;
extern u32 D_00202190;
extern s32 D_00202198;
extern s32 D_004A1430[];
extern char D_001FD388[];
void DbItem_ResetLayout_0_00197DD0(void);
char* DbItem_GetListName_1_00197F30(s32 i);
void DbItem_LoadEntry_0_00197F90(s32 a0);
Tbl* DbItem_GetCount_1_001958A0(void);
s32 Save_TestItemBit_1_001A9B40(s16);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
void UiAnim_SetVisible_1_0017F7C0(s32, s32, s32);
void UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void DbItemProc_Pos_0_00198100(void);
char* DbItem_Find_1_0019D510(s32 i);
u8* Item_GetTable_1_001AFC90(void);
void memset(void *, s32, s32);
s32 ItemSort_GetCount_0_00195BE0(s32);
void Inventory_GetEntry_1_001CC3F0(s16);

/* DbItem_ResetLayout_0_00197DD0 */
#define DbItem_GetListName_1_00197F30 DbItem_GetListName_1_00197F30__as_DbItem_ResetLayout_0_00197DD0
void DbItem_GetListName_1_00197F30__as_DbItem_ResetLayout_0_00197DD0(void);

void DbItem_ResetLayout_0_00197DD0(void) {
    Q2 q;
    Arg a;
    Tbl *t;
    Ent *e;
    u32 i;
    s32 hit;
    u32 cnt;

    t = DbItem_GetCount_1_001958A0();
    if (t != 0) {
        hit = 0;
        cnt = 0;
        e = t->e;
        for (i = 0; i < t->n; i++, e++) {
            if (e->id >= 100) {
                if (Save_TestItemBit_1_001A9B40(e->id) != 0) {
                    hit++;
                }
                cnt++;
            }
        }
        D_00202190 = (u32)(hit * 100) / cnt;
        q = D_001F2F40;
        a.fn = DbItem_GetListName_1_00197F30;
        a.f = -3.0f;
        a.cb = DbItemProc_Pos_0_00198100;
        a.a = 0;
        a.b = 0;
        a.p = D_00201D3C;
        a.n = D_00202198;
        UiAnim_SetColor_0_0017F890(D_00201D38, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(D_00201D38, 1, 1);
        UiAnim_SetTarget_1_0017F470(D_004A1430[0], D_00201D38, 1);
    }
}
#undef DbItem_GetListName_1_00197F30

/* DbItem_GetListName_1_00197F30 */
char *DbItem_GetListName_1_00197F30(s32 i)
{
    if (i < 0)
        return D_001FD388;
    if (Save_TestItemBit_1_001A9B40(i))
        return DbItem_Find_1_0019D510(i);
    return D_001FD388;
}

/* DbItem_LoadEntry_0_00197F90 */
#define D_00201D3C D_00201D3C__as_DbItem_LoadEntry_0_00197F90
extern s32 *D_00201D3C__as_DbItem_LoadEntry_0_00197F90;

void DbItem_LoadEntry_0_00197F90(s32 a0) {
    s32 r;
    u8 *e;
    s32 i;
    u8 *base;
    s32 v;

    base = Item_GetTable_1_001AFC90();
    D_00202198 = 0;
    memset(D_00201D3C, -1, 4);
    for (i = 100; i < 0x400; i++) {
        Inventory_GetEntry_1_001CC3F0(ItemSort_GetCount_0_00195BE0(i));
        e = base + ItemSort_GetCount_0_00195BE0(i) * 0x90;
        if (*(u16 *)(e + 4) > 0 && (a0 >= 2 || *(u16 *)(e + 0xA) == 2)) {
            if (a0 < 2 || a0 >= 9 || (*(u16 *)(e + 0xA) == 1 && *(u16 *)(e + 0x20) == a0 - 2)) {
                v = ItemSort_GetCount_0_00195BE0(i);
                if (v < 0) {
                    r = 0;
                } else {
                    r = Save_TestItemBit_1_001A9B40(v);
                }
                if (r != 0) {
                    D_00201D3C[D_00202198] = v;
                } else {
                    D_00201D3C[D_00202198] = -1;
                }
                D_00202198++;
            }
        }
    }
}
#undef D_00201D3C
