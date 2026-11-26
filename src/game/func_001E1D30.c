#include "common.h"
extern s32 D_004BC2D0[];
extern s32 D_004BC2D4[];
extern s32 D_004BC2D8[];

void func_001E1D30(s32 arg0, s32 arg1) {
    if ((*D_004BC2D4) != arg0) {
        if ((*D_004BC2D8) != 0) {
            if (arg1 != 0) {
                goto block_4;
            }
        } else {
block_4:
            (*D_004BC2D0) = arg0;
            (*D_004BC2D8) = arg1;
        }
    }
}
