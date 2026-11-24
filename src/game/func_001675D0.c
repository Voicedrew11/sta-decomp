#include "m2c.h"

s32 func_001675D0(s8 *arg0) {
    s32 *temp_v0;

    if (arg0 == NULL) {
        return 0;
    }
    temp_v0 = M2C_FIELD(arg0, s32 **, 0x170);
    if (temp_v0 != NULL) {
        return *temp_v0;
    }
    return 0;
}
