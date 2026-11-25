#include "m2c.h"
typedef struct { u8 p:6; u8 v:1; } B;
void func_00157FE0(M2C_UNK);
extern M2C_UNK D_002F1AE0[];
extern s32 D_002F2070[];
extern B D_002F2078[];

M2C_UNK *func_00159500(s32 arg0) {
    s32 temp_s0;

    temp_s0 = arg0 != 0;
    if (temp_s0 && !D_002F2078[0].v) {
        func_00157FE0(0);
        func_00157FE0(1);
        D_002F2070[0] = 0;
    }
    D_002F2078[0].v = temp_s0;
    return D_002F1AE0;
}
