#include "m2c.h"
s32 func_00118CB0(s32, s32);
s32 func_00118B78(s32, s32, s32 *);
extern s32 D_004B6418[][4];

s32 func_001D3BF0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, u32 st) {
    s32 v;

    switch (st) {
    case 0:
    case 2:
    case 4:
        if (func_00118CB0(a0, a1) != 0) {
            if (st == 4) {
                return -100;
            }
            st += 2;
        } else {
            st += 1;
        }
        break;
    case 1:
    case 3:
        if (func_00118B78(1, 0, &v) != 0) {
            if (v != 0) {
                return v;
            }
            st += 1;
        }
        break;
    case 5:
        if (func_00118B78(1, 0, &v) != 0) {
            D_004B6418[a0][a1] = v;
            return v;
        }
        break;
    }
    return st;
}
