#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F;
typedef struct { u8 pad[6]; u8 lv; u8 pad7[0x89]; } E;
typedef struct { u8 pad[2]; u8 n; u8 p3[2]; u8 kind; } K;
void MenuProc_Run_1_0018B320(s32 *);
void MenuProc_Set_1_0018B150(f32, s32 *, s32, s32, void (*)(), s32);
void Notify_DrawItemGold_0_0019FA00();
void ShopProc_BackB_0_001A13F0();
void Snd_PlaySe_3_00131600(s32, s32);
E *Item_GetTable_1_001AFC90(void);
K *Inventory_GetSlot_1_001A97D0(s16);
K *Inventory_GetEntry_1_001CC3F0(s16);
s16 PlayerData_GetGold_0_001CBA30(void);
extern s32 D_004A32E0[];
extern s32 D_004A32E4[];
extern s32 D_004A32E8[];
extern void (*D_004A32EC[])();
extern s32 D_004A32F0[];
extern s16 D_004A3310[];
extern s16 D_004A3312[];
extern s32 D_004A3318[];
extern s32 D_004A331C[];
extern s32 D_004A3328[];
extern F D_004A332C[];

void Shop_Heal_0_001A1000(s8 *a0) {
    s32 m;
    s32 id;
    E *t;
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
