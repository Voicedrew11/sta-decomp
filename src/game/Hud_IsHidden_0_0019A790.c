#include "common.h"

extern s32 D_002021C0;
extern s32 D_002021CC;
s32 Menu_GetMode_1_0018A320(void);

s32 Hud_IsHidden_0_0019A790(void)
{
    s32 r = D_002021C0;
    if (r)
        D_002021CC = 0;
    if (D_002021CC)
        return Menu_GetMode_1_0018A320() == 0x12;
    return r;
}
