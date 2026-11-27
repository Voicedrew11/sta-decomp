#include "m2c.h"
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; } Obj;
void MenuProc_Set_1_0018B150(f32, s32 *, s32, s32, void (*)(), s32);
void MenuProc_Run_1_0018B320(s32 *);
void LoadMenu_UpdateCardFlags_1_00194D90(s32, s32 *);
s32 SaveSys_IsCardReady_0_001E6110(void);
void LoadMenu_RetryB_0_00194D20();
extern s32 D_004A1150[];
extern s32 D_004A1184[];
extern s32 D_004A1188[];
extern s32 D_004A1198[];
extern s32 D_004A119C[];

void LoadMenu_CheckCardB_0_00194C20(Obj *o) {
    s32 st;
    s32 r;
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
        o->xA = 2;
    }
}
