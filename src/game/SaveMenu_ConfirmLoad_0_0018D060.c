#include "common.h"
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[2]; u8 xA; u8 padB[3]; u8 xE; } O;
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
s32 SaveSys_IsCardReady_0_001E6110();
void Snd_PlaySe_3_00131600(s32, s32);
void MenuProc_BackOnCancel_0_0018D000();
extern s32 D_004A0FC0[];
extern s32 D_004A0FF4[];
extern s32 D_004A1000[];
extern Flags8 D_004A1010[];

void SaveMenu_ConfirmLoad_0_0018D060(O *o) {
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    if (o->x4 & 0x2000) {
        o->xA = 2;
        D_004A1010[0].f.b0 = 1;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
}
