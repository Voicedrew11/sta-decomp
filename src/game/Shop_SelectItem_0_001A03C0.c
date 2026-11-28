#include "m2c.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x31]; u8 x3D; u8 pad3E[0x52]; } E_Shop_SelectItem_0_001A03C0;
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; u8 xC; u8 xD; u8 xE; } Ev;
typedef struct { u8 p:2; u8 v:1; u8 b3:1; u8 b4:1; } B;
typedef struct { u8 pad[4]; s16 x4; } R;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F;
typedef struct { u8 pad[4]; u8 max; } K_Shop_BuyQuantity_0_001A0850;
typedef struct { u8 pad[2]; u8 n; } C;
typedef struct { u8 pad[4]; u8 max; } K_Shop_SellQuantity_0_001A0B00;
typedef struct { u8 pad[7]; u8 lv; u8 pad8[0x88]; } E_Shop_Repair_0_001A0DB0;
typedef struct { u8 pad[5]; u8 kind; } K_Shop_Repair_0_001A0DB0;
typedef struct { u8 pad[6]; u8 lv; u8 pad7[0x89]; } E_Shop_Heal_0_001A1000;
typedef struct { u8 pad[2]; u8 n; u8 p3[2]; u8 kind; } K_Shop_Heal_0_001A1000;
extern u16 D_004A3310[];
extern s32 D_004A32E0[];
extern s32 D_004A32E4[];
extern s32 D_004A32E8[];
extern void *D_004A32EC[];
extern s32 D_004A32F0[];
extern s32 D_004A3318[];
extern s32 D_004A331C[];
extern s32 D_004A3328[];
extern B D_004A332C[];
extern s16 D_004A3312[];
void Shop_SelectItem_0_001A03C0(Ev *arg0);
void Shop_Confirm_0_001A06B0(s8 *a0);
void Shop_BuyQuantity_0_001A0850(s8 *a0);
void Shop_SellQuantity_0_001A0B00(s8 *a0);
void Shop_Repair_0_001A0DB0(s8 *a0);
void Shop_Heal_0_001A1000(s8 *a0);
E_Shop_SelectItem_0_001A03C0* Item_GetTable_1_001AFC90(void);
u8* Inventory_GetEntry_1_001CC3F0(s16);
R* PlayerData_Get_2_001C9BA0(void);
void MenuProc_Run_1_0018B320(s32 *);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void *, s32, f32);
void Snd_PlaySe_3_00131600(s32, u8);
void Notify_DrawItemGet_0_0019F050(void);
void ShopProc_BackA_0_001A1380(void);
void Notify_DrawItemName_0_0019F310();
void Notify_DrawItemCount_0_0019F410();
void ShopProc_BackB_0_001A13F0();
K_Shop_BuyQuantity_0_001A0850* Inventory_GetSlot_1_001A97D0(s16);
void Notify_DrawItemCountB_0_0019F690();
void Notify_DrawGold_0_0019F890();
s16 PlayerData_GetGold_0_001CBA30(void);
void Notify_DrawItemGold_0_0019FA00();

/* Shop_SelectItem_0_001A03C0 */
void Shop_SelectItem_0_001A03C0(Ev *arg0) {
    s32 id;
    s16 v;
    E_Shop_SelectItem_0_001A03C0 *e;
    u8 *q;
    s16 r;

    if (D_004A332C[0].b4) {
        D_004A32E0[0] = 0;
        D_004A32E4[0] = 3;
        D_004A32EC[0] = Notify_DrawItemGet_0_0019F050;
        D_004A32F0[0] = 0x3F800000;
        D_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(D_004A32E0);
        arg0->xA = 1;
        D_004A332C[0].b4 = 0;
        D_004A3328[0] = 0x41200000;
    } else if (arg0->x4 & 0x2000) {
        id = D_004A3310[0];
        v = 0;
        e = Item_GetTable_1_001AFC90();
        q = Inventory_GetEntry_1_001CC3F0(id);
        if (id == -1) {
            r = -1;
        } else {
            switch (e[id].xA) {
            case 1:
                v = e[id].x3D;
                break;
            case 2:
                v = e[id].x3D;
                break;
            }
            if (q[0] <= 0) {
                r = (100 - q[0]) * (v / 5) * 2;
            } else {
                r = (100 - q[0]) * (v / 5);
            }
        }
        if (PlayerData_Get_2_001C9BA0()->x4 > r) {
            D_004A3318[0] = D_004A331C[0];
            D_004A332C[0].v = 1;
            Snd_PlaySe_3_00131600(0x67, arg0->xE);
        } else {
            MenuProc_Set_1_0018B150(D_004A32E0, 0xA4, 2, ShopProc_BackA_0_001A1380, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A32E0);
            arg0->xA = 1;
            arg0->xB = 1;
            Snd_PlaySe_3_00131600(0x6B, arg0->xE);
        }
    } else if (arg0->x4 & 0x4000) {
        D_004A332C[0].v = 1;
        Snd_PlaySe_3_00131600(0x68, arg0->xE);
    }
}

