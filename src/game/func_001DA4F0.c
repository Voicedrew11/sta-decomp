#include "common.h"
extern s8 D_004BA782[][4];
s32 func_001DA4F0(s32 arg0) {
    if (!(0 > arg0) && arg0 < 0x40) {
        return ~D_004BA782[arg0][0] != 0;
    }
    return -1;
}
