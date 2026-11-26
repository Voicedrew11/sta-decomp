#include "m2c.h"
extern s32 D_004A18C0[0x400];
void *func_001AFC90(void);
s32 func_0019D510(s32);
s32 func_00187130(s32, s32);
void func_001803B0(s32 *, s32);

void func_0019A0D0(s32 arg0) {
    s32 i;

    for (i = 99; i >= 0; i--) {
        D_004A18C0[i] = 0;
    }
    for (i = 100; i < 0x400; i++) {
        func_001AFC90();
        D_004A18C0[i] = 0;
        if (func_0019D510(i) && func_00187130(i, arg0)) {
            D_004A18C0[i] = 1;
        }
    }
    func_001803B0(D_004A18C0, 0);
}
