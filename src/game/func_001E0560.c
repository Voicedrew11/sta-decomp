#include "common.h"
extern s32 D_004BAC40[];
extern s32 D_004BAC44[];
extern s32 D_004BAC48[];

void func_001E0560(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*D_004BAC40) = arg0;
        (*D_004BAC44) = arg1;
        (*D_004BAC48) = -1;
    }
}
