#include "common.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
} O;
typedef struct { s16 v[8]; } P;
s8 *Save_GetSlotInfo_0_00188FF0(s32);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 SaveSys_StartLoad_0_001E62A0(s32, void *, s32);
s32 SaveSys_GetPort_1_001E8290(void);
void SaveSys_Update_2_001E8500(void);
void LoadMenu_CheckCard_1_00192E90(O *, s32);
void Save_WriteOptions_1_001A8CA0(void);
void Save_ParseGame_1_001A9080(void);
void *Save_GetData_1_001A9400(void);
void Option_Store_1_001A94E0(void *);
P *PlayerData_Get_2_001C9BA0(void);
void Menu_SetCursor_1_0018B840(s32, s32);
void LoadMenu_Back_0_00193780();
void LoadMenu_Retry_0_001937E0();
extern u8 D_004A0900[][0xF0];
extern u8 D_004A0950[];
extern s32 D_004A10F0[];
extern s32 D_004A1120[];
extern s32 D_004A1124[];
extern s32 D_004A1128[];
extern s32 D_004A1130[];
extern Flags8 D_004A1140[];
static inline void start(O *o, s32 s) {
    if (s == 1) {
        MenuProc_Set_1_0018B150(D_004A10F0, 0x7B, 2, LoadMenu_Back_0_00193780, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A10F0);
        o->xA = 1;
        D_004A1124[0] = 0;
        D_004A1130[0] = 0;
        D_004A1140[0].f.b0 = 0;
    }
}
static inline void ok(O *o) {
    MenuProc_Set_1_0018B150(D_004A10F0, 0x6F, 2, LoadMenu_Retry_0_001937E0, 0, 1.0f);
    MenuProc_Run_1_0018B320(D_004A10F0);
    o->xA = 1;
}

void LoadMenu_Load_0_00193070(O *o) {
    s32 n;
    s32 s;
    P *src;
    P *dst;
    s32 off;
    u8 *p;

    n = SaveSys_GetPort_1_001E8290();
    LoadMenu_CheckCard_1_00192E90(o, 1);
    D_004A1140[0].f.b1 = 0;
    switch (D_004A1128[0]) {
    case 0:
        if (SaveSys_StartRead_0_001E5F30(0, 0) == 0) D_004A1128[0]++;
        break;
    case 1:
        SaveSys_GetResult_0_001E6080(&s);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 2:
        Save_GetSlotInfo_0_00188FF0(0)[D_004A1120[0]] = 1;
        if (SaveSys_StartLoad_0_001E62A0(7, Save_GetSlotInfo_0_00188FF0(0), 8) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 3:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 4:
        Save_WriteOptions_1_001A8CA0();
        Save_ParseGame_1_001A9080();
        if (SaveSys_StartLoad_0_001E62A0(D_004A1120[0], Save_GetData_1_001A9400(), 0x7C20) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 5:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 6:
        off = n * 0xF0;
        p = (u8 *)D_004A0900 + off;
        Option_Store_1_001A94E0(p + 0x20);
        src = PlayerData_Get_2_001C9BA0();
        dst = (P *)(D_004A1120[0] * 16 + ((u8 *)D_004A0950 + off));
        *dst = *src;
        if (SaveSys_StartLoad_0_001E62A0(-1, p, 0xF0) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 7:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 8:
        Save_GetSlotInfo_0_00188FF0(0)[D_004A1120[0]] = 0;
        if (SaveSys_StartLoad_0_001E62A0(7, Save_GetSlotInfo_0_00188FF0(0), 8) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 9:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) {
            MenuProc_Set_1_0018B150(D_004A10F0, 0x70, 2, LoadMenu_Retry_0_001937E0, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A10F0);
            o->xA = 1;
            Menu_SetCursor_1_0018B840(SaveSys_GetPort_1_001E8290(), D_004A1120[0]);
        }
        start(o, s);
        break;
    }
}
