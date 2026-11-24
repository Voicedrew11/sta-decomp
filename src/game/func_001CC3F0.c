#include "m2c.h"

s32 func_001CC3F0(s32 arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = func_001C9BA0();
    temp_v1 = (s16) arg0;
    if ((temp_v1 >= 0) && (temp_v1 < 0x400)) {
        return temp_v0 + (temp_v1 * 4) + 0xA0;
    }
    return 0;
}
