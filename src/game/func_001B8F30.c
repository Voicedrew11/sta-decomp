#include "m2c.h"

s32 func_001B8F30(s8 *arg0, s8 *arg1) {
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return 0;
    }
    return M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x170) + (M2C_FIELD(arg1, u16 *, 0x18) << 6)), u8 *, 0x13) & 7;
}
