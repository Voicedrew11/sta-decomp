#include "common.h"
extern s32 AlignUpB_3_001E48E0(s32, s32);
extern s32 D_004BC2F0[];
s32 Credits_Alloc_1_001E4030(s32 arg0, s32 arg1) {
    s32 v = D_004BC2F0[5];
    if (arg1 != 0) {
        v = AlignUpB_3_001E48E0(v, 0x10);
    }
    D_004BC2F0[5] = v + arg0;
    return v;
}
