#include "common.h"
extern s32 D_001FE730[];
extern s32 D_00201E44;
extern s32 D_00201E48;
extern s32 D_00202334;
extern s16 D_0020233C;
extern s32 D_00202340;
extern s8 D_00202348;
extern s16 D_00202350;
extern s16 D_00202352;
extern s16 D_00202354;
extern s16 D_00202356;
void func_00130590(s32 *, s32, s32);

void func_001DD650(s32 *arg0) {
    switch (*arg0) {
    case 25:
        D_00202340 = 1;
        D_00201E44 = 0xC3000000;
        D_00201E48 = 0xC3000000;
        D_00202348 = 5;
        D_00202334 = 0;
        D_0020233C = 0;
        D_00202356 = 0;
        D_00202354 = 0;
        D_00202352 = 0;
        D_00202350 = 0;
        func_00130590(D_001FE730, 0, 1);
        break;
    case 27:
    case 0:
    case 22:
    case 26:
    case 28:
    case 30:
        break;
    }
}

