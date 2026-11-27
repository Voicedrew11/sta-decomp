#include "common.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s32 idx; u8 pad[0x3B]; u8 a; } Elem;
typedef struct { u32 n; Elem *e; } List;
typedef struct { u8 pad[0x3C]; List *list; } Ctx;
Ctx *MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawSpriteRotated_1_00182080(f32, s32, s32 *, s32 *, Col *, s32);
void Ui_BeginSprites_1_00181420(void);
void Ui_DrawElemWrap_1_001829A0(Elem *, s32);
void Text_Draw_2_001875C0(s32, s32, Col, f32, f32, f32);
s32 Msg_GetText_2_00195B10(s32);
extern s32 D_001F27B0[];
extern s32 D_001F27C0[];
extern f32 D_00202414;
extern f32 D_00202418;

void Ending_Draw_0_001EDAD0(void) {
    Col c2;
    Col c1;
    u32 i;
    List *list;
    s32 base;

    c2.w = 0;
    c2.c.a = D_00202414;
    Ui_DrawSpriteRotated_1_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &c2, 0);
    Ui_BeginSprites_1_00181420();
    list = MenuLayout_Get_1_00189050(0)->list;
    base = MenuLayout_GetSub_1_00189020(0);
    for (i = 0; i < list->n; i++) {
        list->e[i].a = 1.95f * D_00202418;
        Ui_DrawElemWrap_1_001829A0(&list->e[i], base + list->e[i].idx * 8);
    }
    c1.w = 0x80808080;
    c1.c.a = D_00202418;
    Text_Draw_2_001875C0(Msg_GetText_2_00195B10(0x191), 1, c1, 320.0f, 200.0f, 1.1f);
}
