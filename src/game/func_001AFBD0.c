#include "common.h"
s32 func_001AFBD0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x64)) {
        return 0;
    }
    if ((arg0 >= 0x64) && (arg0 < 0x320)) {
        return 1;
    }
    if ((arg0 >= 0x320) && (arg0 < 0x400)) {
        return 2;
    }
    return -1;
}
