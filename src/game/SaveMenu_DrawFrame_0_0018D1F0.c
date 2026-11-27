#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; u8 pad[3]; } E;
typedef struct { s32 sel; s32 x4; s32 x8; f32 xC; s32 x10; s32 x14; E e[2]; } M;
typedef struct { s32 idx; u8 pad4[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
extern M D_004A1050;
List **MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(Item *, s32, void (*)(), s32);
void SaveMenu_DrawSlot_1_0018D420();
void Ui_SetAlphaClamped_0_00182050(s32);
void Menu_DrawBackground_0_00187B20(s32);
void Ui_BeginSprites_1_00181420(void);

void SaveMenu_DrawFrame_0_0018D1F0(u8 *a0) {
    u32 i;
    List *l;
    s32 base;


    l = MenuLayout_Get_1_00189050(4)[0];
    base = MenuLayout_GetSub_1_00189020(4);
    if (*(s32 *)a0 == 0x19) {
        D_004A1050.e[0].b0 = 0;
        D_004A1050.e[1].b0 = 0;
    }
    if (a0[8] == 9) {
        D_004A1050.xC += 16.0f;
    } else {
        D_004A1050.xC -= 16.0f;
    }
    Ui_SetAlphaClamped_0_00182050(D_004A1050.xC);
    for (i = 0; i < l->n; i++) {
        Ui_DrawList_1_001829B0(&l->items[i], base + l->items[i].idx * 8, SaveMenu_DrawSlot_1_0018D420, D_004A1050.sel);
    }
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
    Ui_SetAlphaClamped_0_00182050(0x80);
}
