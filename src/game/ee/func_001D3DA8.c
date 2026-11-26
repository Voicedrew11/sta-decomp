#include "common.h"
extern s32 D_004B6450[];
void func_001D3DA8(s32 a) {
    if (a >= 0) D_004B6450[0] = 0;
    else if (a == -2) D_004B6450[0] = 3;
    else if (a == -3) D_004B6450[0] = 30;
    else if (a == -4) D_004B6450[0] = 100;
    else if (a == -5) D_004B6450[0] = 100;
    else if (a == -7) D_004B6450[0] = 100;
    else if (a < -10) D_004B6450[0] = 1;
    else D_004B6450[0] = 100;
}
