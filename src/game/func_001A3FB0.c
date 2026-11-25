#include "common.h"
extern s32 D_004A4394[];
extern u8 D_004A43A2[];

void func_001A3FB0(void) {
    if ((*D_004A4394) == 2) {
        if ((*D_004A43A2) == 0xD) {
            goto block_3;
        }
    } else {
block_3:
        func_0018A310(4);
    }
    func_0017F5C0();
    func_00187B20(0);
}
