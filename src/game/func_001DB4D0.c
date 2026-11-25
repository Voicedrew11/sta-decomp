#include "common.h"
extern s32 D_00202330;

s32 func_001DB4D0(void) {
    if (func_001DB830() != 0) {
        D_00202330 = 0;
        return 0;
    }
    return 1;
}
