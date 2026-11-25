#include "common.h"
extern u8 D_0022EC17[];
extern s32 D_0022EC10[];
extern s32 D_002022B8;
extern s8 D_00201ED6;
extern Flags8 D_0022EC42[];
extern s32 D_0022F060[];
extern s32 D_0022EC44[];
extern s16 D_0022EC48[];
void func_001D9EE0(s32);

void func_0012DE00(void) {
    if (D_0022EC17[0] == 0 && D_002022B8 == D_0022EC10[0]) {
        D_00201ED6 = 0;
        func_001D9EE0(2);
        if (D_0022EC42[0].f.b1) {
            D_0022F060[0] = 0;
            D_0022EC44[0] = 1;
            D_0022EC42[0].f.b1 = 0;
        }
        D_0022EC48[0] = 1;
        D_0022EC17[0] = 1;
        D_0022EC42[0].f.b0 = 1;
        D_0022EC42[0].f.b2 = 0;
    }
}
