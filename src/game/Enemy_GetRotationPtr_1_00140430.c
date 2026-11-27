#include "common.h"
s32 Enemy_GetRotationPtr_1_00140430(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198) + 0x20;
}
