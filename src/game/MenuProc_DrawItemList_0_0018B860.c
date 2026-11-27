#include "common.h"
#include "m2c.h"
typedef union { u32 w; u8 c[4]; } Col_MenuProc_DrawItemList_0_0018B860;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[8]; Col_MenuProc_DrawItemList_0_0018B860 c; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[4]; List *list; } Res;
typedef struct { s32 v[8]; } Tbl;
typedef struct { s32 x0; s32 x4; u8 x8; } Obj;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col_SaveMenu_DrawSlotInfo_2_0018BCC0;
typedef struct { s16 x0, x2, x4, x6; u16 x8; u8 xA, xB; u8 padC[2]; u8 xE, xF; } Ent;
typedef struct { u8 pad0[0x50]; Ent e[10]; } Slot;
typedef struct { s32 a[4]; s32 arr[8]; } Buf;
typedef struct {
    u8 pad0[0x28];
    s32 x28;
    u8 pad2C[3];
    u8 x2F;
    f32 x30, x34, x38, x3C;
} O;
extern Tbl D_001F2A30 __attribute__((aligned(16)));
extern f32 D_0020211C;
extern s32 D_004A0FF0[];
extern s32 D_004A0FFC[];
extern f32 D_004A1008[];
extern f32 D_004A100C[];
extern Flags8 D_004A1010[];
extern S D_001F2A10[] __attribute__((aligned(16)));
extern Slot D_004A0900[];
extern char D_001FCD00[];
extern char D_001FCD10[];
extern char D_001FCD20[];
extern char D_001FCD30[];
extern char D_001FCD40[];
extern char D_001FCD58[];
extern char D_001FCD60[];
void MenuProc_DrawItemList_0_0018B860(Obj *o);
void SaveMenu_DrawSlotInfo_2_0018BCC0(O *o, s32 unused, u32 id, s32 n);
Res* MenuLayout_Get_1_00189050(s32);
s8* MenuLayout_GetSub_1_00189020(s32);
void Menu_SetFlags_0_0018A310(s32);
void Ui_BeginSprites_1_00181420(void);
void Ui_SetAlphaClamped_0_00182050(s32);
f32 Approachf_3_00187770(f32, f32, f32);
void Menu_LerpLayout_0_0018C140(f32 *, f32 *, Col_MenuProc_DrawItemList_0_0018B860 *, f32);
void Ui_DrawList_1_001829B0(Item *, s8 *, void (*)(), s32);
void Ui_DrawItemIconEx_0_0017EDC0(s32, s32, s32, s32, s32);
s32 SaveSys_GetPort_1_001E8290(void);
s8* Save_GetSlotInfo_0_00188FF0(s32);
void SaveSys_GetSlotCount_0_001E5E80(Buf *);
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, S *, u32);
void sprintf(char *, char *, ...);
void Text_Draw_2_001875C0(f32, f32, f32, char *, s32, u32);
char* DbMap_GetLocationName_1_00195AA0(s32);
char* Msg_GetText_2_00195B10(s32);

/* MenuProc_DrawItemList_0_0018B860 */

