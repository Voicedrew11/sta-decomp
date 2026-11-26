#include "common.h"
extern s16 D_001F38F0[];
extern s16 D_001F38F2[];
extern s16 D_001F39EE[];

s16 func_001DBEA0(s32 a) {
    s32 m;
    s32 i;
    s32 f;
    s16 t;
    a += 0x200;
    if (a > 0x7FF) a -= 0x800;
    m = a & 0x1FF;
    i = m >> 2;
    f = 4 - m % 4;
    switch (a / 0x200) {
    case 0:
        if (i < 0x7F) {
            t = D_001F38F2[i];
            return t + f * (D_001F38F0[i] - t) / 4;
        }
        return *D_001F39EE;
    case 1:
        if (i > 0) {
            t = D_001F38F0[0x7F - i];
            return t + f * (D_001F38F0[0x80 - i] - t) / 4;
        }
        return *D_001F39EE;
    case 2:
        if (i < 0x7F) {
            t = D_001F38F2[i];
            return -(t + f * (D_001F38F0[i] - t) / 4);
        }
        return -*D_001F39EE;
    case 3:
        if (i > 0) {
            t = D_001F38F0[0x7F - i];
            return -(t + f * (D_001F38F0[0x80 - i] - t) / 4);
        }
        return -*D_001F39EE;
    }
    return 0;
}
