#include "common.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB[3];
    u8 xE;
} O;
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
s32 SaveSys_IsCardReady_0_001E6110(void);
void Snd_PlaySe_3_00131600(s32, u8);
void LoadMenu_Back_0_00193780();
void LoadMenu_Load_0_00193070();
extern s32 D_004A10F0[];
extern s32 D_004A1124[];
extern s32 D_004A1128[];
extern s32 D_004A1130[];
extern Flags8 D_004A1140[];

void LoadMenu_CheckCard_1_00192E90(O *o, s32 a1) {
    s32 k;

    k = 0;
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        if (a1 == 0) {
            k = 0x79;
        } else if (a1 == 1) {
            k = 0x7B;
        }
        MenuProc_Set_1_0018B150(D_004A10F0, k, 2, LoadMenu_Back_0_00193780, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A10F0);
        o->xA = 1;
        D_004A1124[0] = 0;
        D_004A1130[0] = 0;
        D_004A1140[0].f.b0 = 0;
    }
}
