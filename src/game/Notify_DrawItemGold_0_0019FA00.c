#include "m2c.h"
typedef union { u32 w; u8 b[4]; } C;
typedef struct { u8 pad[6]; u8 x6; u8 pad7[0x89]; } E;
typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; u8 x4; u8 x5; } Q;
void Text_Draw_2_001875C0(s8 *, s32, u32, f32, f32, f32);
f32 Msg_GetAlpha_0_0018B110(void);
s8 *Msg_GetText_2_00195B10(s32);
s8 *DbItem_Find_1_0019D510(u16);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
E *Item_GetTable_1_001AFC90(void);
Q *Inventory_GetSlot_1_001A97D0(s16);
Q *Inventory_GetEntry_1_001CC3F0(s16);
void Ui_DrawGauge_0_00182EF0(s32, s32, s32, s32, f32, f32, f32);
extern u16 D_004A3310[];
extern s16 D_004A3312[];
extern s8 D_001FD6A0[];
extern s8 D_001FD6A8[];

void Notify_DrawItemGold_0_0019FA00(void) {
    C c;
    s8 buf[0x100];
    s32 id;
    E *e;
    s16 v;

    c.w = 0x80808080;
    c.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(DbItem_Find_1_0019D510(D_004A3310[0]), 1, *(u32 *)&c, 330.0f, 140.0f, 1.1f);
    sprintf(buf, Msg_GetText_2_00195B10(0x96));
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 250.0f, 170.0f, 1.0f);
    sprintf(buf, D_001FD6A0, (s16)Inventory_GetSlot_1_001A97D0(D_004A3310[0])->x2);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 330.0f, 170.0f, 1.0f);
    sprintf(buf, Msg_GetText_2_00195B10(0x98));
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 250.0f, 200.0f, 1.0f);
    sprintf(buf, D_001FD6A0, Inventory_GetEntry_1_001CC3F0(D_004A3310[0])->x2);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 330.0f, 200.0f, 1.0f);
    sprintf(buf, Msg_GetText_2_00195B10(0x97));
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 220.0f, 230.0f, 1.0f);
    sprintf(buf, D_001FD6A0, D_004A3312[0]);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 300.0f, 230.0f, 1.0f);
    id = D_004A3310[0];
    e = Item_GetTable_1_001AFC90();
    if (Inventory_GetSlot_1_001A97D0(id)->x5 == 2) {
        v = 5;
    } else {
        v = e[id].x6;
    }
    sprintf(buf, D_001FD6A8, D_004A3312[0] * v);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 355.0f, 230.0f, 1.0f);
    Ui_DrawGauge_0_00182EF0(0xB4, 0xE6, 0x1B8, 0xE6, 0.0f, 0.0f, Msg_GetAlpha_0_0018B110());
    strcpy(buf, Msg_GetText_2_00195B10(0x9B));
    Text_Draw_2_001875C0(buf, 1, *(u32 *)&c, 320.0f, 260.0f, 1.0f);
}
