#include "actor.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[2];
    u8 xA;
    u8 xB;
} Obj1939B0;
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
void LoadMenu_UpdateCardFlags_1_00194D90(s32, s32 *);
s32 SaveSys_GetPort_1_001E8290(void);
void LoadMenu_SelectDevice_0_00193E80(Obj1939B0 *);
void LoadMenu_RetryB_0_00194D20();
extern s32 D_00202140;
extern s32 D_004A1150[];
extern s32 D_004A1180[];
extern s32 D_004A1184[];
extern s32 D_004A118C[];
extern f32 D_004A1190[];
extern Flags8 D_004A1194[];
extern s32 D_004A1198[];
extern s32 D_004A119C[];

void LoadMenu_Open_0_001939B0(Obj1939B0 *o) {
    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    switch (o->x0) {
    case 0x19:
        D_004A1190[0] = 0.0f;
        D_004A118C[0] = 0;
        D_004A1184[0] = 0;
        D_004A1180[0] = SaveSys_GetPort_1_001E8290();
        if (D_00202140 != 0 && D_004A1194[0].f.b1) {
            MenuProc_Set_1_0018B150(D_004A1150, 0x2E, 2, LoadMenu_RetryB_0_00194D20, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A1150);
            o->xA = 1;
            o->xB = 1;
            D_004A1194[0].f.b1 = 0;
        }
        break;
    case 0x16:
        LoadMenu_SelectDevice_0_00193E80(o);
        D_004A1190[0] += 0.1f;
        o->x4 = 0;
        break;
    }
}
