#include "m2c.h"
typedef union { u32 w; u8 b[4]; } C;
f32 Msg_GetAlpha_0_0018B110(void);
s8 *DbItem_Find_1_0019D510(s32);
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, u32);
s32 Item_GetTable_1_001AFC90(void);
u8 *Inventory_GetSlot_1_001A97D0(s16);
u8 *Inventory_GetEntry_1_001CC3F0(s16);
void sprintf(s8 *, s8 *, s32);
void strcpy(s8 *, s32);
s32 Msg_GetText_2_00195B10(s32);
extern s8 D_001FD6A8[];
extern u16 D_004A3310[];

void Notify_DrawGold_0_0019F890(void) {
    C col;
    s8 buf[0x100];
    s32 id;
    u8 *base;
    s16 v;

    col.w = 0x80808080;
    col.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(320.0f, 160.0f, 1.1f, DbItem_Find_1_0019D510(D_004A3310[0]), 1, col.w);
    id = D_004A3310[0];
    base = (u8 *)Item_GetTable_1_001AFC90();
    if (Inventory_GetSlot_1_001A97D0(id)[5] == 2) {
        v = 5;
    } else if ((s32)*Inventory_GetEntry_1_001CC3F0(id) <= 0) {
        v = 1;
    } else {
        v = (base + id * 0x90)[7];
    }
    sprintf(buf, D_001FD6A8, v);
    Text_Draw_2_001875C0(320.0f, 190.0f, 1.0f, buf, 1, col.w);
    strcpy(buf, Msg_GetText_2_00195B10(0x9C));
    Text_Draw_2_001875C0(320.0f, 220.0f, 1.0f, buf, 1, col.w);
}
