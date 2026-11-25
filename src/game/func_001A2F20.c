#include "m2c.h"
s32 func_001CCD90(s32);
void func_001833E0(s16, s32);

void func_001A2F20(u32 a0) {
    s32 n = 10;
    s32 i;

    switch (a0) {
    case 1:
    case 3:
    case 4:
        n = 10;
        break;
    case 2:
    case 5:
        n = 9;
        break;
    case 6:
        n = 7;
        break;
    }
    for (i = 0; i < n; i++) {
        func_001833E0(func_001CCD90(i), i);
    }
    for (; n < 10; n++) {
        func_001833E0(-1, n);
    }
}
