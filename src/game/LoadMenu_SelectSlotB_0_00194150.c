#include "m2c.h"
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; u8 xC; u8 xD; u8 xE; } Obj;
void memset(s32, s32, s32);
s32 Save_GetSlotInfo_0_00188FF0(s32);
void MenuStack_Push_1_00189ED0(s32);
void MenuProc_Set_1_0018B150(f32, s32 *, s32, s32, void (*)(), s32);
void MenuProc_Run_1_0018B320(s32 *);
void LoadMenu_UpdateCardFlags_1_00194D90(s32, s32 *);
void Save_BuildOptions_1_001AB0A0(s8 *);
s32 SaveSys_IsCardReady_0_001E6110(void);
s32 SaveSys_GetPort_1_001E8290(void);
void Snd_PlaySe_3_00131600(s32, s32);
void LoadMenu_RetryB_0_00194D20();
extern s8 D_004A0900[];
extern s32 D_004A1150[];
extern s32 D_004A1184[];
extern s32 D_004A1188[];
extern f32 D_004A118C[];
extern s32 D_004A1198[];
extern s32 D_004A119C[];

void LoadMenu_SelectSlotB_0_00194150(Obj *o) {
    s32 idx;
    s32 st;
    s32 r;

    idx = SaveSys_GetPort_1_001E8290();
    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    st = SaveSys_IsCardReady_0_001E6110();
    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    if (st == 1) {
        MenuProc_Set_1_0018B150(1.0f, D_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
        MenuProc_Run_1_0018B320(D_004A1150);
        r = 1;
        o->xA = 1;
        o->xB = 1;
        D_004A1184[0] = 0;
        D_004A1188[0] = 0;
    } else {
        r = 0;
    }
    if (r == 0 && (o->x4 & 0x2000)) {
        Save_BuildOptions_1_001AB0A0(D_004A0900 + idx * 0xF0);
        memset(Save_GetSlotInfo_0_00188FF0(0), 0, 8);
        D_004A1184[0] = 0;
        D_004A118C[0] = 128.0f;
        D_004A1188[0] = 0;
        MenuStack_Push_1_00189ED0(0xA);
        o->x8 = 0xC;
        o->x4 = 0;
        o->x0 = 0x1A;
        o->xA = 2;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
}
