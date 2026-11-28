#include "common.h"
typedef struct { s32 idx; u8 pad4[0x3C]; } Item_Credits_DrawFrame_0_001DC900;
typedef struct { u32 n; Item_Credits_DrawFrame_0_001DC900 *items; } List_Credits_DrawFrame_0_001DC900;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9[5];
    u8 xE;
    u8 padF[5];
    Flags8 f14;
} O;
typedef struct { s32 idx; u8 pad[0x3C]; } Item_Credits_DrawBg_0_001DCE70;
typedef struct { u32 n; Item_Credits_DrawBg_0_001DCE70 *items; } List_Credits_DrawBg_0_001DCE70;
extern s16 D_00201E40;
extern f32 D_00202334;
extern s16 D_0020233C;
extern s16 D_00202350;
extern s16 D_00202352;
extern s16 D_00202354;
extern s16 D_00202356;
extern f32 D_00202338;
extern s32 D_00202340;
extern u8 D_00202348;
extern f32 D_00201E44;
extern f32 D_00201E48;
void Credits_DrawFrame_0_001DC900(void);
void Credits_Update_0_001DCC30(O *o);
void Credits_DrawBg_0_001DCE70(void);
List_Credits_DrawFrame_0_001DC900** MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(void *, s32, void (*)(), s32);
void TitleProc_DrawPushStart_0_001DD510();
void Strm_Stop_2_00130440(void);
void Strm_SetFadeStep_1_001304B0(s32);
void Snd_PlaySe_3_00131600(s32, u8);
void Credits_HandleEvent_0_001DD650(O *);
void CreditsProc_DrawText_0_001DCF80();
void Menu_DrawBackground_0_00187B20(s32);

/* Credits_DrawFrame_0_001DC900 */
#define Ui_DrawList_1_001829B0 Ui_DrawList_1_001829B0__as_Credits_DrawFrame_0_001DC900
void Ui_DrawList_1_001829B0__as_Credits_DrawFrame_0_001DC900(Item_Credits_DrawFrame_0_001DC900 *, s32, void (*)(), s32);

void Credits_DrawFrame_0_001DC900(void) {
    u32 i;
    List_Credits_DrawFrame_0_001DC900 *l;
    s32 base;

    l = *MenuLayout_Get_1_00189050(3);
    base = MenuLayout_GetSub_1_00189020(3);
    if (D_00202334 > 45.0f && D_00202334 < 75.0f) {
        D_00202350 = 127.0f * (D_00202334 - 45.0f) / 30.0f;
    }
    if (D_00202334 > 30.0f && D_00202334 < 60.0f) {
        D_00202352 = 127.0f * (D_00202334 - 30.0f) / 30.0f;
    }
    if (D_00202334 > 75.0f && D_00202334 < 105.0f) {
        D_00202354 = 127.0f * (D_00202334 - 75.0f) / 30.0f;
    }
    if (D_00202334 > 90.0f && D_00202334 < 120.0f) {
        D_00202356 = 127.0f * (D_00202334 - 90.0f) / 30.0f;
    }
    if (D_00202334 < 30.0f) {
        D_0020233C = 127.0f * D_00202334 / 30.0f;
    } else if (D_00202334 <= 60.0f) {
        D_0020233C += D_00201E40;
        if (D_0020233C <= 0) {
            D_0020233C = 0;
            D_00201E40 = 1;
        }
        if (D_0020233C >= 0x7F) {
            D_0020233C = 0x7F;
            D_00201E40 = -1;
        }
    } else if (D_00202334 < 1800.0f) {
        D_0020233C += D_00201E40;
        if (D_0020233C <= 0) {
            D_0020233C = 0;
            D_00201E40 = 1;
        }
        if (D_0020233C >= 0x7F) {
            D_0020233C = 0x7F;
            D_00201E40 = -1;
        }
    } else {
        D_0020233C += D_00201E40;
        if (D_0020233C <= 0) {
            D_0020233C = 0;
        }
        if (D_0020233C >= 0x7F) {
            D_0020233C = 0x7F;
        }
    }
    for (i = 0; i < l->n; i++) {
        Ui_DrawList_1_001829B0(&l->items[i], base + l->items[i].idx * 8, TitleProc_DrawPushStart_0_001DD510, 0);
    }
}
#undef Ui_DrawList_1_001829B0

