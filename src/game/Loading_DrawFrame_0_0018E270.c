#include "common.h"

typedef struct { s32 idx; char p4[0x3C]; } E;
typedef struct { u32 n; E *e; } L;
typedef struct { L *l[13]; } G;
G *MenuLayout_Get_1_00189050(s32 i);
u8 *MenuLayout_GetSub_1_00189020(s32 i);
void Ui_DrawList_1_001829B0(E *e, u8 *p, void (*f)(void), s32 d);
void Loading_DrawText_2_0018E320(void);
void Menu_DrawBackground_0_00187B20(s32 a);
void Ui_BeginSprites_1_00181420(void);

void Loading_DrawFrame_0_0018E270(void)
{
    u32 i;
    L *l;
    u8 *b;
    l = MenuLayout_Get_1_00189050(0)->l[12];
    b = MenuLayout_GetSub_1_00189020(0);
    for (i = 0; i < l->n; i++)
        Ui_DrawList_1_001829B0(&l->e[i], b + l->e[i].idx * 8, Loading_DrawText_2_0018E320, 0);
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
}
