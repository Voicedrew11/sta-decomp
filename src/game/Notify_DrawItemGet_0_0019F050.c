#include "m2c.h"
typedef union { u32 w; u8 b[4]; } C;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x31]; u8 x3D; u8 pad3E[0x52]; } E;
void Text_Draw_2_001875C0(s8 *, s32, u32, f32, f32, f32);
f32 Msg_GetAlpha_0_0018B110(void);
s8 *Msg_GetText_2_00195B10(s32);
s8 *DbItem_Find_1_0019D510(u16);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
E *Item_GetTable_1_001AFC90(void);
u8 *Inventory_GetEntry_1_001CC3F0(s16);
extern u16 D_004A3310[];
extern s8 D_001FD698[];

void Notify_DrawItemGet_0_0019F050(void) {
    C c;
    s8 buf[0x100] = {0};
    s32 id;
    s16 v;
    E *e;
    u8 *q;
    s16 r;

    c.w = 0x80808080;
    c.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(Msg_GetText_2_00195B10(0x92), 1, *(u32 *)&c, 320.0f, 150.0f, 1.1f);
    Text_Draw_2_001875C0(DbItem_Find_1_0019D510(D_004A3310[0]), 1, *(u32 *)&c, 320.0f, 180.0f, 1.1f);
    sprintf(buf, Msg_GetText_2_00195B10(0x9E));
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 250.0f, 210.0f, 1.0f);
    id = D_004A3310[0];
    v = 0;
    e = Item_GetTable_1_001AFC90();
    q = Inventory_GetEntry_1_001CC3F0(id);
    if (id == -1) {
        r = -1;
    } else {
        switch (e[id].xA) {
        case 1:
            v = e[id].x3D;
            break;
        case 2:
            v = e[id].x3D;
            break;
        }
        if (q[0] <= 0) {
            r = (100 - q[0]) * (v / 5) * 2;
        } else {
            r = (100 - q[0]) * (v / 5);
        }
    }
    sprintf(buf, D_001FD698, r);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 340.0f, 210.0f, 1.0f);
    strcpy(buf, Msg_GetText_2_00195B10(0x9D));
    Text_Draw_2_001875C0(buf, 1, *(u32 *)&c, 320.0f, 240.0f, 1.0f);
}
