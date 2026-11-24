#include "m2c.h"
extern s32 D_002022B0;

s32 func_001AFC40(s16 arg0) {
    s32 temp_a0;

    if (D_002022B0 != 0) {
        temp_a0 = (s16) arg0;
        if ((temp_a0 > 0) && (temp_a0 < 0x400)) {
            return D_002022B0 + (temp_a0 * 0x90);
        }
    }
    return 0;
}
