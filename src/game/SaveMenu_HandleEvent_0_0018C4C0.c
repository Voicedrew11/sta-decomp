#include "common.h"
#include "actor.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB[3];
    u8 xE;
} Obj18C8B0_SaveMenu_SelectSlot_0_0018C590;
typedef struct {
    u8 pad0[0x10];
    s32 arr[8];
} Buf18C590;
typedef struct {
    u8 pad0[4];
    s32 x4;
    u8 pad8[2];
    u8 xA;
    u8 padB[3];
    u8 xE;
} Obj18C8B0_SaveMenu_ConfirmOverwrite_0_0018C8B0;
typedef struct { u8 pad0[0xA]; u8 xA; } O;
typedef struct { s32 pad[3]; s32 xC; s32 arr[8]; } Buf;
typedef struct { s16 x0; s16 x2; s16 x4; s16 x6; u8 pad8[4]; s16 xC; u8 xE; u8 xF; } R;
typedef struct { u8 pad[0x20]; R r; } S1;
typedef struct { u8 pad[0x50]; R r[1]; } S0;
extern Flags8 D_004A1010[];
extern s32 D_004A0FF0[];
extern s32 D_004A1008[];
extern f32 D_0020211C;
extern s32 D_00202120[2];
extern u8 D_004A095F[][0xF0];
extern s32 D_004A0FC0[];
extern s32 D_004A0FF4[];
extern s32 D_004A0FFC[];
extern s32 D_004A1000[];
extern f32 D_004A100C[];
extern s32 D_004A0FF8[];
void SaveMenu_HandleEvent_0_0018C4C0(s32 *a);
void SaveMenu_SelectSlot_0_0018C590(Obj18C8B0_SaveMenu_SelectSlot_0_0018C590 *o);
void SaveMenu_ConfirmOverwrite_0_0018C8B0(Obj18C8B0_SaveMenu_ConfirmOverwrite_0_0018C8B0 *o);
void SaveMenu_Save_0_0018CA20(O *o);
s32 SaveSys_GetPort_1_001E8290(void);
s8* Save_GetSlotInfo_0_00188FF0(s32);
u8 MenuStack_Pop_1_00189EA0(void);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
void SaveSys_GetSlotCount_0_001E5E80(void *);
s32 SaveSys_IsCardReady_0_001E6110();
void Snd_PlaySe_3_00131600(s32, u8);
void MenuProc_BackOnCancel_0_0018D000();
S1* Menu_GetStateBuf_0_00189000(s32);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 SaveSys_StartWrite_0_001E6170(s32, void *, s32);
void SaveSys_Update_2_001E8500(void);
void SaveMenu_ConfirmLoad_0_0018D060();
void SaveMenu_Exit_0_0018D140();

/* SaveMenu_HandleEvent_0_0018C4C0 */
#define SaveMenu_SelectSlot_0_0018C590 SaveMenu_SelectSlot_0_0018C590__as_SaveMenu_HandleEvent_0_0018C4C0
void SaveMenu_SelectSlot_0_0018C590__as_SaveMenu_HandleEvent_0_0018C4C0(s32 *);

void SaveMenu_HandleEvent_0_0018C4C0(s32 *a) {
    switch (a[0]) {
    case 0x19:
        D_0020211C = 0.0f;
        D_004A0FF0[0] = D_00202120[SaveSys_GetPort_1_001E8290()];
        D_004A1010[0].f.b0 = 1;
        D_004A1008[0] = 0;
        D_0020211C = D_004A0FF0[0] + 1;
        break;
    case 0x16:
        if (D_004A1010[0].f.b0) {
            SaveMenu_SelectSlot_0_0018C590(a);
            a[1] = 0;
        }
        break;
    }
}
#undef SaveMenu_SelectSlot_0_0018C590

/* SaveMenu_SelectSlot_0_0018C590 */
#define SaveSys_GetSlotCount_0_001E5E80 SaveSys_GetSlotCount_0_001E5E80__as_SaveMenu_SelectSlot_0_0018C590
void SaveSys_GetSlotCount_0_001E5E80__as_SaveMenu_SelectSlot_0_0018C590(Buf18C590 *);
#define SaveMenu_ConfirmOverwrite_0_0018C8B0 SaveMenu_ConfirmOverwrite_0_0018C8B0__as_SaveMenu_SelectSlot_0_0018C590
void SaveMenu_ConfirmOverwrite_0_0018C8B0__as_SaveMenu_SelectSlot_0_0018C590();

