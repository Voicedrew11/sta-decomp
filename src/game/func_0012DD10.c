#include "common.h"
extern s32 D_0022F050[];
extern s32 D_0022EC44[];
extern s16 D_0022EC48[];
extern s32 D_0022EC18[];
extern Flags8 D_0022EC41[];
extern s8 D_00201ED5;
void func_001D9EE0(s32);

void func_0012DD10(s32 a0) {
    D_00201ED5 = 0;
    func_001D9EE0(1);
    if (D_0022EC41[0].f.b1) {
        D_0022F050[0] = 0;
        D_0022EC44[0] = 1;
        D_0022EC41[0].f.b1 = 0;
    }
    D_0022EC48[0] = 1;
    D_0022EC41[0].f.b0 = 1;
    D_0022EC41[0].f.b2 = 0;
    D_0022EC18[0] = a0 / 10;
}
