#include "m2c.h"
extern s32 D_002F1990[];
extern s32 D_002F1994[];

s32 func_001543A0(s32 arg0) {
    s32 v = D_002F1994[0];
    if (v == 0) {
        v = D_002F1990[0];
        D_002F1994[0] = v;
    }
    D_002F1994[0] += arg0 * 0x10;
    return v;
}
