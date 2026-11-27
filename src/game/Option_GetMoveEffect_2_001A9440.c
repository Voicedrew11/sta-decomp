#include "common.h"
extern void *D_00201E10;

u8 Option_GetMoveEffect_2_001A9440(void) {
    return M2C_FIELD(D_00201E10, u8 *, 8);
}
