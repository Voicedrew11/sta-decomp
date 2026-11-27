#include "actor.h"
typedef struct {
    u8 pad0[4];
    s32 x4;
    u8 pad8[2];
    u8 xA;
    u8 padB[3];
    u8 xE;
} Obj18C8B0;
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
s32 SaveSys_IsCardReady_0_001E6110();
void Snd_PlaySe_3_00131600(s32, u8);
void SaveMenu_Save_0_0018CA20();
void MenuProc_BackOnCancel_0_0018D000();
extern s32 D_004A0FC0[];
extern s32 D_004A0FF4[];
extern s32 D_004A0FF8[];
extern s32 D_004A1000[];
extern Flags8 D_004A1010[];

void SaveMenu_ConfirmOverwrite_0_0018C8B0(Obj18C8B0 *o) {
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    if (o->x4 & 0x2000) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x6B, 0, SaveMenu_Save_0_0018CA20, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A0FF8[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
    if (o->x4 & 0x4000) {
        D_004A1010[0].f.b0 = 1;
        o->xA = 2;
        Snd_PlaySe_3_00131600(0x68, o->xE);
    }
}
