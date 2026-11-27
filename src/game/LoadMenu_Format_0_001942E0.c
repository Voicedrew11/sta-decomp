#include "m2c.h"
void MenuProc_Set_1_0018B150(f32, s32 *, s32, s32, void (*)(s8 *), s32);
void MenuProc_Run_1_0018B320(s32 *);
void LoadMenu_UpdateCardFlags_1_00194D90(s32, s32 *);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 SaveSys_StartFormat_0_001E6410(s32);
void LoadMenu_SelectSlotB_0_00194150(s8 *);
void LoadMenu_RetryB_0_00194D20(s8 *);
extern s32 D_004A1150[];
extern s32 D_004A1184[];
extern s32 D_004A1188[];
extern s32 D_004A1198[];
extern s32 D_004A119C[];

void LoadMenu_Format_0_001942E0(s8 *arg0) {
    s32 r = 0;

    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    switch (D_004A1188[0]) {
    case 0:
        D_004A1188[0]++;
        break;
    case 1:
        if (SaveSys_StartFormat_0_001E6410(D_004A1188[0]) != -1) {
            D_004A1188[0]++;
        }
        break;
    case 2:
        SaveSys_GetResult_0_001E6080(&r);
        if (r == 0) {
            MenuProc_Set_1_0018B150(1.0f, D_004A1150, 0x74, 2, LoadMenu_SelectSlotB_0_00194150, 0);
            MenuProc_Run_1_0018B320(D_004A1150);
            D_004A1184[0] = 0;
            D_004A1188[0] = 0;
        }
        if (r == 1) {
            MenuProc_Set_1_0018B150(1.0f, D_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
            MenuProc_Run_1_0018B320(D_004A1150);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
            D_004A1184[0] = 0;
            D_004A1188[0] = 0;
        }
        break;
    }
}
