#include "common.h"
extern void *D_00201E10;

u8 Option_GetSeVolume_1_001A9480(void) {
    return M2C_FIELD(D_00201E10, u8 *, 4);
}
