#include "common.h"
s32 func_001E1EE0(s32 arg0, s32 arg1) {
    s32 t;
    arg0 &= 0xFF;
    if (arg1 == 0) return 0;
    t = arg0 == -6;
    if (arg0 != -1) {
        t += arg1 * 12;
    } else {
        t += arg1;
    }
    return t * 16;
}