/* Shop_Confirm_0_001A06B0 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Shop_Confirm_0_001A06B0
s16 *PlayerData_Get_2_001C9BA0__as_Shop_Confirm_0_001A06B0(void);
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Shop_Confirm_0_001A06B0
void Snd_PlaySe_3_00131600__as_Shop_Confirm_0_001A06B0(s32, s32);
#define D_004A32EC D_004A32EC__as_Shop_Confirm_0_001A06B0
extern void (*D_004A32EC__as_Shop_Confirm_0_001A06B0[])();
#define D_004A332C D_004A332C__as_Shop_Confirm_0_001A06B0
extern F D_004A332C__as_Shop_Confirm_0_001A06B0[];

void Shop_Confirm_0_001A06B0(s8 *a0) {
    if (D_004A332C[0].b4) {
        D_004A32E0[0] = 0;
        D_004A32E4[0] = 3;
        D_004A32EC[0] = Notify_DrawItemName_0_0019F310;
        D_004A32F0[0] = 0x3F800000;
        D_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(D_004A32E0);
        a0[0xA] = 1;
        D_004A332C[0].b4 = 0;
        D_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        if (PlayerData_Get_2_001C9BA0()[2] == PlayerData_Get_2_001C9BA0()[0] && PlayerData_Get_2_001C9BA0()[3] == PlayerData_Get_2_001C9BA0()[1]) {
            Snd_PlaySe_3_00131600(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        D_004A3318[0] = D_004A331C[0];
        D_004A332C[0].b2 = 1;
        Snd_PlaySe_3_00131600(0x67, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        D_004A332C[0].b2 = 1;
        Snd_PlaySe_3_00131600(0x68, *(u8 *)(a0 + 0xE));
    }
}
#undef PlayerData_Get_2_001C9BA0
#undef Snd_PlaySe_3_00131600
#undef D_004A32EC
#undef D_004A332C

/* Shop_BuyQuantity_0_001A0850 */
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_Shop_BuyQuantity_0_001A0850
void MenuProc_Set_1_0018B150__as_Shop_BuyQuantity_0_001A0850(f32, s32 *, s32, s32, void (*)(), s32);
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850
void Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850(s32, s32);
#define Inventory_GetEntry_1_001CC3F0 Inventory_GetEntry_1_001CC3F0__as_Shop_BuyQuantity_0_001A0850
C *Inventory_GetEntry_1_001CC3F0__as_Shop_BuyQuantity_0_001A0850(s16);
#define D_004A32EC D_004A32EC__as_Shop_BuyQuantity_0_001A0850
extern void (*D_004A32EC__as_Shop_BuyQuantity_0_001A0850[])();
#define D_004A3310 D_004A3310__as_Shop_BuyQuantity_0_001A0850
extern s16 D_004A3310__as_Shop_BuyQuantity_0_001A0850[];
#define D_004A332C D_004A332C__as_Shop_BuyQuantity_0_001A0850
extern F D_004A332C__as_Shop_BuyQuantity_0_001A0850[];

