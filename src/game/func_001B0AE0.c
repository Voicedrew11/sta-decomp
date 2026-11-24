#include "m2c.h"
extern M2C_UNK D_00201E80;

s32 *func_001B0AE0(s32 arg0) {
    if ((M2C_FIELD(&D_00201E80, s32 **, 8) != NULL) && (*M2C_FIELD(&D_00201E80, s32 **, 8) == arg0)) {
        return M2C_FIELD(&D_00201E80, s32 **, 8);
    }
    if ((M2C_FIELD(&D_00201E80, s32 **, 0xC) != NULL) && (*M2C_FIELD(&D_00201E80, s32 **, 0xC) == arg0)) {
        return M2C_FIELD(&D_00201E80, s32 **, 0xC);
    }
    return NULL;
}
