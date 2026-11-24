#include "m2c.h"
extern s8 *D_002022E4;

s32 func_001C9B60(void) {
    s32 temp_v0;

    if (D_002022E4 == NULL) {
        return 0;
    }
    temp_v0 = M2C_FIELD(D_002022E4, s32 *, 0x518);
    if (temp_v0 == 0) {
        return 0;
    }
    return temp_v0 + 0x180;
}
