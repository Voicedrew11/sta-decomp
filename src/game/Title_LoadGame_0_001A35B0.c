#include "common.h"
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; } P;
extern s32 D_00202250;
extern s32 D_00202258;
extern s32 D_00202254;
extern f32 D_00201D9C;
extern s32 D_0020223C;
extern s32 D_00202260;
extern s32 D_0020225C;
extern s32 D_0020224C;
extern s32 D_00202248;
extern s32 D_00202244;
extern s32 D_00202240;
extern s32 D_00201D94;
extern f32 D_00201D98;
extern s32 D_004A4360[];
extern s32 D_004A4364[];
extern void *D_004A4368[];
extern s32 D_004A436C[];
extern f32 D_004A4370[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_004A4374[0x7] __attribute__((aligned(4)));
extern f32 D_004A4378[];
s32 Movie_Stop_0_00180110(void);
s32 Movie_Update_0_001801F0(s32);
void SaveSys_SetPort_1_001E82A0(s32);
s32 SaveSys_GetCardKind_0_001E60C0(s32);
s32 SaveSys_GetSlotState_0_001E6040(s32);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 Menu_GetStateBuf_0_00189000(s32);
void Save_ParseOptions_1_001A8B90(s32);
void Menu_SaveOptions_1_0018E460(void);
void MenuProc_Run_1_0018B320(s32 *);
void TitleProc_Back_0_001A3B60(void);
static inline void go(void) {
    D_0020223C = 0x1E;
    if (D_0020224C) {
        SaveSys_SetPort_1_001E82A0(1);
        return;
    }
    if (D_00202248) {
        SaveSys_SetPort_1_001E82A0(0);
        return;
    }
    D_0020223C = 0x63;
}

void Title_LoadGame_0_001A35B0(P *p) {
    s32 r;
    s32 v;

    if (p->x0 == 0x19) {
        D_00202250 = 0;
        D_00202258 = 5;
        D_00202254 = 0;
        D_00201D9C = 30.0f;
        D_0020223C = 0;
        D_00202260 = 0;
        D_0020225C = 0;
    }
    switch (D_0020223C) {
    case 0:
        D_0020223C = 1;
        D_0020224C = 0;
        D_00201D9C = 30.0f;
        D_00202248 = 0;
        D_00202244 = 0;
        D_00202240 = 0;
        break;
    case 1:
        v = Movie_Stop_0_00180110();
        if (D_00201D9C < 0.0f) {
            if (v == 0) {
                D_0020223C = 10;
            } else {
                D_0020223C = 2;
            }
        } else {
            D_00201D9C -= 1.0f;
        }
        break;
    case 2:
        if ((Movie_Stop_0_00180110() & 0xF) == 3) {
            D_0020223C = 3;
        } else {
            D_0020223C = 4;
        }
        break;
    case 3:
        v = Movie_Update_0_001801F0(0);
        if (v > 0) {
            D_0020223C = 4;
            D_00202240 = (v & 2) != 0;
            D_00202248 = (v & 4) != 0;
        }
        break;
    case 4:
        if ((Movie_Stop_0_00180110() & 0xF0) == 0x30) {
            D_0020223C = 5;
        } else {
            D_0020223C = 6;
        }
        break;
    case 5:
        v = Movie_Update_0_001801F0(1);
        if (v > 0) {
            D_0020223C = 6;
            D_00202244 = (v & 2) != 0;
            D_0020224C = (v & 4) != 0;
        }
        break;
    case 6:
        v = Movie_Stop_0_00180110();
        if ((v & 0xF) == 1 || (v & 0xF0) == 0x10) {
            go();
        } else if (D_00202240 || D_00202244) {
            go();
        } else if ((!SaveSys_GetCardKind_0_001E60C0(0) && SaveSys_GetSlotState_0_001E6040(0) > 0x6E) || (!SaveSys_GetCardKind_0_001E60C0(1) && SaveSys_GetSlotState_0_001E6040(1) > 0x6E)) {
            go();
        } else {
            D_00201D94 = 0x7D;
            D_00201D98 = -20.0f;
            if (!SaveSys_GetCardKind_0_001E60C0(1) && SaveSys_GetSlotState_0_001E6040(1) < 0x6F) {
                D_00201D94 = 0x84;
            }
            if (!SaveSys_GetCardKind_0_001E60C0(0) && SaveSys_GetSlotState_0_001E6040(0) < 0x6F) {
                if (D_00201D94 == 0x84) {
                    D_00201D94 = 0x87;
                    D_00201D98 = -35.0f;
                } else {
                    D_00201D94 = 0x83;
                }
            }
            D_0020223C = 0x14;
        }
        break;
    case 10:
        D_004A436C[0] = 0;
        D_004A4374[0] = 0;
        D_004A4360[0] = 0x7D;
        D_004A4364[0] = 4;
        D_004A4368[0] = TitleProc_Back_0_001A3B60;
        D_004A4370[0] = 0.7916667f;
        D_004A4378[0] = -20.0f;
        MenuProc_Run_1_0018B320(D_004A4360);
        p->xB = 1;
        p->xA = 1;
        D_00202258 = 5;
        break;
    case 0x14:
        D_004A436C[0] = 0;
        D_004A4374[0] = 0;
        D_004A4364[0] = 4;
        D_004A4360[0] = D_00201D94;
        D_004A4368[0] = TitleProc_Back_0_001A3B60;
        D_004A4370[0] = 0.8f;
        D_004A4378[0] = D_00201D98;
        MenuProc_Run_1_0018B320(D_004A4360);
        p->xB = 1;
        p->xA = 1;
        D_00202258 = 5;
        break;
    case 0x1E:
        D_0020223C = 0x63;
        break;
    case 0x1F:
        SaveSys_GetResult_0_001E6080(&r);
        if (r == 0) {
            Save_ParseOptions_1_001A8B90(Menu_GetStateBuf_0_00189000(1));
            D_0020223C = 0x63;
        }
        Menu_SaveOptions_1_0018E460();
        if (r == 1) {
            D_0020223C = 0x63;
        }
        break;
    default:
    case 0x63:
        p->x8 = 3;
        p->x4 = 0;
        p->x0 = 0x1F;
        break;
    }
}
