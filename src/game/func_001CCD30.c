#include "m2c.h"
s8 *func_001C9BA0();

s32 func_001CCD30(s32 arg0) {
    s8 *v = func_001C9BA0();
    s16 i;
    if (arg0 >= 0 && arg0 < 10) {
        i = ((s16 *)(v + 0x80))[arg0];
        if (i != -1) {
            return (s32)(v + i * 4 + 0xA0);
        }
    }
    return 0;
}

s16 func_001CCD90(s32 arg0) {
    s8 *v = func_001C9BA0();
    if (arg0 >= 0 && arg0 < 10) {
        return ((s16 *)(v + 0x80))[arg0];
    }
    return -1;
}