void Shop_BuyQuantity_0_001A0850(s8 *a0) {
    s16 n; s32 m; u8 c;

    if (D_004A332C[0].b4) {
        D_004A32E0[0] = 0;
        D_004A32E4[0] = 3;
        D_004A32EC[0] = Notify_DrawItemCount_0_0019F410;
        D_004A32F0[0] = 0x3F800000;
        D_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(D_004A32E0);
        a0[0xA] = 1;
        D_004A332C[0].b4 = 0;
        D_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x80) {
        D_004A3312[0]--;
        if (D_004A3312[0] <= 0) {
            D_004A3312[0] = 1;
            return;
        }
        Snd_PlaySe_3_00131600(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x20) {
        D_004A3312[0]++;
        m = D_004A3312[0];
        if (Inventory_GetSlot_1_001A97D0(D_004A3310[0])->max < m) {
            D_004A3312[0] = Inventory_GetSlot_1_001A97D0(D_004A3310[0])->max;
            return;
        }
        Snd_PlaySe_3_00131600(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        n = D_004A3312[0];
        c = Inventory_GetEntry_1_001CC3F0(D_004A3310[0])->n;
        if ((s16)n + c > 99) {
            MenuProc_Set_1_0018B150(1.0f, D_004A32E0, 0xA2, 2, ShopProc_BackB_0_001A13F0, 0);
            MenuProc_Run_1_0018B320(D_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            Snd_PlaySe_3_00131600(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        if (n) {
            D_004A3318[0] = D_004A331C[0];
            D_004A332C[0].b2 = 1;
            Snd_PlaySe_3_00131600(0x67, *(u8 *)(a0 + 0xE));
            return;
        }
        Snd_PlaySe_3_00131600(0x68, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        D_004A332C[0].b2 = 1;
        Snd_PlaySe_3_00131600(0x68, *(u8 *)(a0 + 0xE));
    }
}
#undef MenuProc_Set_1_0018B150
#undef Snd_PlaySe_3_00131600
#undef Inventory_GetEntry_1_001CC3F0
#undef D_004A32EC
#undef D_004A3310
#undef D_004A332C

/* Shop_SellQuantity_0_001A0B00 */
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_Shop_SellQuantity_0_001A0B00
void MenuProc_Set_1_0018B150__as_Shop_SellQuantity_0_001A0B00(f32, s32 *, s32, s32, void (*)(), s32);
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00
void Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00(s32, s32);
#define Inventory_GetSlot_1_001A97D0 Inventory_GetSlot_1_001A97D0__as_Shop_SellQuantity_0_001A0B00
K_Shop_SellQuantity_0_001A0B00 *Inventory_GetSlot_1_001A97D0__as_Shop_SellQuantity_0_001A0B00(s16);
#define Inventory_GetEntry_1_001CC3F0 Inventory_GetEntry_1_001CC3F0__as_Shop_SellQuantity_0_001A0B00
C *Inventory_GetEntry_1_001CC3F0__as_Shop_SellQuantity_0_001A0B00(s16);
#define D_004A32EC D_004A32EC__as_Shop_SellQuantity_0_001A0B00
extern void (*D_004A32EC__as_Shop_SellQuantity_0_001A0B00[])();
#define D_004A3310 D_004A3310__as_Shop_SellQuantity_0_001A0B00
extern s16 D_004A3310__as_Shop_SellQuantity_0_001A0B00[];
#define D_004A332C D_004A332C__as_Shop_SellQuantity_0_001A0B00
extern F D_004A332C__as_Shop_SellQuantity_0_001A0B00[];

void Shop_SellQuantity_0_001A0B00(s8 *a0) {
    s16 n; s32 m; u8 c;

    if (D_004A332C[0].b4) {
        D_004A32E0[0] = 0;
        D_004A32E4[0] = 3;
        D_004A32EC[0] = Notify_DrawItemCountB_0_0019F690;
        D_004A32F0[0] = 0x3F800000;
        D_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(D_004A32E0);
        a0[0xA] = 1;
        D_004A332C[0].b4 = 0;
        D_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x80) {
        D_004A3312[0]--;
        if (D_004A3312[0] <= 0) {
            D_004A3312[0] = 1;
            return;
        }
        Snd_PlaySe_3_00131600(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x20) {
        D_004A3312[0]++;
        m = D_004A3312[0];
        if (Inventory_GetEntry_1_001CC3F0(D_004A3310[0])->n < m) {
            D_004A3312[0] = Inventory_GetEntry_1_001CC3F0(D_004A3310[0])->n;
            return;
        }
        Snd_PlaySe_3_00131600(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        n = D_004A3312[0];
        c = Inventory_GetSlot_1_001A97D0(D_004A3310[0])->max;
        if ((s16)n + c > 99) {
            MenuProc_Set_1_0018B150(1.0f, D_004A32E0, 0xA1, 2, ShopProc_BackB_0_001A13F0, 0);
            MenuProc_Run_1_0018B320(D_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            Snd_PlaySe_3_00131600(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        if (n) {
            D_004A3318[0] = D_004A331C[0];
            D_004A332C[0].b2 = 1;
            Snd_PlaySe_3_00131600(0x67, *(u8 *)(a0 + 0xE));
            return;
        }
        Snd_PlaySe_3_00131600(0x68, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        D_004A332C[0].b2 = 1;
        Snd_PlaySe_3_00131600(0x68, *(u8 *)(a0 + 0xE));
    }
}
#undef MenuProc_Set_1_0018B150
#undef Snd_PlaySe_3_00131600
#undef Inventory_GetSlot_1_001A97D0
#undef Inventory_GetEntry_1_001CC3F0
#undef D_004A32EC
#undef D_004A3310
#undef D_004A332C

/* Shop_Repair_0_001A0DB0 */
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_Shop_Repair_0_001A0DB0
void MenuProc_Set_1_0018B150__as_Shop_Repair_0_001A0DB0(f32, s32 *, s32, s32, void (*)(), s32);
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Shop_Repair_0_001A0DB0
void Snd_PlaySe_3_00131600__as_Shop_Repair_0_001A0DB0(s32, s32);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Shop_Repair_0_001A0DB0
E_Shop_Repair_0_001A0DB0 *Item_GetTable_1_001AFC90__as_Shop_Repair_0_001A0DB0(void);
#define Inventory_GetSlot_1_001A97D0 Inventory_GetSlot_1_001A97D0__as_Shop_Repair_0_001A0DB0
K_Shop_Repair_0_001A0DB0 *Inventory_GetSlot_1_001A97D0__as_Shop_Repair_0_001A0DB0(s16);
#define D_004A32EC D_004A32EC__as_Shop_Repair_0_001A0DB0
extern void (*D_004A32EC__as_Shop_Repair_0_001A0DB0[])();
#define D_004A332C D_004A332C__as_Shop_Repair_0_001A0DB0
extern F D_004A332C__as_Shop_Repair_0_001A0DB0[];

void Shop_Repair_0_001A0DB0(s8 *a0) {
    s32 id;
    E_Shop_Repair_0_001A0DB0 *t;
    s16 m;
    s16 r;

    if (D_004A332C[0].b4) {
        D_004A32E0[0] = 0;
        D_004A32E4[0] = 3;
        D_004A32EC[0] = Notify_DrawGold_0_0019F890;
        D_004A32F0[0] = 0x3F800000;
        D_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(D_004A32E0);
        a0[0xA] = 1;
        D_004A332C[0].b4 = 0;
        D_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        id = D_004A3310[0];
        t = Item_GetTable_1_001AFC90();
        if (Inventory_GetSlot_1_001A97D0(id)->kind == 2) {
            m = 5;
        } else if (*Inventory_GetEntry_1_001CC3F0(id) <= 0) {
            m = 1;
        } else {
            m = t[id].lv;
        }
        r = PlayerData_GetGold_0_001CBA30();
        if (r + D_004A3312[0] * m > 99) {
            MenuProc_Set_1_0018B150(1.0f, D_004A32E0, 0xA5, 2, ShopProc_BackB_0_001A13F0, 0);
            MenuProc_Run_1_0018B320(D_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            Snd_PlaySe_3_00131600(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        D_004A3318[0] = D_004A331C[0];
        D_004A332C[0].b2 = 1;
        Snd_PlaySe_3_00131600(0x67, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        D_004A332C[0].b2 = 1;
        Snd_PlaySe_3_00131600(0x68, *(u8 *)(a0 + 0xE));
    }
}
#undef MenuProc_Set_1_0018B150
#undef Snd_PlaySe_3_00131600
#undef Item_GetTable_1_001AFC90
#undef Inventory_GetSlot_1_001A97D0
#undef D_004A32EC
#undef D_004A332C

/* Shop_Heal_0_001A1000 */
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_Shop_Heal_0_001A1000
void MenuProc_Set_1_0018B150__as_Shop_Heal_0_001A1000(f32, s32 *, s32, s32, void (*)(), s32);
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000
void Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000(s32, s32);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Shop_Heal_0_001A1000
E_Shop_Heal_0_001A1000 *Item_GetTable_1_001AFC90__as_Shop_Heal_0_001A1000(void);
#define Inventory_GetSlot_1_001A97D0 Inventory_GetSlot_1_001A97D0__as_Shop_Heal_0_001A1000
K_Shop_Heal_0_001A1000 *Inventory_GetSlot_1_001A97D0__as_Shop_Heal_0_001A1000(s16);
#define Inventory_GetEntry_1_001CC3F0 Inventory_GetEntry_1_001CC3F0__as_Shop_Heal_0_001A1000
K_Shop_Heal_0_001A1000 *Inventory_GetEntry_1_001CC3F0__as_Shop_Heal_0_001A1000(s16);
#define D_004A32EC D_004A32EC__as_Shop_Heal_0_001A1000
extern void (*D_004A32EC__as_Shop_Heal_0_001A1000[])();
#define D_004A3310 D_004A3310__as_Shop_Heal_0_001A1000
extern s16 D_004A3310__as_Shop_Heal_0_001A1000[];
#define D_004A332C D_004A332C__as_Shop_Heal_0_001A1000
extern F D_004A332C__as_Shop_Heal_0_001A1000[];

void Shop_Heal_0_001A1000(s8 *a0) {
    s32 m;
    s32 id;
    E_Shop_Heal_0_001A1000 *t;
    s16 k;
    s16 r;

    if (D_004A332C[0].b4) {
        D_004A32E0[0] = 0;
        D_004A32E4[0] = 3;
        D_004A32EC[0] = Notify_DrawItemGold_0_0019FA00;
        D_004A32F0[0] = 0x3F800000;
        D_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(D_004A32E0);
        a0[0xA] = 1;
        D_004A332C[0].b4 = 0;
        D_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x80) {
        D_004A3312[0]--;
        if (D_004A3312[0] <= 0) {
            D_004A3312[0] = 1;
            return;
        }
        Snd_PlaySe_3_00131600(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x20) {
        D_004A3312[0]++;
        m = D_004A3312[0];
        if (Inventory_GetSlot_1_001A97D0(D_004A3310[0])->n < m) {
            D_004A3312[0] = Inventory_GetSlot_1_001A97D0(D_004A3310[0])->n;
        } else {
            Snd_PlaySe_3_00131600(0x6A, *(u8 *)(a0 + 0xE));
        }
        if (D_004A3312[0] > 99) {
            D_004A3312[0] = 99;
        }
    }
    else if (*(s32 *)(a0 + 4) & 0x2000) {
        if (D_004A3312[0] + Inventory_GetEntry_1_001CC3F0(D_004A3310[0])->n > 99) {
            MenuProc_Set_1_0018B150(1.0f, D_004A32E0, 0xA0, 2, ShopProc_BackB_0_001A13F0, 0);
            MenuProc_Run_1_0018B320(D_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            Snd_PlaySe_3_00131600(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        id = (u16)D_004A3310[0];
        t = Item_GetTable_1_001AFC90();
        if (Inventory_GetSlot_1_001A97D0(id)->kind == 2) {
            k = 5;
        } else {
            k = t[id].lv;
        }
        r = PlayerData_GetGold_0_001CBA30();
        if (!(r < D_004A3312[0] * k)) {
            D_004A3318[0] = D_004A331C[0];
            D_004A332C[0].b2 = 1;
            Snd_PlaySe_3_00131600(0x67, *(u8 *)(a0 + 0xE));
            return;
        }
        MenuProc_Set_1_0018B150(1.0f, D_004A32E0, 0xA3, 2, ShopProc_BackB_0_001A13F0, 0);
        MenuProc_Run_1_0018B320(D_004A32E0);
        a0[0xA] = 1;
        a0[0xB] = 1;
        Snd_PlaySe_3_00131600(0x6B, *(u8 *)(a0 + 0xE));
    }
    else if (*(s32 *)(a0 + 4) & 0x4000) {
        D_004A332C[0].b2 = 1;
        Snd_PlaySe_3_00131600(0x68, *(u8 *)(a0 + 0xE));
    }
}
#undef MenuProc_Set_1_0018B150
#undef Snd_PlaySe_3_00131600
#undef Item_GetTable_1_001AFC90
#undef Inventory_GetSlot_1_001A97D0
#undef Inventory_GetEntry_1_001CC3F0
#undef D_004A32EC
#undef D_004A3310
#undef D_004A332C
