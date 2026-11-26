#include "m2c.h"
s32 func_001AA440(s32);
s8 *func_00195AA0(s32);
void sprintf(s8 *, s8 *, s8 *);
extern s8 D_001FD3B0[];
extern s8 D_001FD3F0[];
extern s8 D_004A1770[];

s8 *func_00198F30(s32 a) {
    s32 i;
    s32 found;
    s32 k;
    if (a < 0) {
        return D_001FD3B0;
    }
    found = 0;
    for (i = 0, k = a * 10; i < 10; i++, k++) {
        if (func_001AA440(k)) {
            found = 1;
        }
    }
    if (found) {
        sprintf(D_004A1770, D_001FD3F0, func_00195AA0(a));
        return D_004A1770;
    }
    return D_001FD3B0;
}
