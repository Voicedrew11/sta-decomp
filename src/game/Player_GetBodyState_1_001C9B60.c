#include "common.h"
extern void *D_002022E4;

s32 Player_GetBodyState_1_001C9B60(void) {
    s32 temp_2;

    if (D_002022E4 == NULL) {
        return 0;
    }
    temp_2 = M2C_FIELD(D_002022E4, s32 *, 0x518);
    if (temp_2 == 0) {
        return 0;
    }
    return temp_2 + 0x180;
}