void SaveMenu_SelectSlot_0_0018C590(Obj18C8B0_SaveMenu_SelectSlot_0_0018C590 *o) {
    Buf18C590 buf = {0};
    s32 i;
    s32 fl;

    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    D_004A1010[0].f.b1 = 1;
    fl = o->x4;
    if (fl & 0x10) {
        D_004A0FF0[0]--;
        Snd_PlaySe_3_00131600(0x66, o->xE);
        if (D_004A0FF0[0] < 0) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 1;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x40) {
        D_004A0FF0[0]++;
        Snd_PlaySe_3_00131600(0x66, o->xE);
        if (D_004A0FF0[0] > 6) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 3;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x2000) {
        SaveSys_GetSlotCount_0_001E5E80(&buf);
        i = D_004A0FF0[0];
        if (buf.arr[i] != 1 || D_004A095F[SaveSys_GetPort_1_001E8290()][i * 0x10] == 0 || Save_GetSlotInfo_0_00188FF0(0)[D_004A0FF0[0]] != 0) {
            Snd_PlaySe_3_00131600(0x6B, o->xE);
        } else {
            Snd_PlaySe_3_00131600(0x67, o->xE);
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x71, 3, SaveMenu_ConfirmOverwrite_0_0018C8B0, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x4000) {
        o->x8 = MenuStack_Pop_1_00189EA0();
        o->x4 = 0;
        o->x0 = 0x1A;
        Snd_PlaySe_3_00131600(0x69, o->xE);
    }
}
#undef SaveSys_GetSlotCount_0_001E5E80
#undef SaveMenu_ConfirmOverwrite_0_0018C8B0

/* SaveMenu_ConfirmOverwrite_0_0018C8B0 */
#define SaveMenu_Save_0_0018CA20 SaveMenu_Save_0_0018CA20__as_SaveMenu_ConfirmOverwrite_0_0018C8B0
void SaveMenu_Save_0_0018CA20__as_SaveMenu_ConfirmOverwrite_0_0018C8B0();

void SaveMenu_ConfirmOverwrite_0_0018C8B0(Obj18C8B0_SaveMenu_ConfirmOverwrite_0_0018C8B0 *o) {
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    if (o->x4 & 0x2000) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x6B, 0, SaveMenu_Save_0_0018CA20, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A0FF8[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
    if (o->x4 & 0x4000) {
        D_004A1010[0].f.b0 = 1;
        o->xA = 2;
        Snd_PlaySe_3_00131600(0x68, o->xE);
    }
}
#undef SaveMenu_Save_0_0018CA20

/* SaveMenu_Save_0_0018CA20 */
#define SaveSys_GetSlotCount_0_001E5E80 SaveSys_GetSlotCount_0_001E5E80__as_SaveMenu_Save_0_0018CA20
void SaveSys_GetSlotCount_0_001E5E80__as_SaveMenu_Save_0_0018CA20(Buf *);
static inline s32 diff(R *a, R *b) {
    if (a->x4 != b->x4 || a->x6 != b->x6 || a->x0 != b->x0 || a->x2 != b->x2 ||
        a->xE != b->xE || a->xC != b->xC || a->xF != b->xF) {
        return 1;
    }
    return 0;
}

void SaveMenu_Save_0_0018CA20(O *o) {
    Buf buf = {0};
    S1 *s1;
    S0 *s0;
    s32 st;

    SaveSys_GetPort_1_001E8290();
    s1 = Menu_GetStateBuf_0_00189000(0);
    s0 = (S0 *)Menu_GetStateBuf_0_00189000(1);
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    D_004A1010[0].f.b1 = 0;
    switch (D_004A0FF8[0]) {
    case 0:
        if (!SaveSys_StartRead_0_001E5F30(0, 0)) {
            D_004A0FF8[0]++;
        }
        break;
    case 1:
        SaveSys_GetResult_0_001E6080(&st);
        if (st == 0) {
            D_004A0FF8[0]++;
        }
        if (st == 1) {
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    case 2:
        SaveSys_GetSlotCount_0_001E5E80(&buf);
        switch (buf.arr[D_004A0FF0[0]]) {
        case 2:
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x6C, 2, SaveMenu_ConfirmLoad_0_0018D060, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A1010[0].f.b0 = 0;
            return;
        case 0:
            break;
        case 1:
            break;
        }
        if (buf.xC == 1) {
            if (!SaveSys_StartWrite_0_001E6170(-1, s0, 0xF0)) {
                D_004A0FF8[0]++;
            }
        } else {
            D_004A0FF8[0]++;
            D_004A0FF8[0]++;
        }
        break;
    case 3:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&st);
        } while (st == 2);
        if (st == 0) {
            D_004A0FF8[0]++;
        }
        if (st == 1) {
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    case 4:
        if (!SaveSys_StartWrite_0_001E6170(D_004A0FF0[0], s1, 0x7C20)) {
            D_004A0FF8[0]++;
        }
        break;
    case 5:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&st);
        } while (st == 2);
        if (st == 0) {
            if (diff(&s0->r[D_004A0FF0[0]], &s1->r)) {
                MenuProc_Set_1_0018B150(D_004A0FC0, 0x6C, 2, SaveMenu_ConfirmLoad_0_0018D060, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A0FC0);
                o->xA = 1;
                D_004A1010[0].f.b0 = 0;
            } else {
                MenuProc_Set_1_0018B150(D_004A0FC0, 0x6D, 2, SaveMenu_Exit_0_0018D140, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A0FC0);
                o->xA = 1;
            }
        }
        if (st == 1) {
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    }
}
#undef SaveSys_GetSlotCount_0_001E5E80
