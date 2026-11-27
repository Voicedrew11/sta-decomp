#include "common.h"
extern void *D_002022E4;

s32 Player_GetRotationPtr_1_00145710(void) {
    return M2C_FIELD(D_002022E4, s32 *, 0x518) + 0x20;
}
