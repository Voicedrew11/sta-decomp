#include "common.h"
u8 *func_001A97D0(s16);
extern s32 D_004A3330[];
void func_001A2EA0(void) {
    s32 i;
    s32 *p = D_004A3330;
    for (i = 0; i < 0x400; i++, p++) {
        *p = 0;
        if (func_001A97D0(i)[5] == 3) {
            func_001A97D0(i)[5] = 1;
        }
    }
}
