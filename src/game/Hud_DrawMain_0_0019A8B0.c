#include "common.h"

s32 *MenuLayout_Get_1_00189050(s32 i);
void *MenuLayout_GetSub_1_00189020(s32 i);
void Msg_Draw_0_0018ACA0(void);
void Ui_BeginSprites_1_00181420(void);
void Hud_DrawStatus_1_0019A920(s32 a, void *b);
void Menu_DrawBackground_0_00187B20(s32 a);

void Hud_DrawMain_0_0019A8B0(void)
{
    s32 a = *MenuLayout_Get_1_00189050(1);
    void *b = MenuLayout_GetSub_1_00189020(1);
    Msg_Draw_0_0018ACA0();
    Ui_BeginSprites_1_00181420();
    Hud_DrawStatus_1_0019A920(a, b);
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
}
