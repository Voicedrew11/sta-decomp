#include "common.h"
typedef struct { s32 x0; u8 pad[0x3B]; u8 b3F; } E;
typedef struct { u32 n; E *e; } L;
typedef struct { u8 pad[0x38]; L *l; } R;
typedef union { u32 w; s8 b[4]; } Col;
void Ui_DrawElemWrap_1_001829A0(E *, s8 *);
void Text_Draw_2_001875C0(s32, s32, u32, f32, f32, f32);
void Menu_DrawBackground_0_00187B20(s32);
s8 *MenuLayout_GetSub_1_00189020(s32);
R *MenuLayout_Get_1_00189050(s32);
s32 Msg_GetText_2_00195B10(s32);
void Ui_BeginSprites_1_00181420(void);
extern f32 D_00202408;

void Ending_DrawText_0_001ED850(void) {
    Col col;
    u32 i;
    L *l;
    s8 *base;


    col.w = 0x80808080;
    col.b[3] = (s32)D_00202408;
    l = MenuLayout_Get_1_00189050(0)->l;
    base = MenuLayout_GetSub_1_00189020(0);
    for (i = 0; i < l->n; i++) {
        l->e[i].b3F = 1.95f * (f32)(s32)D_00202408;
        Ui_DrawElemWrap_1_001829A0(&l->e[i], base + l->e[i].x0 * 8);
    }
    Text_Draw_2_001875C0(Msg_GetText_2_00195B10(0x190), 1, col.w, 320.0f, 120.0f, 1.0f);
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
}
