#include "common.h"
extern s16 D_001F38F0[];
extern s16 D_001F38F2[];
extern s16 D_001F39EE[];

s16 func_001DC0F0(s32 a) {
    s32 m = a & 0x1FF;
    s32 i = m >> 2;
    s32 w = 4 - m % 4;
    s16 b;
    switch (a / 512) {
    case 0:
        if (i < 0x7F) {
            b = D_001F38F2[i];
            return b + w * (D_001F38F0[i] - b) / 4;
        }
        return D_001F39EE[0];
    case 1:
        if (i > 0) {
            b = D_001F38F0[0x7F - i];
            return b + w * (D_001F38F0[0x80 - i] - b) / 4;
        }
        return D_001F39EE[0];
    case 2:
        if (i < 0x7F) {
            b = D_001F38F2[i];
            return -(b + w * (D_001F38F0[i] - b) / 4);
        }
        return -D_001F39EE[0];
    case 3:
        if (i > 0) {
            b = D_001F38F0[0x7F - i];
            return -(b + w * (D_001F38F0[0x80 - i] - b) / 4);
        }
        return -D_001F39EE[0];
    }
    return 0;
}
