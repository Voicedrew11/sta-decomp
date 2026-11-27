#include "actor.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB[3];
    u8 xE;
} Obj18C8B0;
typedef struct {
    u8 pad0[0x10];
    s32 arr[8];
} Buf18C590;
s8 *Save_GetSlotInfo_0_00188FF0(s32);
u8 MenuStack_Pop_1_00189EA0(void);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
void SaveSys_GetSlotCount_0_001E5E80(Buf18C590 *);
s32 SaveSys_IsCardReady_0_001E6110();
s32 SaveSys_GetPort_1_001E8290();
void Snd_PlaySe_3_00131600(s32, u8);
void SaveMenu_ConfirmOverwrite_0_0018C8B0();
void MenuProc_BackOnCancel_0_0018D000();
extern u8 D_004A095F[][0xF0];
extern s32 D_004A0FC0[];
extern s32 D_004A0FF0[];
extern s32 D_004A0FF4[];
extern s32 D_004A0FFC[];
extern s32 D_004A1000[];
extern f32 D_004A100C[];
extern Flags8 D_004A1010[];

void SaveMenu_SelectSlot_0_0018C590(Obj18C8B0 *o) {
    Buf18C590 buf = {0};
    s32 i;
    s32 fl;

    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    D_004A1010[0].f.b1 = 1;
    fl = o->x4;
    if (fl & 0x10) {
        D_004A0FF0[0]--;
        Snd_PlaySe_3_00131600(0x66, o->xE);
        if (D_004A0FF0[0] < 0) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 1;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x40) {
        D_004A0FF0[0]++;
        Snd_PlaySe_3_00131600(0x66, o->xE);
        if (D_004A0FF0[0] > 6) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 3;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x2000) {
        SaveSys_GetSlotCount_0_001E5E80(&buf);
        i = D_004A0FF0[0];
        if (buf.arr[i] != 1 || D_004A095F[SaveSys_GetPort_1_001E8290()][i * 0x10] == 0 || Save_GetSlotInfo_0_00188FF0(0)[D_004A0FF0[0]] != 0) {
            Snd_PlaySe_3_00131600(0x6B, o->xE);
        } else {
            Snd_PlaySe_3_00131600(0x67, o->xE);
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x71, 3, SaveMenu_ConfirmOverwrite_0_0018C8B0, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x4000) {
        o->x8 = MenuStack_Pop_1_00189EA0();
        o->x4 = 0;
        o->x0 = 0x1A;
        Snd_PlaySe_3_00131600(0x69, o->xE);
    }
}
