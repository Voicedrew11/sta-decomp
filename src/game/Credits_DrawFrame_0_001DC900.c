#include "common.h"
typedef struct { s32 idx; u8 pad4[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
List **MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(Item *, s32, void (*)(), s32);
void TitleProc_DrawPushStart_0_001DD510();
extern s16 D_00201E40;
extern f32 D_00202334;
extern s16 D_0020233C;
extern s16 D_00202350;
extern s16 D_00202352;
extern s16 D_00202354;
extern s16 D_00202356;

void Credits_DrawFrame_0_001DC900(void) {
    u32 i;
    List *l;
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

