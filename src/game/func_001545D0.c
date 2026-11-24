#include "m2c.h"
extern s32 D_002F1990[];
extern s32 D_002F1994[];
extern s32 D_002F1998[];

void func_001545D0(void) {
    if (D_002F1994[0] == 0) {
        D_002F1994[0] = D_002F1990[0];
    }
    D_002F1998[0] = D_002F1994[0];
    D_002F1994[0] += 0x20;
}
