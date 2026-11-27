#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F;
void MenuProc_Run_1_0018B320(s32 *);
void Notify_DrawItemName_0_0019F310();
s16 *PlayerData_Get_2_001C9BA0(void);
void Snd_PlaySe_3_00131600(s32, s32);
extern s32 D_004A32E0[];
extern s32 D_004A32E4[];
extern s32 D_004A32E8[];
extern void (*D_004A32EC[])();
extern s32 D_004A32F0[];
extern s32 D_004A3318[];
extern s32 D_004A331C[];
extern s32 D_004A3328[];
extern F D_004A332C[];

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
