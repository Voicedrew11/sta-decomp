#include "actor.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 xB;
    u8 padC[2];
    u8 xE;
} Obj193E80;
typedef struct {
    Flags8 f;
    u8 pad[3];
} Ent193E80;
typedef struct {
    s32 idx;
    u8 pad4[0x14];
    Ent193E80 e[1];
} Menu193E80;
u8 MenuStack_Pop_1_00189EA0(void);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
void SaveSys_SetPort_1_001E82A0(s32);
void Snd_PlaySe_3_00131600(s32, u8);
void LoadMenu_LoadB_0_001945B0();
void LoadMenu_WaitCard_0_00194440();
void LoadMenu_RetryB_0_00194D20();
void LoadMenu_BackB_0_00194B90();
extern s32 D_00202140;
extern s32 D_004A1150[];
extern Menu193E80 D_004A1180[];
extern s32 D_004A1188[];
extern f32 D_004A118C[];
extern f32 D_004A1190[];

void LoadMenu_SelectDevice_0_00193E80(Obj193E80 *o) {
    s32 fl;

    fl = o->x4;
    if (fl & 0x80) {
        D_004A1180[0].idx--;
        if (D_004A1180[0].idx < 0) {
            D_004A1180[0].idx = 1;
        }
        D_004A1190[0] = 0.0f;
        Snd_PlaySe_3_00131600(0x66, o->xE);
    } else if (fl & 0x20) {
        D_004A1180[0].idx++;
        if (D_004A1180[0].idx > 1) {
            D_004A1180[0].idx = 0;
        }
        D_004A1190[0] = 0.0f;
        Snd_PlaySe_3_00131600(0x66, o->xE);
    } else if (fl & 0x2000) {
        if (D_004A1180[0].e[D_004A1180[0].idx].f.f.b0) {
            SaveSys_SetPort_1_001E82A0(D_004A1180[0].idx);
            if (D_004A1180[0].e[D_004A1180[0].idx].f.f.b1) {
                MenuProc_Set_1_0018B150(D_004A1150, 0x7A, 0, LoadMenu_LoadB_0_001945B0, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A1150);
                D_004A1188[0] = 0;
                o->xA = 1;
                o->xB = 1;
            } else {
                MenuProc_Set_1_0018B150(D_004A1150, 0x76, 3, LoadMenu_WaitCard_0_00194440, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A1150);
                D_004A1188[0] = 0;
                o->xA = 1;
                o->xB = 1;
            }
        } else {
            MenuProc_Set_1_0018B150(D_004A1150, D_004A1180[0].idx + 0x81, 2, LoadMenu_RetryB_0_00194D20, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A1150);
            o->xA = 1;
            o->xB = 1;
        }
        Snd_PlaySe_3_00131600(0x67, o->xE);
    } else if (fl & 0x4000) {
        if (D_00202140 != 0) {
            MenuProc_Set_1_0018B150(D_004A1150, 0x2D, 3, LoadMenu_BackB_0_00194B90, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A1150);
            o->xA = 1;
            o->xB = 1;
            Snd_PlaySe_3_00131600(0x67, o->xE);
        } else {
            Snd_PlaySe_3_00131600(0x69, o->xE);
            o->x8 = MenuStack_Pop_1_00189EA0();
            o->x4 = 0;
            o->x0 = 0x1A;
            D_004A118C[0] = 128.0f;
        }
    }
    o->x4 = 0;
}