/* Credits_Update_0_001DCC30 */
void Credits_Update_0_001DCC30(O *o) {
    s16 v;

    Credits_HandleEvent_0_001DD650(o);
    if (o->x0 != 0x16) return;
    if (D_00202348 != 5) {
        D_00202356 = (127.0f * (15.0f - (D_00202334 - D_00202338))) / 15.0f;
        if (!(D_00202334 < 15.0f + D_00202338)) {
            o->x8 = D_00202348;
            o->x4 = 0;
            o->x0 = 0x1A;
        }
    } else {
        if (!(D_00202334 <= 100.0f) && (o->x4 & 0x6008)) {
            Snd_PlaySe_3_00131600(0x69, o->xE);
            D_00202348 = 6;
            D_00202338 = D_00202334;
            o->x8 = 6;
            o->f14.f.b5 = 0;
            D_00202340 = 0;
            o->x4 = 0;
            o->x0 = 0x1F;
            return;
        }
        if (o->x4 & 0x6008) {
            Snd_PlaySe_3_00131600(0x69, o->xE);
            D_00202348 = 6;
            D_00202338 = D_00202334;
            o->x8 = 6;
            o->f14.f.b5 = 1;
            D_00202340 = 0;
            o->x4 = 0;
            o->x0 = 0x1F;
            return;
        }
        if (!(D_00202334 < 1800.0f)) {
            Strm_SetFadeStep_1_001304B0(-0x444);
            D_00201E40 = -2;
            if (!(D_00202334 < 1830.0f)) {
                o->x8 = 4;
                o->x4 = 0;
                o->x0 = 0x1E;
                Strm_Stop_2_00130440();
            } else {
                v = (127.0f * (1830.0f - D_00202334)) / 30.0f;
                D_00202356 = v;
                D_00202354 = v;
                D_00202352 = v;
                D_00202350 = v;
            }
        }
    }
    D_00202334 += 1.0f;
}

/* Credits_DrawBg_0_001DCE70 */
#define MenuLayout_Get_1_00189050 MenuLayout_Get_1_00189050__as_Credits_DrawBg_0_001DCE70
List_Credits_DrawBg_0_001DCE70 **MenuLayout_Get_1_00189050__as_Credits_DrawBg_0_001DCE70(s32);
#define Ui_DrawList_1_001829B0 Ui_DrawList_1_001829B0__as_Credits_DrawBg_0_001DCE70
void Ui_DrawList_1_001829B0__as_Credits_DrawBg_0_001DCE70(Item_Credits_DrawBg_0_001DCE70 *, s32, void (*)(), s32);

void Credits_DrawBg_0_001DCE70(void) {
    u32 i;
    List_Credits_DrawBg_0_001DCE70 *l;
    s32 base;
    Item_Credits_DrawBg_0_001DCE70 *it;

    l = MenuLayout_Get_1_00189050(3)[1];
    base = MenuLayout_GetSub_1_00189020(3);
    D_00201E48 += 4.0f;
    if (!(D_00201E48 <= 128.0f)) D_00201E48 = 128.0f;
    D_00201E44 += 4.0f;
    if (!(D_00201E44 <= 128.0f)) D_00201E44 = 128.0f;
    for (i = 0; i < l->n; i++) {
        it = &l->items[i];
        Ui_DrawList_1_001829B0(it, base + it->idx * 8, CreditsProc_DrawText_0_001DCF80, 0);
    }
    Menu_DrawBackground_0_00187B20(0);
}
#undef MenuLayout_Get_1_00189050
#undef Ui_DrawList_1_001829B0
