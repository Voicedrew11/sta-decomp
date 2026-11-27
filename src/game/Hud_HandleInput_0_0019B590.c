#include "m2c.h"
typedef struct { s32 state; s32 x4; u8 x8; u8 x9; u8 pad[4]; u8 xE; u8 xF; } P;
s8 *PlayerData_Get_2_001C9BA0(void);
void SndEmit_SetEnabled_0_0012F6E0(s32);
void SndCh_ResumePaused_1_0012C260(void);
void Ui_SetScrollSpeed_0_00180F50(f32);
void SndEmit_StopAllA_1_0012F640(void);
void SndCh_PauseAll_1_0012C2C0(void);
void SndCh_StopAllUnlooped_1_0012C210(void);
void Snd_PlaySe_3_00131600(s32, u8);
void LoadMenu_SetFromTitle_0_00193850(s32);
void MenuStack_Push_1_00189ED0(s32);
extern s32 D_002021C0;
extern s32 D_002021D8;
extern s32 D_002021DC;
extern s32 D_004A3320[];

void Hud_HandleInput_0_0019B590(P *p) {
    s8 *b;

    b = PlayerData_Get_2_001C9BA0();
    if (p->state == 0x19) {
        SndEmit_SetEnabled_0_0012F6E0(1);
        SndCh_ResumePaused_1_0012C260();
    }
    if (p->state == 0) {
        Ui_SetScrollSpeed_0_00180F50(90.0f);
        D_002021D8 = *(s16 *)(b + 4);
        D_002021DC = *(s16 *)(b + 6);
    }
    D_002021C0 = 0;
    if (p->state == 0x16) {
        D_002021C0 = 1;
        if (p->xF) {
            SndEmit_StopAllA_1_0012F640();
            SndEmit_SetEnabled_0_0012F6E0(0);
            SndCh_PauseAll_1_0012C2C0();
            SndCh_StopAllUnlooped_1_0012C210();
        }
        switch (p->xF) {
        case 0x1F:
            p->x8 = p->xF;
            p->xF = 0;
            D_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x2BD, p->xE);
            break;
        case 0x28:
            p->x8 = p->xF;
            p->xF = 0;
            D_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0xA:
            p->x8 = p->xF;
            p->xF = 0;
            D_002021C0 = 0;
            LoadMenu_SetFromTitle_0_00193850(0);
            MenuStack_Push_1_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x2BC, p->xE);
            break;
        case 0x14:
            p->x8 = p->xF;
            p->xF = 0;
            D_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x64, p->xE);
            break;
        case 0x80:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            D_004A3320[0] = 5;
            p->x8 = 0x22;
            MenuStack_Push_1_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x2BD, p->xE);
            break;
        case 0x81:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            D_004A3320[0] = 6;
            p->x8 = 0x22;
            MenuStack_Push_1_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x2BD, p->xE);
            break;
        case 0x29:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x29;
            MenuStack_Push_1_00189ED0(1);
            p->x4 = 0;
            p->state = 0x1A;
            break;
        case 0x13:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x13;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x11:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x11;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x25:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x25;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x24:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x24;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        }
    }
}
