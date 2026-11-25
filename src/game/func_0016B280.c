#include "common.h"
extern s32 D_00201FF8;
extern s32 D_00201FFC;
extern s32 D_00202000;

void func_0016B280(void) {
    if (D_00201FF8 != 0) {
        func_001549D0();
        func_00155900();
        func_001548F0(0);
        D_00201FF8 = 0;
    }
    D_00201FFC = 0;
    D_00202000 = 0;
}
