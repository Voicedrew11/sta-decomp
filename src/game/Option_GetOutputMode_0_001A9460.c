#include "common.h"
extern void *D_00201E10;

u8 Option_GetOutputMode_0_001A9460(void) {
    return M2C_FIELD(D_00201E10, u8 *, 1);
}
