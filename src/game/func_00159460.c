#include "common.h"
void sceVu0CopyVector(s32 *, s32);           /* extern */
extern s16 D_002F1A48[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_002F1A50[0x4];

void func_00159460(s32 arg0) {
    (*D_002F1A48) = 2;
    sceVu0CopyVector(D_002F1A50, arg0);
}
