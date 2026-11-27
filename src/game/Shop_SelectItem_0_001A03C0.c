#include "m2c.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x31]; u8 x3D; u8 pad3E[0x52]; } E;
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; u8 xC; u8 xD; u8 xE; } Ev;
typedef struct { u8 p:2; u8 v:1; u8 b3:1; u8 b4:1; } B;
typedef struct { u8 pad[4]; s16 x4; } R;
E *Item_GetTable_1_001AFC90(void);
u8 *Inventory_GetEntry_1_001CC3F0(s16);
R *PlayerData_Get_2_001C9BA0(void);
void MenuProc_Run_1_0018B320(s32 *);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void *, s32, f32);
void Snd_PlaySe_3_00131600(s32, u8);
void Notify_DrawItemGet_0_0019F050(void);
void ShopProc_BackA_0_001A1380(void);
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

void Shop_SelectItem_0_001A03C0(Ev *arg0) {
    s32 id;
    s16 v;
    E *e;
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