void MenuProc_DrawItemList_0_0018B860(Obj *o) {
    f32 x;
    f32 y;
    Col_MenuProc_DrawItemList_0_0018B860 c;
    Tbl tbl __attribute__((aligned(16)));
    Item it;
    List *l;
    s8 *base;
    s32 off;
    u32 j;
    s32 i;
    s32 v;
    s32 *p;
    s32 t;
    u32 k;

    tbl = D_001F2A30;
    l = MenuLayout_Get_1_00189050(4)->list;
    base = MenuLayout_GetSub_1_00189020(4);
    Menu_SetFlags_0_0018A310(8);
    Ui_BeginSprites_1_00181420();
    if (o->x0 == 0x16) {
        D_004A1008[0] += 8.0f;
    }
    Ui_SetAlphaClamped_0_00182050((s32)D_004A1008[0]);
    switch (D_004A0FFC[0]) {
    case 1:
        D_0020211C = Approachf_3_00187770(D_0020211C, 2.0f, 2.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 10;
            D_004A0FF0[0] = 6;
            D_0020211C = 15.0f;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    case 3:
        D_0020211C = Approachf_3_00187770(D_0020211C, 13.0f, 2.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A100C[0] = 10.0f;
            D_0020211C = 0.0f;
            D_004A0FFC[0] = 10;
            D_004A0FF0[0] = 0;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    case 10:
        D_0020211C = Approachf_3_00187770(D_0020211C, D_004A0FF0[0] + 4, 5.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A0FFC[0] = 0;
            D_004A1010[0].f.b0 = 1;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    default:
        D_0020211C = D_0020211C - (D_0020211C - (f32)(D_004A0FF0[0] + 4)) / 4.0f;
        break;
    }
    i = 0;
    v = (s32)D_0020211C;
    p = tbl.v;
    for (; i < 5; i++) {
        if (v - 5 >= 0 && v - 5 < 7) {
            *p = v - 5;
        } else {
            *p = -1;
        }
        v++;
        p++;
    }
    j = 0;
    if (j < l->n) { off = 0; do {
        it = *(Item *)((s8 *)l->items + off);
        Menu_LerpLayout_0_0018C140(&x, &y, &c, D_0020211C + (f32)(s32)j);
        it.f2C = x;
        it.f30 = y;
        it.c = c;
        t = tbl.v[((s32)D_0020211C + j) % l->n];
        if (t != -1) {
            Ui_DrawList_1_001829B0(&it, base + it.idx * 8, SaveMenu_DrawSlotInfo_2_0018BCC0, t);
        }
        off += 0x40; j++;
    } while (j < l->n); }
    Ui_DrawItemIconEx_0_0017EDC0(o->x8 == 0xB, D_004A1010[0].f.b1, 1, 7, D_004A0FF0[0]);
    Ui_BeginSprites_1_00181420();
    Ui_SetAlphaClamped_0_00182050(0x80);
}

/* SaveMenu_DrawSlotInfo_2_0018BCC0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */

void SaveMenu_DrawSlotInfo_2_0018BCC0(O *o, s32 unused, u32 id, s32 n) {
    S t __attribute__((aligned(16))) = D_001F2A10[0];
    Ent *e = &D_004A0900[SaveSys_GetPort_1_001E8290()].e[n];
    s32 s0 = Save_GetSlotInfo_0_00188FF0(0)[n];
    char buf[0x100] = {0};
    Buf b = {0};
    Col_SaveMenu_DrawSlotInfo_2_0018BCC0 col;
    u8 f;
    col.w = 0x80808080;
    col.c.a = o->x2F * 2;
    SaveSys_GetSlotCount_0_001E5E80(&b);
    if (id < 2000) {
        t.x = o->x30;
        t.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, (u8 *)o + 0x10, (u8 *)o + 0x2C, &t, id);
        return;
    }
    if ((f = e->xF) != 0 && s0 == 0) {
        switch (id) {
        case 2001:
            break;
        case 2002:
            if (e->xE) {
                col.c.r = 0x20;
                col.c.g = 0x20;
            }
            sprintf(buf, D_001FCD00, n + 1);
            Text_Draw_2_001875C0(o->x38, o->x3C, 1.0f, buf, 0, col.w);
            break;
        case 2003:
            sprintf(buf, D_001FCD10, e->x4, e->x0);
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 2004:
            sprintf(buf, D_001FCD20, e->x6, e->x2);
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 2005:
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, D_001FCD30, 0, col.w);
            break;
        case 2006:
            sprintf(buf, D_001FCD40, e->x8, e->xA, e->xB);
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 2007:
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, DbMap_GetLocationName_1_00195AA0(f / 10), 0, col.w);
            break;
        }
    } else {
        switch (id) {
        case 2001:
            break;
        case 2002:
            if (b.arr[n] == 2 || b.a[3] == 2 || s0 != 0) {
                col.w = 0x80404080;
                col.c.a = o->x2F * 2;
                Text_Draw_2_001875C0(o->x38, o->x3C, 1.0f, Msg_GetText_2_00195B10(0x69), 0, col.w);
            } else {
                Text_Draw_2_001875C0(o->x38, o->x3C, 1.0f, D_001FCD58, 0, col.w);
            }
            break;
        case 2005:
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, D_001FCD30, 0, col.w);
            break;
        case 2003:
        case 2004:
        case 2006:
        case 2007:
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, D_001FCD60, 0, col.w);
            break;
        }
    }
}
