#include "common.h"

extern s32 D_00201CD8;

void Ui_SetAlphaClamped_0_00182050(s32 v)
{
    if (v < 0)
        v = 0;
    if (v > 0x80)
        v = 0x80;
    D_00201CD8 = v;
}
