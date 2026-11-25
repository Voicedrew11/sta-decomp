#include "common.h"
s32 func_001B8F30(void *arg0, void *arg1) {
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return 0;
    }
    return M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x170) + (M2C_FIELD(arg1, u16 *, 0x18) << 6)), u8 *, 0x13) & 7;
}
