#include "m2c.h"
typedef struct { u8 b[256]; } Buf;
typedef union { s32 w; u8 b[4]; } Col;
typedef struct { u8 pad[2]; u8 x2; } Ent;
typedef struct { u8 pad[4]; u8 x4; } Ent4;
f32 Msg_GetAlpha_0_0018B110(void);
s8 *DbItem_Find_1_0019D510(s32);
void Text_Draw_2_001875C0(s8 *, s32, s32, f32, f32, f32);
s8 *Msg_GetText_2_00195B10(s32);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
Ent *Inventory_GetEntry_1_001CC3F0(s32);
Ent4 *Inventory_GetSlot_1_001A97D0(s32);
void Ui_DrawGauge_0_00182EF0(s32, s32, s32, s32, f32, f32, f32);
extern s8 D_001FD6A0[];
extern s16 D_004A3310[];
extern s16 D_004A3312[];

void Notify_DrawItemCount_0_0019F410(void) {
    Buf buf = {0};
    Col col;

    col.w = 0x80808080;
    col.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(DbItem_Find_1_0019D510((u16)D_004A3310[0]), 1, col.w, 320.0f, 150.0f, 1.1f);
    sprintf((s8 *)&buf, Msg_GetText_2_00195B10(0x9A));
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 250.0f, 180.0f, 1.0f);
    sprintf((s8 *)&buf, D_001FD6A0, Inventory_GetSlot_1_001A97D0(D_004A3310[0])->x4);
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 330.0f, 180.0f, 1.0f);
    sprintf((s8 *)&buf, Msg_GetText_2_00195B10(0x98));
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 250.0f, 210.0f, 1.0f);
    sprintf((s8 *)&buf, D_001FD6A0, Inventory_GetEntry_1_001CC3F0(D_004A3310[0])->x2);
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 330.0f, 210.0f, 1.0f);
    sprintf((s8 *)&buf, Msg_GetText_2_00195B10(0x99));
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 250.0f, 240.0f, 1.0f);
    sprintf((s8 *)&buf, D_001FD6A0, D_004A3312[0]);
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 330.0f, 240.0f, 1.0f);
    Ui_DrawGauge_0_00182EF0(200, 240, 400, 240, 0.0f, 0.0f, Msg_GetAlpha_0_0018B110());
    strcpy((s8 *)&buf, Msg_GetText_2_00195B10(0x9B));
    Text_Draw_2_001875C0((s8 *)&buf, 1, col.w, 320.0f, 270.0f, 1.0f);
}
