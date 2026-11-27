#include "m2c.h"
typedef struct { s32 idx; u8 pad[0x3C]; } Elem;
typedef struct { u32 n; Elem *e; } List;
typedef struct { u8 pad[0x34]; List *list; } Ctx;
typedef struct { u8 p:4; u8 v:1; } BF4;
typedef struct { s32 type; u8 pad[0x10]; BF4 x14; } Arg;
typedef union { s32 w; u8 b[4]; } Col;
Ctx *MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(Elem *, s32, void (*)(), s32);
void GameOverProc_DrawText_0_0019EA60();
void Menu_DrawBackground_0_00187B20(s32);
void Ui_BeginSprites_1_00181420(void);
extern s32 D_00202210;
extern s32 D_00202214;
extern s32 D_00202218;

void GameOver_DrawFrame_0_0019E8B0(Arg *arg0) {
    Col col;
    u32 i;
    List *list;
    s32 base;

    list = MenuLayout_Get_1_00189050(0)->list;
    base = MenuLayout_GetSub_1_00189020(0);
    if (arg0->type != 0x1C && arg0->type != 0x1E && arg0->type != 0x1F) {
        switch (D_00202210) {
        case 0:
            arg0->x14.v = 1;
            D_00202214 += 2;
            if (D_00202214 > 0x80) {
                D_00202214 = 0x80;
                D_00202210 += 1;
            }
            break;
        case 1:
            D_00202218 += 4;
            if (D_00202218 > 0x80) {
                D_00202218 = 0x80;
                D_00202210 += 1;
            }
            break;
        case 2:
            break;
        }
    } else {
        D_00202218 -= 0x10;
        if (D_00202218 < 0) {
            D_00202218 = 0;
        }
    }
    col.w = 0x80505050;
    col.b[3] = D_00202218;
    for (i = 0; i < list->n; i++) {
        Ui_DrawList_1_001829B0(&list->e[i], base + list->e[i].idx * 8, GameOverProc_DrawText_0_0019EA60, col.w);
    }
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
}
