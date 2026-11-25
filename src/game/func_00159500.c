#include "common.h"

extern struct { unsigned char : 6; unsigned char f : 1; char pad[15]; } D_002F2078;
extern s32 D_002F2070[];
extern s32 D_002F1AE0[];
void func_00157FE0(s32 a);

s32 *func_00159500(s32 on)
{
    s32 v = on != 0;
    if (v && !D_002F2078.f) {
        func_00157FE0(0);
        func_00157FE0(1);
        D_002F2070[0] = 0;
    }
    D_002F2078.f = v;
    return D_002F1AE0;
}
