#include "common.h"
extern s32 D_002023E4;
extern s32 D_004BC39C[];
s32 func_001E82A0(s32 a) {
    volatile s32 t;
    if (a < 0 || a > 1) return 0;
    t = D_004BC39C[D_002023E4 * 256];
    if (t == 2) return 0;
    D_002023E4 = a;
    return 1;
}
